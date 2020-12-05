//
// Created by 刘时明 on 2020/12/5.
//
#include <cstdio>
#include <dirent.h>

void show_dir(char *path)
{
    DIR *dp;
    struct dirent *dt;

    if ((dp = opendir(path)) == nullptr)
    {

    }
    while ((dt = readdir(dp)) != nullptr)
    {
        printf("%s \n", dt->d_name);
    }
    closedir(dp);
}
