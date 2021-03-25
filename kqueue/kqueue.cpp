//
// Created by 刘时明 on 2020/11/24.
//
#include <sys/socket.h>
#include <sys/event.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstdio>
#include <cerrno>
#include <cstring>
#include <cstdlib>

#define exit_if(r, ...) if(r) {printf(__VA_ARGS__); printf("error no: %d error msg %s\n", errno, strerror(errno)); exit(1);}

const int kReadEvent = 1;
const int kWriteEvent = 2;

void setNonBlock(int fd)
{
    int flags = fcntl(fd, F_GETFL, 0);
    exit_if(flags < 0, "fcntl failed")
    int r = fcntl(fd, F_SETFL, flags | O_NONBLOCK);
    exit_if(r < 0, "fcntl failed")
}

void updateEvents(int efd, int fd, int events, bool modify)
{
    struct kevent ev[2];
    int n = 0;
    if (events & kReadEvent)
    {
        EV_SET(&ev[n++], fd, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, (void *) (intptr_t) fd);
    } else if (modify)
    {
        EV_SET(&ev[n++], fd, EVFILT_READ, EV_DELETE, 0, 0, (void *) (intptr_t) fd);
    }
    if (events & kWriteEvent)
    {
        EV_SET(&ev[n++], fd, EVFILT_WRITE, EV_ADD | EV_ENABLE, 0, 0, (void *) (intptr_t) fd);
    } else if (modify)
    {
        EV_SET(&ev[n++], fd, EVFILT_WRITE, EV_DELETE, 0, 0, (void *) (intptr_t) fd);
    }
    printf("%s fd %d events read %d write %d\n", modify ? "mod" : "add", fd, events & kReadEvent, events & kWriteEvent);
    int r = kevent(efd, ev, n, NULL, 0, NULL);
    exit_if(r, "kevent failed ");
}

void handleAccept(int efd, int fd)
{
    struct sockaddr_in r_addr;
    socklen_t rsz = sizeof(r_addr);
    int cfd = accept(fd, (struct sockaddr *) &r_addr, &rsz);
    exit_if(cfd < 0, "accept failed");
    sockaddr_in peer, local;
    socklen_t alen = sizeof(peer);
    int r = getpeername(cfd, (sockaddr *) &peer, &alen);
    exit_if(r < 0, "getpeername failed");
    printf("accept a connection from %s\n", inet_ntoa(r_addr.sin_addr));
    setNonBlock(cfd);
    updateEvents(efd, cfd, kReadEvent | kWriteEvent, false);
}

void handleRead(int efd, int fd)
{
    char buf[4096];
    int n;
    while ((n = ::read(fd, buf, sizeof buf)) > 0)
    {
        printf("read %d bytes\n", n);
        int r = ::write(fd, buf, n); //写出读取的数据
        //实际应用中，写出数据可能会返回EAGAIN，此时应当监听可写事件，当可写时再把数据写出
        exit_if(r <= 0, "write error");
    }
    if (n < 0 && (errno == EAGAIN || errno == EWOULDBLOCK))
        return;
    exit_if(n < 0, "read error"); //实际应用中，n<0应当检查各类错误，如EINTR
    printf("fd %d closed\n", fd);
    close(fd);
}

void handleWrite(int efd, int fd)
{
    //实际应用应当实现可写时写出数据，无数据可写才关闭可写事件
    updateEvents(efd, fd, kReadEvent, true);
}

void loop_once(int efd, int lfd, int wait_ms)
{
    struct timespec timeout{};
    timeout.tv_sec = wait_ms / 1000;
    timeout.tv_nsec = (wait_ms % 1000) * 1000 * 1000;
    const int kMaxEvents = 20;
    struct kevent activeEvs[kMaxEvents];
    int n = kevent(efd, nullptr, 0, activeEvs, kMaxEvents, &timeout);
    printf("epoll_wait return %d\n", n);
    for (int i = 0; i < n; i++)
    {
        int fd = (int) (intptr_t) activeEvs[i].udata;
        int events = activeEvs[i].filter;
        if (events == EVFILT_READ)
        {
            if (fd == lfd)
            {
                handleAccept(efd, fd);
            } else
            {
                handleRead(efd, fd);
            }
        } else if (events == EVFILT_WRITE)
        {
            handleWrite(efd, fd);
        } else
        {
            exit_if(1, "unknown event");
        }
    }
}

int main()
{
    short port = 8888;
    int epoll_fd = kqueue();
    exit_if(epoll_fd < 0, "epoll_create failed");
    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    exit_if(listen_fd < 0, "socket failed");
    struct sockaddr_in addr{};
    memset(&addr, 0, sizeof addr);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;
    int r = ::bind(listen_fd, (struct sockaddr *) &addr, sizeof(struct sockaddr));
    exit_if(r, "bind to 0.0.0.0:%d failed %d %s", port, errno, strerror(errno))
    r = listen(listen_fd, 20);
    exit_if(r, "listen failed %d %s", errno, strerror(errno))
    printf("fd %d listening at %d\n", listen_fd, port);
    setNonBlock(listen_fd);
    updateEvents(epoll_fd, listen_fd, kReadEvent, false);
    for (;;)
    {
        //实际应用应当注册信号处理函数，退出时清理资源
        loop_once(epoll_fd, listen_fd, 10000);
    }
    return 0;
}