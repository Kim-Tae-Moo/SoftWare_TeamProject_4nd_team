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
        printf("�Է�[1] ����[2] ����[3] ���[4] ����[6]\n");
        printf("���ϴ� ��ȣ�� ����ּ��� : ");
        scanf("%d", &num);
        if(num == 1)
        {
            for(index = 0; index < 10; index++)if(bk[index].page == 0)break;
            if(index == 10)
            {
                printf("�� �̻� ������ ������ �����ϴ�.\n\n");
                continue;
            }
            printf("���ڸ� �Է��� �ּ��� : ");
            scanf("%s", bk[index].name);
            printf("������ �Է��� �ּ��� : ");
            scanf("%s", bk[index].title);
            printf("���ǻ縦 �Է��� �ּ��� : ");
            scanf("%s", bk[index].books);
            printf("�������� �Է��� �ּ��� : ");
            scanf("%d", &bk[index].page);
            if(bk[index].page < 1)
            {
                printf("�߸��� ���� �Է��ϼ̽��ϴ�.\n\n");
                for(i = 0; i < 10; i++)bk[index].name[i] = 0;
                for(i = 0; i < 100; i++)bk[index].title[i] = 0;
                for(i = 0; i < 100; i++)bk[index].books[i] = 0;
                bk[index].page = 0;
                continue;
            }
            printf("����Ǿ����ϴ�.\n\n");
        }
        else if(num == 2)
        {
            printf("������ ��ȣ�� �Է��� �ּ��� : ");
            scanf("%d", &del);

            if((del >= 0) && (del <= 9))
            {
                if(bk[del].page == 0)
                {
                    printf("�ش�Ǵ� å�� �����ϴ�. \n\n");
                    continue;
                }
                for(i = 0; i < 10; i++)bk[del].name[i] = 0;
                for(i = 0; i < 100; i++)bk[del].title[i] = 0;
                for(i = 0; i < 100; i++)bk[del].books[i] = 0;
                bk[del].page = 0;
                printf("���� �߽��ϴ�.\n\n");
            }
            else printf("�߸��� ��ȣ�� �Է��ϼ̽��ϴ�.\n\n");
        }
        else if(num == 3)
        {
            printf("������ ��ȣ�� �Է��� �ּ��� : ");
            scanf("%d", &del);

            if((del >= 0) && (del <= 9))
            {
                if(bk[del].page == 0)
                {
                    printf("�ش�Ǵ� å�� �����ϴ�. \n\n");
                    continue;
                }
                printf("���ڸ� �Է��� �ּ��� : ");
                scanf("%s", bk[del].name);
                printf("������ �Է��� �ּ��� : ");
                scanf("%s", bk[del].title);
                printf("���ǻ縦 �Է��� �ּ��� : ");
                scanf("%s", bk[del].books);
                printf("�������� �Է��� �ּ��� : ");
                scanf("%d", &bk[del].page);
                if(bk[del].page < 1)
                {
                    printf("�߸��� ���� �Է��ϼ̽��ϴ�.\n\n");
                    for(i = 0; i < 10; i++)bk[del].name[i] = 0;
                    for(i = 0; i < 100; i++)bk[del].title[i] = 0;
                    for(i = 0; i < 100; i++)bk[del].books[i] = 0;
                    bk[del].page = 0;
                    continue;
                }
                printf("���� �߽��ϴ�.\n\n");
            }
            else printf("�߸��� ��ȣ�� �Է��ϼ̽��ϴ�.\n\n");
        }
        else if(num == 4)
        {
            printf("\n");
            for(i = 0; i < 10; i++)
            {
                if(bk[i].page != 0)
                {
                    printf("%d��\n", i);
                    printf("���� : %s\n", bk[i].name);
                    printf("���� : %s\n", bk[i].title);
                    printf("���ǻ� : %s\n", bk[i].books);
                    printf("������ : %d\n\n", bk[i].page);
                }
            }
        }
        else if(num == 6) break;
        else printf("\n�߸��� ���� �Է��߽��ϴ�.\n\n");
    }
}
