#include <stdio.h>

char* uppercase(char *str);//Made by TaeMoo Kim
char* downcase(char *str);//Made by TaeMoo Kim

char* uppercase(char *str)//small -> big
{
    int i, j;
    char alphabet;
    for (i=0; i<=99; i++)
    {
        for (j=97; j<=122; j++)//small letter
        {
            alphabet=j;
            if (str[i]==alphabet)
            str[i]=j-32;
        }
        if (str[i]=='\0')
        break;
    }

    return str;
}

char* downcase(char *str)//big -> small
{
    int i, j;
    char alphabet;
    for (i=0; i<=99; i++)
    {
        for (j=65; j<=90; j++)//big letter
        {
            alphabet=j;
            if (str[i]==alphabet)
            str[i]=j+32;
        }
        if (str[i]=='\0')
        break;
    }

    return str;
}

int main()
{
    //supplies
    char input[100];

    //input
    printf("Input : ");
    scanf("%s", input);

    //use -> uppercase(str)
    printf("big output : %s\n", uppercase(input));
    printf("small output : %s\n", downcase(input));
}
