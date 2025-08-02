#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>


int main()
{
    float *stogare = (float *)malloc(1000*sizeof(float));\
    if(stogare == NULL)
    {
        printf(" Khong the cap phat \n");
    }
    srand((unsigned int)time(NULL));
    float a = 40.0;
    for (int i=0;i<1000;i++)
    {
        stogare[i]=(((float)rand()/(float)(RAND_MAX)) * a);
    }
    char keyboard;
    keyboard = getchar();
    if(keyboard =='q')
    {
        printf(" Exit the program \n");
    }
    else
    {
        printf(" Nhiet do cua moi truong la \n");
        for (int i=0;i<1000;i++)
        {
            printf("%f\n", stogare[i]);
        }
        printf("-----------------------\n");
        Sleep(1000);
    }
    free(stogare);
    return 0;
}