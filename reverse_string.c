#include<stdio.h>
#include <stdlib.h>
void input_string(char* arr, int n)
{
    // step 1: Viết hàm nhập chuỗi
    printf("Nhap so phan tu cua chuoi: ");
    getchar();
    for(int i = 0; i <n; i++)
    {
        scanf("%c",&arr[i]);
    }
    arr[n] ='\0';

}
void forward_string(char* arr, int n)
{
    printf("Chuoi da nhap la: ");
    for(int i = 0; i <n; i++)
    {
        printf("%c",arr[i]);
    }
}
void reverse_string(char* arr,int n)
{
    // step 2: Viết hàm đảo ngược chuỗi
    printf("\nChuoi dao nguoc la: ");
    for(int i = n-1; i >= 0;i--)
    {
        printf("%c",arr[i]);
    }
}
int main()
{
    int n = 0;
    //Nhập số phần tử của chuỗi
    printf("Nhap so phan tu cua chuoi: ");
    scanf("%d",&n);
    // Cấp phát bộ nhớ động
    char *arr = (char *)malloc(n* sizeof(char));
    input_string(arr,n);
    forward_string(arr,n);
    reverse_string(arr,n);
        
    free(arr); // Giải phóng bộ nhớ đã cấp phát
    return 0;

}