#include<stdio.h>
#include<string.h>

struct SV
{
    float diem ;
    char ten[20];
};
typedef struct SV SV;

void nhap( SV *a)
{
    getchar();
    scanf("%s",a->ten);
    scanf("%f",&a->diem);
    
}
void in (SV *a)
{
    printf("%s %0.2f \n",a->ten,a->diem);
}
int main()
{
    // Nhap n sinh vien
    int n ;
    scanf("%d",&n);
    SV a[n];
    for( int i =0; i < n; i++)
    {
        nhap(&a[i]);
    }
    // In sinh vien ra
    for(int j =0; j < n ; j++)
    {
        in(&a[j]);
    }
    // Tim kiem sinh vien
    for(int i = 0; i < n ; i++)
    {
        if(a[i].diem == 9.5)
        {
            in(&a[i]);
        }
    }
    return 0;
}