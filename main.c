#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>

//설계 및 프로그램 작성 : 은성원
//설계 및 프로그램 수정 : 김태무
//설계 및 회원정보 담당: 이원겸
//설계 및 도서정보 담당 : 

// 고객 정보 구조체
typedef struct _customer {
    char id[20];                        //고객 ID
    char name[30];                      //고객이름
    char phone[20];                     //전화번호
    char address[60];                   //주소
}CUSTOMER;

// 도서 정보 구조체
typedef struct _book{
    char ISBN[100];                     // ISBN
    char title[200];                    // 도서제목
    char author[200];                   // 저자
    char publishing[200];               // 출판사
    int is_rented;                     //1: 대여중, 0: 대여중이 아님
}BOOK;

//대여 정보 구조체
typedef struct _rent_info{
    int id;                             // 대여 번호
    int book_ISBN;                      // ISBN
    int customer_id;                    // 회원번호
    int rent_date;                      // 대여 날짜
    int ret_date;                       // 반납 날짜
    int ret_due_date;                   // 반납예정 일자
    int is_returned;                    //1: 반납 완료, 0: 대여
}RENT_INFO;

void input_customer(void);              // 회원정보파일을 읽어서 구조체에 담는함수
void input_book(void);                  // 책 정보파일을 읽어서 구조체에 담는함수
void new_customer(void);                // 신규 고객
void new_book(void);                    // 신규 책
int searchname_customer(void);          // 이름으로 고객검색
int searchphone_customer(void);         // 연락처로 고객검색
int searchtitle_book(void);             // 제목으로 도서검색
int searchauthor_book(void);            // 저자로 도서검색
void modify_customer(void);             // 회원정보 수정
void delete_customer(void);             // 회원정보 삭제
void modify_book(void);                 // 책정보 수정
void delete_book(void);                 // 책정보 삭제
void rent_book(void);                   // 책 대여
void return_book(void);                 // 책 반납
void rent_information(void);            // 대여 정보


CUSTOMER customer_info[200];             // 회원정보를 담기위한 구조체
int c_idx = 0;                          // 회원정보를 몇개 담았는지 카운트
BOOK book_info[200];                    // 책정보를 담기위한 구조체
int b_idx = 0;                          // 책정보를 몇개 담았는지 카운트
int idx;
RENT_INFO rent;                          //한 개의 비디오 대여/반납
int rent_id = 1;                        //대여번호



int main(void)
{
    SetConsoleTextAttribute( GetStdHandle ( STD_OUTPUT_HANDLE), 3); //printf문의 텍스트 색을 바꾸어라.
    int i, sel = 1;
    input_customer();                   // 고객 정보 입력
    input_book();                       // 책 정보 입력

    while (sel != 0)
    {
        system("cls");                // 화면 지우기 윈도우는 cls 맥은 clear
        //메인메뉴

        printf("                                     ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
        printf("                                     ┃        < 도서관 정보 시스템>        ┃\n");
        printf("                                     ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
        printf("                                     ┃             1. 고객 관리            ┃\n");
        printf("                                     ┃             2. 도서 관리            ┃\n");
        printf("                                     ┃             3. 대여 관리            ┃\n");
        printf("                                     ┃               0. 종료               ┃\n");
        printf("                                     ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
        printf("                                      번호를 선택하세요: ");
        scanf("%d", &sel);
        r:;
        switch (sel)   //sel이 케이스에 맞는 숫자이면 해당숫자 케이스로 이동한다.
        {
            //고객 관리 메뉴
            case 1:
            while (sel != 0)
            {
                system("cls");            //화면 지우기  .. 윈도우는 cls 맥은 clear
                printf("                                     ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
                printf("                                     ┃            < 고객 관리 >            ┃\n");
                printf("                                     ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
                printf("                                     ┃        1. 신규 회원 등록            ┃\n");
                printf("                                     ┃        2. 회원 정보 수정            ┃\n");
                printf("                                     ┃        3. 회원 정보 삭제            ┃\n");
                printf("                                     ┃        4. 전체 회원 리스트 출력     ┃\n");
                printf("                                     ┃        5. 회원 이름으로 검색        ┃\n");
                printf("                                     ┃        6. 회원 연락처로 검색        ┃\n");
                printf("                                     ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
                printf("                                     ┃        9. 메인메뉴로 이동           ┃\n");
                printf("                                     ┃        0. 프로그램 종료             ┃\n");
                printf("                                     ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");;
                printf("                                       번호를 선택하세요: ");
                scanf("%d", &sel);

                switch (sel)  //sel이 케이스에 맞는 숫자이면 해당숫자 케이스로 이동한다.
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
                        printf("                                       일치하는 고객이 없습니다.\n");
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
                            printf("                                       일치하는 고객이 없습니다.\n");
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

            //도서 관리 메뉴
            case 2:
            while (sel != 0)
            {

                system("cls");            //화면 지우기  .. 윈도우는 cls 맥은 clear
                printf("                                     ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
                printf("                                     ┃            < 도서 관리 >            ┃\n");
                printf("                                     ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
                printf("                                     ┃        1. 신규 도서 등록            ┃\n");
                printf("                                     ┃        2. 도서 정보 수정            ┃\n");
                printf("                                     ┃        3. 도서 정보 삭제            ┃\n");
                printf("                                     ┃        4. 전체 도서 리스트 출력     ┃\n");
                printf("                                     ┃        5. 도서 제목으로 검색        ┃\n");
                printf("                                     ┃        6. 도서 저자로 검색          ┃\n");
                printf("                                     ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
                printf("                                     ┃        9. 메인메뉴로 이동           ┃\n");
                printf("                                     ┃        0. 프로그램 종료             ┃\n");
                printf("                                     ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");;
                printf("                                       번호를 선택하세요: ");
                scanf("%d", &sel);
                switch (sel)     //sel이 케이스에 맞는 숫자이면 해당숫자 케이스로 이동한다.
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
                            printf("                                       일치하는 도서가 없습니다.\n");
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
                            printf("                                       일치하는 도서가 없습니다.\n");
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
            //대여 관리 메뉴
            case 3:
            while (sel != 0)
            {

                system("cls");            //화면 지우기
                printf("                                     ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
                printf("                                     ┃            < 도서 관리 >            ┃\n");
                printf("                                     ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
                printf("                                     ┃        1. 도서 대여                 ┃\n");
                printf("                                     ┃                                     ┃\n");
                printf("                                     ┃        2. 도서 반납                 ┃\n");
                printf("                                     ┃                                     ┃\n");
                printf("                                     ┃        3. 대여 정보                 ┃\n");
                printf("                                     ┃                                     ┃\n");
                printf("                                     ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
                printf("                                     ┃        9. 메인메뉴로 이동           ┃\n");
                printf("                                     ┃        0. 프로그램 종료             ┃\n");
                printf("                                     ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");;
                printf("                                       번호를 선택하세요: ");
                scanf("%d", &sel);
                switch (sel)     //sel이 케이스에 맞는 숫자이면 해당숫자 케이스로 이동한다.
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




// 책 대여
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
    idx = searchtitle_book();    //책제목을 검색해서나온 줄

                if (idx == -1){
                    printf("                                       일치하는 도서가 없습니다.\n");
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

    printf("                                       ===== 대여하려면 1, 아니면 2를 입력해주세요! =====\n");
    printf("\n                                       입력 : "); scanf("%d", &check);


        if (check == 1){
            book_info[idx].is_rented = 1;
            FILE *fp = fopen("modfiybook.txt","wb");
            for(i = 0; i < b_idx; i++){
                fprintf(fp, "%s,%s,%s,%s,%d\n"
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
            rename(oldname, newname);     //oldname 와 newname 의 이름을 바꾼다.
            remove("modfiybook.txt");
        }
        else
        {
            printf("                                       처음으로 되돌아 갑니다.");
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

    printf("고객 ID를 입력하세요: ");
    scanf("%d", &customer_id);

    printf("도서 대여가 완료되었습니다.");
    system("pause");
}




// 모든 도서  반납
void return_book()
{
    time_t timer;
    struct tm * t;
    int ret_sec;
    int late_pay, late_day;
    int check;
    int i;

    printf("                                      ===== 모든 도서를 반납하려면 1, 아니면 2를 입력해주세요! =====\n");
    printf("\n                                       입력 : "); scanf("%d", &check);


        if (check == 1){
            FILE *fp = fopen("modfiybook.txt","wb");
            for(i = 0; i < b_idx; i++){
                fprintf(fp, "%s,%s,%s,%s,%d\n"
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
            rename(oldname, newname);     //oldname 와 newname 의 이름을 바꾼다.
            remove("modfiybook.txt");
        }
        else
        {
            printf("                                       처음으로 되돌아 갑니다.");
            main();
        }

    printf("도서 반납이 완료되었습니다.\n");
    system("pause");
}




//대여 정보
void rent_information()
{
    int i, book_ISBN, customer_id;
    time_t timer;
    struct tm * t;
    int check;

    for (i = 0; i < b_idx; i++)
    {
        if (book_info[i].is_rented == 1)
            printf("\nISBN: %s, 책 제목: %s, 저자: %s, 출판사: %s, 대여중, 반납일자 0년 0월 0일 \n"
                , book_info[i].ISBN
                , book_info[i].title
                , book_info[i].author
                , book_info[i].publishing);
    }

    printf("\n대여 정보를 수정하려면 1, 아니면 2를 입력해주세요!\n");
    printf("\n                                       입력 : ");
    scanf("%d", &check);

    if (check == 1){
        printf("\n수정할 도서를 선택해주세요.\n");

        idx = searchtitle_book();    //책제목을 검색해서나온 줄
        if (book_info[idx].is_rented == !1){
            printf("                                     해당도서는 대여되지 않았습니다.\n");
            main();
        }
        else
        {
            printf("                                    ISBN: %s, 제목: %s, 저자: %s, 출판사: %s, 대여정보: %d\n"
                        , book_info[idx].ISBN
                        , book_info[idx].title
                        , book_info[idx].author
                        , book_info[idx].publishing
                        , book_info[idx].is_rented);
        }

        printf("                                  ===== 해당 도서를 반납 하려면 1, 아니면 2를 입력해주세요! =====\n");
        printf("\n                                       입력 : "); scanf("%d", &check);


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
            rename(oldname, newname);     //oldname 와 newname 의 이름을 바꾼다.
            remove("modfiybook.txt");
        }
        else
        {
            printf("                                       처음으로 되돌아 갑니다.");
            main();
        }

    }
    else printf("                                       처음으로 되돌아 갑니다.");
    system("pause");

}


// 제목으로 도서 정보 검색
int searchtitle_book(void)
{
    int i;
    char title[200], Ctitle[200];
    printf("                                       제목: ");
    scanf("%s", title);

    for (i = 0; i < b_idx; i++)
    {
        if (strcmp(Ctitle, book_info[i].title) == 0)
        return i;
    }
    return -1;
}

// 저자로 도서 정보 검색
int searchauthor_book(void)
{
    int i;
    char author[30];
    printf("                                       저자: ");
    scanf("%s", author);

    for (i = 0; i < b_idx; i++)
    {
        if (strcmp(author, book_info[i].author) == 0)
        return i;
    }
    return -1;
}

// 이름으로 고객 정보 검색
int searchname_customer(void)
{
    int i;
    char name[30];
    printf("                                       이름: ");
    scanf("%s", name);

    for (i = 0; i < c_idx; i++)
    {
        if (strcmp(name, customer_info[i].name) == 0)
        return i;
    }
    return -1;
}

// 연락처로 고객 정보 검색
int searchphone_customer(void)
{
    int i;
    char phone[30];
    printf("                                       연락처: ");
    scanf("%s", phone);
    for (i = 0; i < c_idx; i++)
    {
        if (strcmp(phone, customer_info[i].phone) == 0)
        return i;
    }
    return -1;
}

// 신규 책 정보
void new_book(void)
{
    FILE* b_fp = fopen("book_info.txt", "a");
    //구조체 배열에 책 정보를 입력받음
    printf("                                       ISBN: ");
    scanf("%s", book_info[b_idx].ISBN);
    printf("                                       책 제목: ");
    scanf("%s", book_info[b_idx].title);
    printf("                                       책 저자: ");
    scanf("%s", book_info[b_idx].author);
    printf("                                       출판사: ");
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

// 신규 고객 정보
void new_customer(void)
{
    FILE* m_fp = fopen("customer_info.txt", "a");
    //구조체 배열에 고객 정보를 입력 받음
    printf("                                       예시 -> samuelLee17, Seongdallor, Mookimchi89\n ");
    printf("                                       회원 ID: ");
    scanf("%s", customer_info [c_idx].id);
    printf("                                       예시 -> LeeSangKon, EunSeongWon, KimTaeMoo\n ");
    printf("                                       이름: ");
    scanf("%s", customer_info [c_idx].name);
    printf("                                       예시 -> 010-2323-3434, 010-2323-3443, 010-2332-2424\n ");
    printf("                                       연락처: ");
    scanf("%s", customer_info [c_idx].phone);
    printf("                                       예시 -> Seoul, JeonJu, KwangJu, KyeongKi\n ");
    printf("                                       주소: ");
    scanf("%s", customer_info [c_idx].address);

    fprintf(m_fp, "%s,%s,%s,%s\n"
        , customer_info [c_idx].id
        , customer_info [c_idx].name
        , customer_info [c_idx].phone
        , customer_info [c_idx].address);
    c_idx++;
    fclose(m_fp);
}

// 고객 정보를 파일에서 입력받는다.
void input_customer(void)
{
    FILE* c_fp = fopen("customer_info.txt", "r");
    char line[150];   // 한라인씩 읽어온다.
    char* ptr;
    int word_cnt;  //워드카운트

    //고객 정보 입력
    while (fscanf(c_fp, "%s", line) > 0)  //0보다 큰동안만 데이터를 읽어와라
    {
        word_cnt = 0;
        ptr = strtok(line, ",");  //읽어온 데이터를 , 단위로 짤라내라
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
                strcpy(customer_info[c_idx].name, ptr); //스트링 카피를 사용해서 문자열 복사
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

    fclose(c_fp);// 파일포인터 종료
}

// 책정보를 파일에서 입력받는다.
void input_book(void)
{

    FILE* b_fp = fopen("book_info.txt", "r");
    char line[150];   //한라인씩 읽어온다
    char* ptr;
    int word_cnt;  //워드카운트

    //책 정보 입력
    while (fscanf(b_fp, "%s", line) > 0) // 0보다 큰동안만 데이터를 읽어와라
    {
        word_cnt = 0;
        ptr = strtok(line, ","); // 읽어온 데이터를 , 단위로 짤라내라
        while (ptr != NULL)
        {
            word_cnt++;
            switch (word_cnt)
            {
            case 1:  //int ISBn
                strcpy(book_info[b_idx].ISBN, ptr);
                break;
            case 2: //char title
                strcpy(book_info[b_idx].title, ptr);//스트링 카피를 사용해서 문자열 복사
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
    fclose(b_fp); //파일포인터 종료
}

// 회원 정보 수정
void modify_customer(void)
{
    idx = searchname_customer(); //회원 이름을 검색해서나온 줄

                if (idx == -1){
                    printf("                                       일치하는 고객이 없습니다.\n");
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
    //수정할 내용 정의
    char new_user_number[100];
    char new_user_name[100];
    char new_user_phone_number[100];
    char new_user_address[100];
    int check;
    int i;

    printf("\n                                       변경을 시작합니다. \n\n");
    printf("                                       새로운 고객 ID를 입력하여 주세요 : "); scanf("%s", &new_user_number);
    printf("                                       새로운 이름을 입력하여 주세요 : "); scanf("%s", new_user_name);
    printf("                                       새로운 전화번호를 입력하여 주세요 : "); scanf("%s", new_user_phone_number);
    printf("                                       새로운 주소를 입력하여 주세요 : "); scanf("%s", new_user_address);

    printf("                                       ━━━━ 새로운 정보를 확인합니다.━━━━ \n\n");
    printf("                                       새로운 고객 ID : %s\n", new_user_number);
    printf("                                       새로운 이름 : %s\n", new_user_name);
    printf("                                       새로운 전화번호 : %s\n", new_user_phone_number);
    printf("                                       새로운 주소 : %s\n", new_user_address);
    printf("                                       ━━━━ 맞으면 1, 틀리면 2를 입력해주세요! ━━━━\n");
    printf("\n                                       입력 : "); scanf("%d", &check);

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
            rename(oldname, newname); //oldname 와 newname 의 이름을 바꾼다.
            remove("modfiy.txt");
            printf("                                       정상적으로 처리되었습니다.\n");
            printf("                                       처음으로 되돌아 갑니다.");
          //  system("pause");
        }
        else
        {
            printf("                                       \n처음으로 되돌아 갑니다.");
          //  system("pause");
        }

}

// 회원정보 삭제
void delete_customer(void)
{
    int i;
    printf("\n\n                                       삭제를 진행합니다.\n\n");
    idx = searchname_customer();

                if (idx == -1)
                    printf("                                       일치하는 고객이 없습니다.\n");
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
//         printf("======= 지워야 하는줄  : %d =====\n", temp);
//         printf("======= 총 라인 : %d =====\n", idx);

         for(i = 0; i < idx; i++)
         {
            fprintf(fp, "%s,%s,%s,%s\n"
               ,customer_info[i].id
               ,customer_info[i].name
               ,customer_info[i].phone
               ,customer_info[i].address);
         }

         for(i = idx + 1; i < c_idx; i++)
         {
            fprintf(fp, "%s,%s,%s,%s\n"
               ,customer_info[i].id
               ,customer_info[i].name
               ,customer_info[i].phone
               ,customer_info[i].address);
         }

         fclose(fp);
            remove("customer_info.txt");
            char oldname[80] = "modfiy.txt";
            char newname[80] = "customer_info.txt";
            rename(oldname, newname);
            remove("modfiy.txt");
            printf("                                       정상적으로 처리되었습니다.\n");
            printf("                                       처음으로 되돌아 갑니다.");
            system("pause");
           //fflush(stdin);
            c_idx = 0;
            main();
}

// 도서 정보 수정
void modify_book(void)
{
    idx = searchtitle_book();    //책제목을 검색해서 나온 줄

                if (idx == -1){
                    printf("                                       일치하는 도서가 없습니다.\n");
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
    //수정할 내용 정의
    char new_book_ISBN[100];
    char new_book_title[100];
    char new_book_author[100];
    char new_book_publishing[100];
    int check;
    int i;
    printf("\n\n                                        변경을 시작합니다. \n\n");
    printf("                                       새로운 ISBN를 입력하여 주세요 : "); scanf("%s", new_book_ISBN);
    printf("                                       새로운 제목을 입력하여 주세요 : "); scanf("%s",new_book_title);
    printf("                                       새로운 저자를 입력하여 주세요 : "); scanf("%s", new_book_author);
    printf("                                       새로운 출판사를 입력하여 주세요 : "); scanf("%s", new_book_publishing);


    printf("                                       ===== 새로운 정보를 확인합니다. ===== \n\n");
    printf("                                       새로운 ISBN : %s\n", new_book_ISBN);
    printf("                                       새로운 제목 : %s\n", new_book_title);
    printf("                                       새로운 저자 : %s\n", new_book_author);
    printf("                                       새로운 출판사 : %s\n",new_book_publishing);


    printf("                                       ===== 맞으면 1, 틀리면 2를 입력해주세요! =====\n");
    printf("\n                                       입력 : ");
    scanf("%d", &check);


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
            rename(oldname, newname);     //oldname 와 newname 의 이름을 바꾼다.
            remove("modfiybook.txt");
            printf("                                       정상적으로 처리되었습니다.\n");
            printf("                                       처음으로 되돌아 갑니다.");
          //  system("pause");
        }
        else printf("                                       처음으로 되돌아 갑니다.");

}

// 도서 정보 삭제
void delete_book(void)
{
    int i;
    printf("\n                                       삭제를 진행합니다.\n\n");
    idx = searchtitle_book();

                if (idx == -1)
                    printf("                                       일치하는 고객이 없습니다.\n");
                else
                {
                    printf("                                       %s,%s,%s,%s\n"
                        , book_info[idx].ISBN
                        , book_info[idx].title
                        , book_info[idx].author
                        , book_info[idx].publishing);
                }
         FILE *fp = fopen("modfiybook.txt","wb");;
//         printf("======= 지워야 하는줄  : %d =====\n", temp);
//         printf("======= 총 라인 : %d =====\n", idx);

         for(i = 0; i < idx; i++)
         {
            fprintf(fp, "%s,%s,%s,%s\n"
                ,book_info[i].ISBN
                ,book_info[i].title
                ,book_info[i].author
                ,book_info[i].publishing);
         }

         for(i = idx + 1; i < b_idx; i++)
         {
            fprintf(fp, "%s,%s,%s,%s\n"
                ,book_info[i].ISBN
                ,book_info[i].title
                ,book_info[i].author
                ,book_info[i].publishing);
         }

            fclose(fp);
            remove("book_info.txt");
            char oldname[80] = "modfiybook.txt";
            char newname[80] = "book_info.txt";
            rename(oldname, newname);     //oldname 와 newname 의 이름을 바꾼다.
            remove("modfiybook.txt");
            printf("                                       정상적으로 처리되었습니다.\n");
            printf("                                       처음으로 되돌아 갑니다.");
            system("pause");
            b_idx = 0;
            main();
}
