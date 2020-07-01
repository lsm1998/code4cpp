#include "ch02.h"

void ch02()
{
    // read_file_2("/app/1.txt");

    // copy("/app/1.txt","/app/1-copy.txt");

    char *result = read_bytes("/app/1.txt");

    //printf("%p \n", result);
    //printf("%s \n", result);
    cout << (int)*(result) << endl;
    cout << (int)*(result+1) << endl;
}