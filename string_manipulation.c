#include <stdio.h>
#include <stdlib.h>
void input_string(char *str, int n)
{
    fgets(str,n,stdin);
}
void print_string(char *str, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%c",str[i]);
    }
}

int main()
{
    int n = 0;
    printf(" Init the string with n characters: ");
    scanf("%d",&n);
    char *str = (char *)malloc(n*sizeof(char));
    if(str == NULL)
    {
        printf(" Fail to init pointer");
    }
    input_string(str,n);
    print_string(str,n);
    int count = 1;
    for(int i = 0; i < n; i++)
    {
        if(str[i] == ' ')
        {
            count += 1;
        }

    }
    printf("%d", count);
    free(str);
    return 0;
}