#include<stdio.h>
#define SIZE 50
struct SV
{
    char name[100];
    int id;
    float score;
};
void input_student (struct SV student[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf(" Thong tin sinh vien thu %d \n",i+1);
        scanf("%s",student[i].name);
        scanf("%d",&student[i].id);
        scanf("%f",&student[i].score);
        printf("---------- \n");
    }
}
void print_student (struct SV student[], int n)
{
    // In ra tên sinh viên,thông tin, điểm số
    for(int i = 0; i < n; i++)
    {
        printf("%s\n ",student[i].name);
        printf("%d\n ",student[i].id);
        printf("%0.2f\n ",student[i].score);
    }
}
float total_score(struct SV student[], int n )
{
    float total = 0;
    for( int i = 0; i < n ; i++)
    {
        total = total + student[i].score;  
    }
    return total;
}
int main()
{
    int n = 0;
    float total = 0, min_score = 0, max_score = 0;
    struct SV student[SIZE];    
    printf(" Nhap so sinh vien can nhap ");
    scanf("%d",&n);
    // Nhập tên sinh viên, thông tin, điểm số
    if(SIZE >= n)
    {
        input_student(student, n);
    }
    else
    {
        printf(" Vuot qua so hoc sinh \n");
    }
    print_student(student, n);
    total = total_score(student, n);
    printf("Tong diem cua lop la %0.2f \n", total);

    for ( int i = 0; i <n ; i++)
    {
        min_score = student[0].score;
        max_score = student[0].score;
        if(min_score > student[i].score)
        {
            min_score = student[i].score;
        }
        if(max_score < student[i].score)
        {
            max_score = student[i].score;
        }
    }
    printf(" Diem thap nhat la %0.2f \n", min_score);
    printf(" Diem cao nhat la %0.2f", max_score);
    return 0;
}