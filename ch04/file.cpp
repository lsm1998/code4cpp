/**
* 作者：刘时明
* 时间：2020/11/22 0022
*/
#include <ntddk.h>

#define FILE_NAME L"\\?\\c:\\a.txt"
#define BUFFER_LEN 10

VOID DriverUnload(PDRIVER_OBJECT pDriverObject)
{

}

VOID CreateFileTest()
{
    NTSTATUS status = STATUS_SUCCESS;

    OBJECT_ATTRIBUTES ObjAttribute;
    IO_STATUS_BLOCK ioStatusBlock;

    UNICODE_STRING uniFile;

    HANDLE hFile = NULL;

    RtlInitUnicodeString(&uniFile, FILENAME);

    // 初始化一个对象属性
    InitializeObjectAttributes(&ObjAttribute,
                               &uniFile,
                               OBJ_CASE_INSENSITIVE,
                               NULL,
                               NULL);

    // 创建文件
    status = ZwCreateFile(&hFile,
                          GENERIC_READ | GENERIC_WRITE,
                          &ObjAttribute,
                          &ioStatusBlock,
                          0,
                          FILE_ATTRIBUTE_NORMAL,
                          FILE_SHARE_READ,
                          FILE_OPEN_IF,
                          FILE_SYNCHRONOUS_IO_NONALERT,
                          NULL,
                          0);

    if ( NT_SUCCESS(status) )
    {
        KdPrint(("File Create ok ! \r\n"));
    }
    else
    {
        KdPrint(("File Create faild ! \r\n"));
    }


    ZwClose(hFile);
}