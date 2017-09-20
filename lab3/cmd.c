#include<stdio.h>
#include<stdlib.h>
int main()
{
    char cmd[100];
    while(1)
    {
        scanf("%s",cmd);
        if(!strcmp(cmd,"help"))
           printf("this is help\n");
        else if(!strcmp(cmd,"ls"))
           printf("this is ls\n");
        else if(!strcmp(cmd,"quit"))
           exit(0);
        else printf("this is not a cmd\n");

    }
}
