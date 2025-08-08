#include <stdio.h>
#include <stdlib.h>

struct shape
{
    float length, width;
    float area, perimeter;
};
void input_parameters(struct shape rectangle[], int n)
{
    int i = 0;
    // Input the parameter:
    do{
        scanf("%f", &rectangle[i].length);
        scanf("%f", &rectangle[i].width);
        i++;
    }
    while(i <n);
}
void print_result(struct shape rectangle[], int n )
{
    for(int i = 0; i < n; i++)
    {
        printf("-----------------");
        printf("\n Rectangle %d \n",i+1);
        printf("Length: %.2f, Width: %.2f\n", rectangle[i].length, rectangle[i].width);
        printf("Perimeter: %.2f\n",  rectangle[i].perimeter);
        printf("Area: %.2f\n",  rectangle[i].area);
        printf("-----------------");
    }
}
void calculate(struct shape rectangle[], int n )
{
    // Calculate perimeter and area
    for(int i = 0; i < n; i++)
    {
        rectangle[i].area =rectangle[i].length * rectangle[i].width;
        rectangle[i].perimeter = (rectangle[i].length + rectangle[i].width) * 2;
    }
}
int main()
{
    int n = 0;
    printf("Input the number of rectangle ");
    scanf("%d",&n);
    struct shape *rectangle = (struct shape *)malloc(n*sizeof(struct shape));
    if (rectangle == NULL)
    {
        printf(" Fail to allocate the memory \n");
        return 1;
    }
    input_parameters(rectangle,n);
    calculate(rectangle,n);
    print_result(rectangle,n);
    free(rectangle);
    return 0;
}