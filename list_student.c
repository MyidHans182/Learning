#include <stdio.h>
#include <stdbool.h>
#define SIZE 50
struct SV
{
    char name[100];
    int id;
    float score;
};
void input_student(struct SV student[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" Thong tin sinh vien thu %d \n", i + 1);
        scanf("%s", student[i].name);
        scanf("%d", &student[i].id);
        scanf("%f", &student[i].score);
        printf("---------- \n");
    }
}
void print_student(struct SV student[], int n) {
    // In tiêu đề cột
    printf("%-20s %-10s %-10s\n", "Tên", "ID", "Score");
    printf("----------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        // %-20s: căn trái, chiếm 20 ký tự; %-10s: căn trái, 10 ký tự; %-10.2f: căn trái, 10 ký tự, 2 số thập phân
        printf("%-20s %-10d %-10.2f\n", student[i].name, student[i].id, student[i].score);
    }
}

void print_score(struct SV student[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%0.2f \n", student[i].score);
    }
}
float total_score(struct SV student[], int n)
{
    float total = 0;
    for (int i = 0; i < n; i++)
    {
        total = total + student[i].score;
    }
    return total;
}
void sort_student_score (struct SV student[], int n)
{
    // Đây sử dụng bubble soft
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (student[j].score > student[j + 1].score)
            {
                struct SV temp = student[j];
                student[j] = student[j + 1];
                student[j + 1] = temp;
            }
        }
    }
}
float find_min_max(struct SV student[], int n, bool flag)
{

    float score = student[0].score;
    for (int i = 0; i < n; i++)
    {
        if (flag == true)
        {
            if (score > student[i].score)
            {
                score = student[i].score;
            }
        }
        else
        {
            if (score < student[i].score)
            {
                score = student[i].score;
            }
        }
    }

    return score;
}
int main()
{
    int n = 0;
    float total = 0, min_score = 0, max_score = 0;
    struct SV student[SIZE];
    printf(" Nhap so sinh vien can nhap ");
    scanf("%d", &n);
    // Nhập tên sinh viên, thông tin, điểm số
    if (SIZE >= n)
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
    min_score = find_min_max(student, n, true);
    max_score = find_min_max(student, n, false);

    sort_student_score (student, n);
    print_score(student, n);
    printf(" Diem thap nhat la %0.2f \n", min_score);
    printf(" Diem cao nhat la %0.2f", max_score);
    return 0;
}