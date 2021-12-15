#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>

// �� ���� ����ü
typedef struct _customer {
    char id[20];                        //�� ID
    char name[30];                      //���̸�
    char phone[20];                     //��ȭ��ȣ
    char address[60];                   //�ּ�
}CUSTOMER;

// ���� ���� ����ü
typedef struct _book{
    char ISBN[100];                     // ISBN
    char title[200];                    // ��������
    char author[200];                   // ����
    char publishing[200];               // ���ǻ�
    int is_rented;                     //1: �뿩��, 0: �뿩���� �ƴ�
}BOOK;

//�뿩 ���� ����ü
typedef struct _rent_info{
    int id;                             // �뿩 ��ȣ
    int book_ISBN;                      // ISBN
    int customer_id;                    // ȸ����ȣ
    int rent_date;                      // �뿩 ��¥
    int ret_date;                       // �ݳ� ��¥
    int ret_due_date;                   // �ݳ����� ����
    int is_returned;                    //1: �ݳ� �Ϸ�, 0: �뿩
}RENT_INFO;

void input_customer(void);              // ȸ������������ �о ����ü�� ����Լ�
void input_book(void);                  // å ���������� �о ����ü�� ����Լ�
void new_customer(void);                // �ű� ��
void new_book(void);                    // �ű� å
int searchname_customer(void);          // �̸����� ���˻�
int searchphone_customer(void);         // ����ó�� ���˻�
int searchtitle_book(void);             // �������� �����˻�
int searchauthor_book(void);            // ���ڷ� �����˻�
void modify_customer(void);             // ȸ������ ����
void delete_customer(void);             // ȸ������ ����
void modify_book(void);                 // å���� ����
void delete_book(void);                 // å���� ����
void rent_book(void);                   // å �뿩
void return_book(void);                 // å �ݳ�
void rent_information(void);            // �뿩 ����


CUSTOMER customer_info[200];             // ȸ�������� ������� ����ü
int c_idx = 0;                          // ȸ�������� � ��Ҵ��� ī��Ʈ
BOOK book_info[200];                    // å������ ������� ����ü
int b_idx = 0;                          // å������ � ��Ҵ��� ī��Ʈ
int idx;
RENT_INFO rent;                          //�� ���� ���� �뿩/�ݳ�
int rent_id = 1;                        //�뿩��ȣ



int main(void)
{
    SetConsoleTextAttribute( GetStdHandle ( STD_OUTPUT_HANDLE), 3); //printf���� �ؽ�Ʈ ���� �ٲپ��.
    int i, sel = 1;
    input_customer();                   // �� ���� �Է�
    input_book();                       // å ���� �Է�

    while (sel != 0)
    {
        system("cls");                // ȭ�� ����� ������� cls ���� clear
        //���θ޴�

        printf("                                     ������������������������������������������������������������������������������\n");
        printf("                                     ��        < ������ ���� �ý���>        ��\n");
        printf("                                     ������������������������������������������������������������������������������\n");
        printf("                                     ��             1. �� ����            ��\n");
        printf("                                     ��             2. ���� ����            ��\n");
        printf("                                     ��             3. �뿩 ����            ��\n");
        printf("                                     ��               0. ����               ��\n");
        printf("                                     ������������������������������������������������������������������������������\n");
        printf("                                      ��ȣ�� �����ϼ���: ");
        scanf("%d", &sel);
        r:;
        switch (sel)   //sel�� ���̽��� �´� �����̸� �ش���� ���̽��� �̵��Ѵ�.
        {
            //�� ���� �޴�
            case 1:
            while (sel != 0)
            {
                system("cls");            //ȭ�� �����  .. ������� cls ���� clear
                printf("                                     ������������������������������������������������������������������������������\n");
                printf("                                     ��            < �� ���� >            ��\n");
                printf("                                     ������������������������������������������������������������������������������\n");
                printf("                                     ��        1. �ű� ȸ�� ���            ��\n");
                printf("                                     ��        2. ȸ�� ���� ����            ��\n");
                printf("                                     ��        3. ȸ�� ���� ����            ��\n");
                printf("                                     ��        4. ��ü ȸ�� ����Ʈ ���     ��\n");
                printf("                                     ��        5. ȸ�� �̸����� �˻�        ��\n");
                printf("                                     ��        6. ȸ�� ����ó�� �˻�        ��\n");
                printf("                                     ������������������������������������������������������������������������������\n");
                printf("                                     ��        9. ���θ޴��� �̵�           ��\n");
                printf("                                     ��        0. ���α׷� ����             ��\n");
                printf("                                     ������������������������������������������������������������������������������\n");;
                printf("                                       ��ȣ�� �����ϼ���: ");
                scanf("%d", &sel);

                switch (sel)  //sel�� ���̽��� �´� �����̸� �ش���� ���̽��� �̵��Ѵ�.
                {
                    case 1:
                        new_customer();
                        break;

                    case 2:
                        modify_customer();
                        break;

                    case 3:
                        delete_customer();
                        break;

                    case 4:
                        for (i = 0; i < c_idx; i++)
                        {
                            printf("                                       %s, %s, %s, %s\n"
                            , customer_info[i].id
                            , customer_info[i].name
                            , customer_info[i].phone
                            , customer_info[i].address);
                        }
                        break;

                    case 5:
                        idx = searchname_customer();
                        if (idx == -1)
                        printf("                                       ��ġ�ϴ� ���� �����ϴ�.\n");
                        else
                        {
                            printf("                                       %s, %s, %s, %s\n"
                            , customer_info[idx].id
                            , customer_info[idx].name
                            , customer_info[idx].phone
                            , customer_info[idx].address);
                        }
                        break;

                    case 6:
                        idx = searchphone_customer();
                        if (idx == -1)
                            printf("                                       ��ġ�ϴ� ���� �����ϴ�.\n");
                        else
                        {
                            printf("                                       %s, %s, %s, %s\n"
                            , customer_info[idx].id
                            , customer_info[idx].name
                            , customer_info[idx].phone
                            , customer_info[idx].address);
                        }
                        break;

                    case 9:
                        goto r;

                }
                system("pause");
            }
            break;

            //���� ���� �޴�
            case 2:
            while (sel != 0)
            {

                system("cls");            //ȭ�� �����  .. ������� cls ���� clear
                printf("                                     ������������������������������������������������������������������������������\n");
                printf("                                     ��            < ���� ���� >            ��\n");
                printf("                                     ������������������������������������������������������������������������������\n");
                printf("                                     ��        1. �ű� ���� ���            ��\n");
                printf("                                     ��        2. ���� ���� ����            ��\n");
                printf("                                     ��        3. ���� ���� ����            ��\n");
                printf("                                     ��        4. ��ü ���� ����Ʈ ���     ��\n");
                printf("                                     ��        5. ���� �������� �˻�        ��\n");
                printf("                                     ��        6. ���� ���ڷ� �˻�          ��\n");
                printf("                                     ������������������������������������������������������������������������������\n");
                printf("                                     ��        9. ���θ޴��� �̵�           ��\n");
                printf("                                     ��        0. ���α׷� ����             ��\n");
                printf("                                     ������������������������������������������������������������������������������\n");;
                printf("                                       ��ȣ�� �����ϼ���: ");
                scanf("%d", &sel);
                switch (sel)     //sel�� ���̽��� �´� �����̸� �ش���� ���̽��� �̵��Ѵ�.
                {
                    case 1:
                        new_book();
                        break;

                    case 2:
                        modify_book();
                        break;

                    case 3:
                        delete_book();
                        break;

                    case 4:
                        for (i = 0; i < b_idx; i++)
                        {
                            printf("                                       %s, %s, %s, %s, %d\n"
                            , book_info[i].ISBN
                            , book_info[i].title
                            , book_info[i].author
                            , book_info[i].publishing
                            , book_info[i].is_rented);
                        }
                    break;

                    case 5:
                        idx = searchtitle_book();
                        if (idx == -1)
                            printf("                                       ��ġ�ϴ� ������ �����ϴ�.\n");
                        else
                        {
                            printf("                                       %s, %s, %s, %s\n"
                            , book_info[idx].ISBN
                            , book_info[idx].title
                            , book_info[idx].author
                            , book_info[idx].publishing);
                        }
                        break;

                    case 6:
                        idx = searchauthor_book();
                        if (idx == -1)
                            printf("                                       ��ġ�ϴ� ������ �����ϴ�.\n");
                        else
                        {
                            printf("                                       %s, %s, %s, %s\n"
                            , book_info[idx].ISBN
                            , book_info[idx].title
                            , book_info[idx].author
                            , book_info[idx].publishing);
                        }
                        break;

                    case 9:
                        goto r;
                }
                system("pause");
            }
            //�뿩 ���� �޴�
            case 3:
            while (sel != 0)
            {

                system("cls");            //ȭ�� �����
                printf("                                     ������������������������������������������������������������������������������\n");
                printf("                                     ��            < ���� ���� >            ��\n");
                printf("                                     ������������������������������������������������������������������������������\n");
                printf("                                     ��        1. ���� �뿩                 ��\n");
                printf("                                     ��                                     ��\n");
                printf("                                     ��        2. ���� �ݳ�                 ��\n");
                printf("                                     ��                                     ��\n");
                printf("                                     ��        3. �뿩 ����                 ��\n");
                printf("                                     ��                                     ��\n");
                printf("                                     ������������������������������������������������������������������������������\n");
                printf("                                     ��        9. ���θ޴��� �̵�           ��\n");
                printf("                                     ��        0. ���α׷� ����             ��\n");
                printf("                                     ������������������������������������������������������������������������������\n");;
                printf("                                       ��ȣ�� �����ϼ���: ");
                scanf("%d", &sel);
                switch (sel)     //sel�� ���̽��� �´� �����̸� �ش���� ���̽��� �̵��Ѵ�.
                {
                    case 1:
                        rent_book();
                        break;
                    case 2:
                        return_book();
                        break;
                    case 3:
                        rent_information();
                        break;
                    case 9:
                        goto r;

                }
            }
        }
    }
}




// å �뿩
void rent_book()
{
    int i, book_ISBN, customer_id, check;
    time_t timer;
    struct tm * t;

    for (i = 0; i < b_idx; i++)
    {
        if (book_info[i].is_rented == 0)
            printf("%s,%s,%s,%s,%d \n"
                , book_info[i].ISBN
                , book_info[i].title
                , book_info[i].author
                , book_info[i].publishing
                , book_info[i].is_rented);
    }
    idx = searchtitle_book();    //å������ �˻��ؼ����� ��

                if (idx == -1){
                    printf("                                       ��ġ�ϴ� ������ �����ϴ�.\n");
                    main();
                }
                else
                {
                    printf("                                       %s,%s,%s,%s,%d\n"
                        , book_info[idx].ISBN
                        , book_info[idx].title
                        , book_info[idx].author
                        , book_info[idx].publishing
                        , book_info[idx].is_rented);
                }

    printf("                                       ===== �뿩�Ϸ��� 1, �ƴϸ� 2�� �Է����ּ���! =====\n");
    printf("\n                                       �Է� : "); scanf("%d", &check);


        if (check == 1){
            book_info[idx].is_rented = 1;
            FILE *fp = fopen("modfiybook.txt","wb");
            for(i = 0; i < b_idx; i++){
                fprintf(fp,                                        "%s,%s,%s,%s,%d\n"
                , book_info[i].ISBN
                , book_info[i].title
                , book_info[i].author
                , book_info[i].publishing
                , book_info[idx].is_rented = 1);
            }
            fclose(fp);
            remove("book_info.txt");
            char oldname[80] = "modfiybook.txt";
            char newname[80] = "book_info.txt";
            rename(oldname, newname);     //oldname �� newname �� �̸��� �ٲ۴�.
            remove("modfiybook.txt");
        }
        else
        {
            printf("                                       ó������ �ǵ��� ���ϴ�.");
            main();
          //  system("pause");
        }

    for (i = 0; i < c_idx; i++)
    {
        printf("\n%s,%s,%s,%s\n"
            , customer_info[i].id
            , customer_info[i].name
            , customer_info[i].phone
            , customer_info[i].address);
    }

    printf("�� ID�� �Է��ϼ���: ");
    scanf("%d", &customer_id);

    printf("���� �뿩�� �Ϸ�Ǿ����ϴ�.");
    system("pause");
}




// ��� ����  �ݳ�
void return_book()
{
    time_t timer;
    struct tm * t;
    int ret_sec;
    int late_pay, late_day;
    int check;
    int i;

    printf("                                      ===== ��� ������ �ݳ��Ϸ��� 1, �ƴϸ� 2�� �Է����ּ���! =====\n");
    printf("\n                                       �Է� : "); scanf("%d", &check);


        if (check == 1){
            FILE *fp = fopen("modfiybook.txt","wb");
            for(i = 0; i < b_idx; i++){
                fprintf(fp,                                        "%s,%s,%s,%s,%d\n"
                , book_info[i].ISBN
                , book_info[i].title
                , book_info[i].author
                , book_info[i].publishing
                , book_info[i].is_rented = 0);
            }
            fclose(fp);
            remove("book_info.txt");
            char oldname[80] = "modfiybook.txt";
            char newname[80] = "book_info.txt";
            rename(oldname, newname);     //oldname �� newname �� �̸��� �ٲ۴�.
            remove("modfiybook.txt");
        }
        else
        {
            printf("                                       ó������ �ǵ��� ���ϴ�.");
            main();
          //  system("pause");
        }

    printf("���� �ݳ��� �Ϸ�Ǿ����ϴ�.\n");
    system("pause");
}




//�뿩 ����
void rent_information()
{
    int i, book_ISBN, customer_id;
    time_t timer;
    struct tm * t;
    int check;

    for (i = 0; i < b_idx; i++)
    {
        if (book_info[i].is_rented == 1)
            printf("\nISBN: %s, å ����: %s, ����: %s, ���ǻ�: %s, �뿩��, �ݳ����� 0�� 0�� 0�� \n"
                , book_info[i].ISBN
                , book_info[i].title
                , book_info[i].author
                , book_info[i].publishing);
    }

    printf("\n�뿩 ������ �����Ϸ��� 1, �ƴϸ� 2�� �Է����ּ���!\n");
    printf("\n                                       �Է� : ");
    scanf("%d", &check);

    if (check == 1){
        printf("\n������ ������ �������ּ���.\n");

        idx = searchtitle_book();    //å������ �˻��ؼ����� ��
        if (book_info[idx].is_rented == !1){
            printf("                                     �ش絵���� �뿩���� �ʾҽ��ϴ�.\n");
            main();
        }
        else
        {
            printf("                                    ISBN: %s, ����: %s, ����: %s, ���ǻ�: %s, �뿩����: %d\n"
                        , book_info[idx].ISBN
                        , book_info[idx].title
                        , book_info[idx].author
                        , book_info[idx].publishing
                        , book_info[idx].is_rented);
        }

        printf("                                  ===== �ش� ������ �ݳ� �Ϸ��� 1, �ƴϸ� 2�� �Է����ּ���! =====\n");
        printf("\n                                       �Է� : "); scanf("%d", &check);


        if (check == 1){
            FILE *fp = fopen("modfiybook.txt","wb");
            for(i = 0; i < b_idx; i++){
                fprintf(fp,                                        "%s,%s,%s,%s,%d\n"
                , book_info[i].ISBN
                , book_info[i].title
                , book_info[i].author
                , book_info[i].publishing
                , book_info[idx].is_rented = 0);
            }
            fclose(fp);
            remove("book_info.txt");
            char oldname[80] = "modfiybook.txt";
            char newname[80] = "book_info.txt";
            rename(oldname, newname);     //oldname �� newname �� �̸��� �ٲ۴�.
            remove("modfiybook.txt");
        }
        else
        {
            printf("                                       ó������ �ǵ��� ���ϴ�.");
            main();
          //  system("pause");
        }

    }

    else
        {
            printf("                                       ó������ �ǵ��� ���ϴ�.");
          //  system("pause");
        }
    system("pause");

}




// �������� ���� ���� �˻�
int searchtitle_book(void)
{
    int i;
    char title[200], Ctitle[200];
    printf("                                       ����: ");
    scanf("%s", title);
    //strcpy(Ctitle, title);

    for (i = 0; i < b_idx; i++)
    {
        if (strcmp(Ctitle, book_info[i].title) == 0)
        return i;
    }
    return -1;
}

// ���ڷ� ���� ���� �˻�
int searchauthor_book(void)
{
    int i;
    char author[30];
    printf("                                       ����: ");
    scanf("%s", author);

    for (i = 0; i < b_idx; i++)
    {
        if (strcmp(author, book_info[i].author) == 0)
        return i;
    }
    return -1;
}

// �̸����� �� ���� �˻�
int searchname_customer(void)
{
    int i;
    char name[30];
    printf("                                       �̸�: ");
    scanf("%s", name);

    for (i = 0; i < c_idx; i++)
    {
        if (strcmp(name, customer_info[i].name) == 0)
        return i;
    }
    return -1;
}

// ����ó�� �� ���� �˻�
int searchphone_customer(void)
{
    int i;
    char phone[30];
    printf("                                       ����ó: ");
    scanf("%s", phone);
    for (i = 0; i < c_idx; i++)
    {
        if (strcmp(phone, customer_info[i].phone) == 0)
        return i;
    }
    return -1;
}

// �ű� å ����
void new_book(void)
{
    FILE* b_fp = fopen("book_info.txt", "a");
    //����ü �迭�� å ������ �Է¹���
    printf("                                       ISBN: ");
    scanf("%s", book_info[b_idx].ISBN);
    printf("                                       å ����: ");
    scanf("%s", book_info[b_idx].title);
    printf("                                       å ����: ");
    scanf("%s", book_info[b_idx].author);
    printf("                                       ���ǻ�: ");
    scanf("%s", book_info[b_idx].publishing);
    book_info[b_idx].is_rented = 0;
    fprintf(b_fp, "%s,%s,%s,%s,%d\n"
        , book_info[b_idx].ISBN
        , book_info[b_idx].title
        , book_info[b_idx].author
        , book_info[b_idx].publishing
        , book_info[b_idx].is_rented);

    b_idx++;
    fclose(b_fp);
}

// �ű� �� ����
void new_customer(void)
{
    FILE* m_fp = fopen("customer_info.txt", "a");
    //����ü �迭�� �� ������ �Է� ����
    printf("                                       ���� -> samuelLee17, Seongdallor, Mookimchi89\n ");
    printf("                                       ȸ�� ID: ");
    scanf("%s", customer_info [c_idx].id);
    printf("                                       ���� -> LeeSangKon, EunSeongWon, KimTaeMoo\n ");
    printf("                                       �̸�: ");
    scanf("%s", customer_info [c_idx].name);
    printf("                                       ���� -> 010-2323-3434, 010-2323-3443, 010-2332-2424\n ");
    printf("                                       ����ó: ");
    scanf("%s", customer_info [c_idx].phone);
    printf("                                       ���� -> Seoul, JeonJu, KwangJu, KyeongKi\n ");
    printf("                                       �ּ�: ");
    scanf("%s", customer_info [c_idx].address);

    fprintf(m_fp, "%s,%s,%s,%s\n"
        , customer_info [c_idx].id
        , customer_info [c_idx].name
        , customer_info [c_idx].phone
        , customer_info [c_idx].address);
    c_idx++;
    fclose(m_fp);
}

// �� ������ ���Ͽ��� �Է¹޴´�.
void input_customer(void)
{
    FILE* c_fp = fopen("customer_info.txt", "r");
    char line[150];   // �Ѷ��ξ� �о�´�.
    char* ptr;
    int word_cnt;  //����ī��Ʈ

    //�� ���� �Է�
    while (fscanf(c_fp, "%s", line) > 0)  //0���� ū���ȸ� �����͸� �о�Ͷ�
    {
        word_cnt = 0;
        ptr = strtok(line, ",");  //�о�� �����͸� , ������ ©�󳻶�
        while (ptr != NULL)
        {
            word_cnt++;
            switch (word_cnt)
            {
            case 1:  //int id
                //customer_info[c_idx].id = atoi(ptr);
                strcpy(customer_info[c_idx].id, ptr);
                break;
            case 2: //char name
                strcpy(customer_info[c_idx].name, ptr); //��Ʈ�� ī�Ǹ� ����ؼ� ���ڿ� ����
                break;
            case 3:  //char phone
                strcpy(customer_info[c_idx].phone, ptr);
                break;
            case 4:  //char address
                strcpy(customer_info[c_idx].address, ptr);
                break;

            }
            ptr = strtok(NULL, ",");
        }
        c_idx++;
    }

    fclose(c_fp);// ���������� ����
}

// å������ ���Ͽ��� �Է¹޴´�.
void input_book(void)
{

    FILE* b_fp = fopen("book_info.txt", "r");
    char line[150];   //�Ѷ��ξ� �о�´�
    char* ptr;
    int word_cnt;  //����ī��Ʈ

    //å ���� �Է�
    while (fscanf(b_fp, "%s", line) > 0) // 0���� ū���ȸ� �����͸� �о�Ͷ�
    {
        word_cnt = 0;
        ptr = strtok(line, ","); // �о�� �����͸� , ������ ©�󳻶�
        while (ptr != NULL)
        {
            word_cnt++;
            switch (word_cnt)
            {
            case 1:  //int ISBn
                strcpy(book_info[b_idx].ISBN, ptr);
                break;
            case 2: //char title
                strcpy(book_info[b_idx].title, ptr);//��Ʈ�� ī�Ǹ� ����ؼ� ���ڿ� ����
                break;
            case 3:  //char author
                strcpy(book_info[b_idx].author, ptr);
                break;
            case 4:  //char publishing
                strcpy(book_info[b_idx].publishing, ptr);
                break;
            case 5:  //int is_rented
                book_info[b_idx].is_rented = atoi(ptr);
            }
            ptr = strtok(NULL, ",");
        }
        b_idx++;
    }
    fclose(b_fp); //���������� ����
}

// ȸ�� ���� ����
void modify_customer(void)
{
    idx = searchname_customer(); //ȸ�� �̸��� �˻��ؼ����� ��

                if (idx == -1){
                    printf("                                       ��ġ�ϴ� ���� �����ϴ�.\n");
                    main();
                }
                else
                {
                    printf("                                       %s,%s,%s,%s\n"
                        , customer_info[idx].id
                        , customer_info[idx].name
                        , customer_info[idx].phone
                        , customer_info[idx].address);
                }
    //������ ���� ����
    char new_user_number[100];
    char new_user_name[100];
    char new_user_phone_number[100];
    char new_user_address[100];
    int check;
    int i;

    printf("\n                                       ������ �����մϴ�. \n\n");
    printf("                                       ���ο� �� ID�� �Է��Ͽ� �ּ��� : "); scanf("%s", &new_user_number);
    printf("                                       ���ο� �̸��� �Է��Ͽ� �ּ��� : "); scanf("%s", new_user_name);
    printf("                                       ���ο� ��ȭ��ȣ�� �Է��Ͽ� �ּ��� : "); scanf("%s", new_user_phone_number);
    printf("                                       ���ο� �ּҸ� �Է��Ͽ� �ּ��� : "); scanf("%s", new_user_address);

    printf("                                       �������� ���ο� ������ Ȯ���մϴ�.�������� \n\n");
    printf("                                       ���ο� �� ID : %s\n", new_user_number);
    printf("                                       ���ο� �̸� : %s\n", new_user_name);
    printf("                                       ���ο� ��ȭ��ȣ : %s\n", new_user_phone_number);
    printf("                                       ���ο� �ּ� : %s\n", new_user_address);
    printf("                                       �������� ������ 1, Ʋ���� 2�� �Է����ּ���! ��������\n");
    printf("\n                                       �Է� : "); scanf("%d", &check);

        if (check == 1){
            strcpy(customer_info[idx].id, new_user_number);
            strcpy(customer_info[idx].name, new_user_name);
            strcpy(customer_info[idx].phone, new_user_phone_number);
            strcpy(customer_info[idx].address, new_user_address);
            FILE *fp = fopen("modfiy.txt","wb");
            for(i = 0; i < c_idx; i++){
                fprintf(fp, "%s,%s,%s,%s\n"
                , customer_info[i].id
                , customer_info[i].name
                , customer_info[i].phone
                , customer_info[i].address);
            }
            fclose(fp);
            remove("customer_info.txt");
            char oldname[80] = "modfiy.txt";
            char newname[80] = "customer_info.txt";
            rename(oldname, newname); //oldname �� newname �� �̸��� �ٲ۴�.
            remove("modfiy.txt");
            printf("                                       ���������� ó���Ǿ����ϴ�.\n");
            printf("                                       ó������ �ǵ��� ���ϴ�.");
          //  system("pause");
        }
        else
        {
            printf("                                       \nó������ �ǵ��� ���ϴ�.");
          //  system("pause");
        }

}

// ȸ������ ����
void delete_customer(void)
{
    int i;
    printf("\n\n                                       ������ �����մϴ�.\n\n");
    idx = searchname_customer();

                if (idx == -1)
                    printf("                                       ��ġ�ϴ� ���� �����ϴ�.\n");
                else
                {
                    printf("%s,%s, %s, %s\n"
                        , customer_info[idx].id
                        , customer_info[idx].name
                        , customer_info[idx].phone
                        , customer_info[idx].address);
                }
         FILE *fp;
         fp = fopen("modfiy.txt", "wb");
//         printf("======= ������ �ϴ���  : %d =====\n", temp);
//         printf("======= �� ���� : %d =====\n", idx);

         for(i = 0; i < idx; i++)
         {
            fprintf(fp, "%s,%s,%s,%s\n"
               ,&customer_info[i].id
               ,&customer_info[i].name
               ,&customer_info[i].phone
               ,&customer_info[i].address);
         }

         for(i = idx + 1; i < c_idx; i++)
         {
            fprintf(fp, "%s,%s,%s,%s\n"
               ,&customer_info[i].id
               ,&customer_info[i].name
               ,&customer_info[i].phone
               ,&customer_info[i].address);
         }

         fclose(fp);
            remove("customer_info.txt");
            char oldname[80] = "modfiy.txt";
            char newname[80] = "customer_info.txt";
            rename(oldname, newname);
            remove("modfiy.txt");
            printf("                                       ���������� ó���Ǿ����ϴ�.\n");
            printf("                                       ó������ �ǵ��� ���ϴ�.");
            system("pause");
           //fflush(stdin);
            c_idx = 0;
            main();
}

// ���� ���� ����
void modify_book(void)
{
    idx = searchtitle_book();    //å������ �˻��ؼ����� ��

                if (idx == -1){
                    printf("                                       ��ġ�ϴ� ������ �����ϴ�.\n");
                    main();
                }
                else
                {
                    printf("                                       %s,%s,%s,%s\n"
                        , book_info[idx].ISBN
                        , book_info[idx].title
                        , book_info[idx].author
                        , book_info[idx].publishing);
                }
    //������ ���� ����
    char new_book_ISBN[100];
    char new_book_title[100];
    char new_book_author[100];
    char new_book_publishing[100];
    int check;
    int i;
    printf("\n\n                                        ������ �����մϴ�. \n\n");
    printf("                                       ���ο� ISBN�� �Է��Ͽ� �ּ��� : "); scanf("%s", new_book_ISBN);
    printf("                                       ���ο� ������ �Է��Ͽ� �ּ��� : "); scanf("%s",new_book_title);
    printf("                                       ���ο� ���ڸ� �Է��Ͽ� �ּ��� : "); scanf("%s", new_book_author);
    printf("                                       ���ο� ���ǻ縦 �Է��Ͽ� �ּ��� : "); scanf("%s", new_book_publishing);


    printf("                                       ===== ���ο� ������ Ȯ���մϴ�. ===== \n\n");
    printf("                                       ���ο� ISBN : %s\n", new_book_ISBN);
    printf("                                       ���ο� ���� : %s\n", new_book_title);
    printf("                                       ���ο� ���� : %s\n", new_book_author);
    printf("                                       ���ο� ���ǻ� : %s\n",new_book_publishing);


    printf("                                       ===== ������ 1, Ʋ���� 2�� �Է����ּ���! =====\n");
    printf("\n                                       �Է� : "); scanf("%d", &check);


        if (check == 1){
            strcpy(book_info[idx].ISBN, new_book_ISBN);
            strcpy(book_info[idx].title, new_book_title);
            strcpy(book_info[idx].author, new_book_author);
            strcpy(book_info[idx].publishing, new_book_publishing);
            FILE *fp = fopen("modfiybook.txt","wb");
            for(i = 0; i < b_idx; i++){
                fprintf(fp,                                        "%s,%s,%s,%s\n"
                , book_info[i].ISBN
                , book_info[i].title
                , book_info[i].author
                , book_info[i].publishing);
            }
            fclose(fp);
            remove("book_info.txt");
            char oldname[80] = "modfiybook.txt";
            char newname[80] = "book_info.txt";
            rename(oldname, newname);     //oldname �� newname �� �̸��� �ٲ۴�.
            remove("modfiybook.txt");
            printf("                                       ���������� ó���Ǿ����ϴ�.\n");
            printf("                                       ó������ �ǵ��� ���ϴ�.");
          //  system("pause");
        }
        else
        {
            printf("                                       ó������ �ǵ��� ���ϴ�.");
          //  system("pause");
        }

}

// ���� ���� ����
void delete_book(void)
{
    int i;
    printf("\n                                       ������ �����մϴ�.\n\n");
    idx = searchtitle_book();

                if (idx == -1)
                    printf("                                       ��ġ�ϴ� ���� �����ϴ�.\n");
                else
                {
                    printf("                                       %s,%s,%s,%s\n"
                        , book_info[idx].ISBN
                        , book_info[idx].title
                        , book_info[idx].author
                        , book_info[idx].publishing);
                }
         FILE *fp = fopen("modfiybook.txt","wb");;
//         printf("======= ������ �ϴ���  : %d =====\n", temp);
//         printf("======= �� ���� : %d =====\n", idx);

         for(i = 0; i < idx; i++)
         {
            fprintf(fp, "%s,%s,%s,%s\n"
                ,&book_info[i].ISBN
                ,&book_info[i].title
                ,&book_info[i].author
                ,&book_info[i].publishing);
         }

         for(i = idx + 1; i < b_idx; i++)
         {
            fprintf(fp, "%s,%s,%s,%s\n"
                ,&book_info[i].ISBN
                ,&book_info[i].title
                ,&book_info[i].author
                ,&book_info[i].publishing);
         }

            fclose(fp);
            remove("book_info.txt");
            char oldname[80] = "modfiybook.txt";
            char newname[80] = "book_info.txt";
            rename(oldname, newname);     //oldname �� newname �� �̸��� �ٲ۴�.
            remove("modfiybook.txt");
            printf("                                       ���������� ó���Ǿ����ϴ�.\n");
            printf("                                       ó������ �ǵ��� ���ϴ�.");
            system("pause");
           //fflush(stdin);
            b_idx = 0;
            main();
}




