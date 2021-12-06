#include <stdio.h>
#include <stdlib.h>

void ExitProgram();
void ErrorExit();

void ExitProgram()//Made by TaeMoo Kim
{
    printf("Program Has Successfully Exited\n");
    exit(0);
}

void ErrorExit()//Made by TaeMoo Kim
{
    printf("Program has Shutdown.\n");
    exit(1);
}

int main()
{
    int test;
    printf("10 -> standard exit function\n");
    printf("9 -> if occur Error, then use it\n");
    scanf("%d", &test);
    if(test==10)
        {
            ExitProgram();
            printf("Hello\n");
        }
    else if (test==9)
        {
            ErrorExit();
            printf("Hello\n");
        }
    else
        printf("Happy birthday!\n");
    return 0;
}
