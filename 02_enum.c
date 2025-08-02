#include <stdio.h>

enum days{ Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };

int main (){
    enum days today = Wednesday;
    printf(" this is %d ",today);
    return 0;
}