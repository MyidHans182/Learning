#include<stdio.h>

int main()
{
    int arr[100], count = 0, x =0;
    int arr2[100];
    printf("Nhap phan tu cua mang \n");
    for(int i = 0; i < 5; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("------------- \n");
    printf(" Nhap so can tim trong mang : =");
    scanf("%d",&x);
    for(int i = 0; i < 5; i++)
    {
        if(arr[i]==x)
        {
            count +=1;
        }
    }
    printf("So lan xuat hien cua %d la %d",x,count);
    return 0;
}