#include <dirent.h>
#include "ch02.h"

/**
 * 读目录
 * @param path
 */
void open_dir(const string &path)
{
    struct stat statBuf{};
    DIR *dir = opendir(path.c_str());
    dirent *dip;
    // d_type 4为目录，8为文件
    while ((dip = readdir(dir)) != nullptr)
    {
        lstat(dip->d_name, &statBuf);
        printf("%s %d\n", dip->d_name, dip->d_type);
        if (dip->d_type == 8)
        {
            read_file_1(path + "/" + dip->d_name);
        }
    }
    closedir(dir);
}

/**
 * 读文件
 * @param filePath
 */
void read_file_1(const string &filePath)
{
    FILE *file_fd;
    int read_len, i;
    file_fd = fopen(filePath.c_str(), "rb");
    if (file_fd == nullptr)
    {
        perror("errno");
    }

    unsigned char data[20];

    while (true)
    {
        read_len = fread(data, 1, 16, file_fd);
        if (read_len == -1)
        {
            printf("File read error!\n");
            perror("errno");
            exit(0);
        } else if (read_len == 0)
        {
            printf("File read Over!\n");
            break;
        } else
        {
            printf("Read %d Byte From download.bin: ", read_len);
            for (i = 0; i < read_len; i++)
            {
                printf(" %02x", data[i]);
            }
            printf("\n");
        }
        usleep(20000);
    }
    fclose(file_fd);
}
