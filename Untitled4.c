#include <stdio.h>

struct book
{
    char name[10];
    char title[100];
    char books[100];
    int page;
}typedef book;

void main()
{
    book bk[10] = {0};
    int index = 0;
    int num;
    int del;
    char title[100];;
    int i;

    while(1)
    {
        printf("입력[1] 삭제[2] 수정[3] 출력[4] 종료[6]\n");
        printf("원하는 번호를 골라주세요 : ");
        scanf("%d", &num);
        if(num == 1)
        {
            for(index = 0; index < 10; index++)if(bk[index].page == 0)break;
            if(index == 10)
            {
                printf("더 이상 저장할 공간이 없습니다.\n\n");
                continue;
            }
            printf("저자를 입력해 주세요 : ");
            scanf("%s", bk[index].name);
            printf("제목을 입력해 주세요 : ");
            scanf("%s", bk[index].title);
            printf("출판사를 입력해 주세요 : ");
            scanf("%s", bk[index].books);
            printf("페이지를 입력해 주세요 : ");
            scanf("%d", &bk[index].page);
            if(bk[index].page < 1)
            {
                printf("잘못된 값을 입력하셨습니다.\n\n");
                for(i = 0; i < 10; i++)bk[index].name[i] = 0;
                for(i = 0; i < 100; i++)bk[index].title[i] = 0;
                for(i = 0; i < 100; i++)bk[index].books[i] = 0;
                bk[index].page = 0;
                continue;
            }
            printf("저장되었습니다.\n\n");
        }
        else if(num == 2)
        {
            printf("삭제할 번호를 입력해 주세요 : ");
            scanf("%d", &del);

            if((del >= 0) && (del <= 9))
            {
                if(bk[del].page == 0)
                {
                    printf("해당되는 책이 없습니다. \n\n");
                    continue;
                }
                for(i = 0; i < 10; i++)bk[del].name[i] = 0;
                for(i = 0; i < 100; i++)bk[del].title[i] = 0;
                for(i = 0; i < 100; i++)bk[del].books[i] = 0;
                bk[del].page = 0;
                printf("삭제 했습니다.\n\n");
            }
            else printf("잘못된 번호를 입력하셨습니다.\n\n");
        }
        else if(num == 3)
        {
            printf("수정할 번호를 입력해 주세요 : ");
            scanf("%d", &del);

            if((del >= 0) && (del <= 9))
            {
                if(bk[del].page == 0)
                {
                    printf("해당되는 책이 없습니다. \n\n");
                    continue;
                }
                printf("저자를 입력해 주세요 : ");
                scanf("%s", bk[del].name);
                printf("제목을 입력해 주세요 : ");
                scanf("%s", bk[del].title);
                printf("출판사를 입력해 주세요 : ");
                scanf("%s", bk[del].books);
                printf("페이지를 입력해 주세요 : ");
                scanf("%d", &bk[del].page);
                if(bk[del].page < 1)
                {
                    printf("잘못된 값을 입력하셨습니다.\n\n");
                    for(i = 0; i < 10; i++)bk[del].name[i] = 0;
                    for(i = 0; i < 100; i++)bk[del].title[i] = 0;
                    for(i = 0; i < 100; i++)bk[del].books[i] = 0;
                    bk[del].page = 0;
                    continue;
                }
                printf("수정 했습니다.\n\n");
            }
            else printf("잘못된 번호를 입력하셨습니다.\n\n");
        }
        else if(num == 4)
        {
            printf("\n");
            for(i = 0; i < 10; i++)
            {
                if(bk[i].page != 0)
                {
                    printf("%d번\n", i);
                    printf("저자 : %s\n", bk[i].name);
                    printf("제목 : %s\n", bk[i].title);
                    printf("출판사 : %s\n", bk[i].books);
                    printf("페이지 : %d\n\n", bk[i].page);
                }
            }
        }
        else if(num == 6) break;
        else printf("\n잘못된 값을 입력했습니다.\n\n");
    }
}
