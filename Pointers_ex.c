#include <stdio.h>
#include <stdlib.h>
void swap(int *A, int *B)
{
    int p1 = *A;
    *A = *B;
    *B = p1;
}
int find_max(int * arr, int n)
{
    int max = 0;
    max = arr[0];
    for(int i = 0; i < n; i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    // int *p1;
    // int A = 0, B = 0;
    // scanf("%d %d", &A, &B);
    // printf(" A = %d, B = %d", A, B);
    // swap(&A, &B);
    // printf(" A = %d, B = %d", A, B);
    int n = 0;
    printf(" Nhap so luong phan tu n = ");
    scanf("%d",&n);
    int *arr = (int*)malloc(n*sizeof(int));
    if(arr == NULL)
    {
        printf(" Khong khoi tao duoc \n");
    }
    int max = 0;
    for(int i = 0; i < n;i++)
    {
        scanf("%d",&arr[i]);
    }
    max = find_max(arr,n);
    printf("%d",max);
    free(arr);
    return 0;
}