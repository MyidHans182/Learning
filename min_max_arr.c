#include <stdio.h>


void input_arr(int arr[],int n )
{   
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
        printf(" phan tu %d co gia tri la %d \n",i,arr[i]);
    }
}
int min_arr( int arr[], int n, int *min_idx)
{
    int min = arr[0];


    for( int j = 0; j < n ; j++)
    {
        if(min > arr[j])
        {
            min = arr[j];
            *min_idx = j;
        }
    }
    return min;
}
int max_arr(int arr[], int n, int *max_idx)
{   
    
    int max = arr[0];
    int index_max = 0;
    for( int t = 0; t < n ; t++)
    {
        if(max < arr[t])
        {
            max = arr[t];
            *max_idx = t;
        }
    }    
    return max;
}

int main()
{    
    // Nhap mang 
    int n = 0, idx_min = 0, idx_max = 0;
    printf("Nhap so phan n trong mang ");
    scanf("%d",&n);
    int arr[n], min = 0, max = 0;
    // Quét mảng để nhập các phần tử vào mảng
    input_arr(arr,n);
    // Tìm giá trị min max của mảng
    min = min_arr(arr,n,&idx_min);
    max= max_arr(arr,n,&idx_max);

    printf(" gia tri nho nhat %d %d\n",min,idx_min);
    printf(" gia tri lon nhat %d %d\n",max,idx_max);

    return 0;
}