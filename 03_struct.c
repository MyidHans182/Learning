#include <stdio.h>
#include <string.h>
struct sinhvien
{
    /* data */
    char ma[20];
    char ten[20];
    float diem;
    char lop[20];
};

int main ()
{
    struct sinhvien A;
    A.diem = 9.8;
    strcpy(A.ma, "19151127");
    strcpy(A.lop,"10A12");
    strcpy(A.ten,"Nguyen Minh Hoang");
    printf("Day la ten %s \n",A.ten);
    printf("Day la lop %s \n",A.lop);
    printf("Day la ma sinh vien %s \n",A.ma);
    printf("Day la diem %0.2f \n",A.diem);
    struct sinhvien B;
    B.diem = 10;
    strcpy(B.ma,"2020112");
    strcpy(B.lop,"11A12");
    strcpy(B.ten,"Nguyen Minh Hoang");
    printf("Day la ten %s \n",B.ten);
    printf("Day la lop %s \n",B.lop);
    printf("Day la ma sinh vien %s \n",B.ma);
    printf("Day la diem %0.2f",B.diem);
}