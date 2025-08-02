#include <stdio.h>

int main()
{
    int temp = 0;
    int arr[100];
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf(" Mang ban dau ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n -------------- \n");

    for (int j = 0; j < 5 - 1; j++)
    {
        for (int i = 0; i < 5 - j - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
    printf("--------------\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d", arr[i]);
    }
    return 0;
}