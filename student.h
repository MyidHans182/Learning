#include <stdbool.h>

#ifndef student_H
#define student_H // Là header guard
#define SIZE 50

struct SV
{
    char name[100];
    int id;
    float score;
};
void input_student(struct SV student[], int n);
void print_student(struct SV student[], int n);
void print_score(struct SV student[], int n);
void sort_student_score (struct SV student[], int n);
float total_score(struct SV student[], int n);
float find_min_max(struct SV student[], int n, bool flag);

#endif