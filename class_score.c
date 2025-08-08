#include <stdio.h>
enum score
{
    A,
    B,
    C,
    D,
    F,
    INVALID
};
enum score Classify(float score)
{
    if (score >= 8.5 && score <= 10)
    {
        return A;
    }
    else if (score >= 7.0 && score < 8.5)
    {
        return B;
    }
    else if (score >= 5.5 && score < 7.0)
    {
        return C;
    }
    else if (score >= 4.0 && score < 5.5)
    {
        return D;
    }
    else if (score >= 0 && score < 4.0)
    {
        return F;
    }
    else
    {
        return INVALID ;
    }
}
int main()
{
    float score = 0;
    printf(" Input your score ");
    scanf("%f", &score);
    if (score <= 10 && score >= 0)
    {
        enum score classify_score = Classify(score);
        switch (classify_score)
        {
        case A:
            printf(" A ");
            break;
        case B:
            printf(" B ");
            break;
        case C:
            printf(" C ");

            break;
        case D:
            printf(" D ");

            break;
        case F:
            printf(" F ");
            break;
        default:
            break;
        }
    }
    else{
        printf(" Invalid score \n");
        return 1;
    }
    return 0;
}