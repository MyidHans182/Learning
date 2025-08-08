#include <stdio.h>
#include <stdbool.h>
#include "student.h"

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