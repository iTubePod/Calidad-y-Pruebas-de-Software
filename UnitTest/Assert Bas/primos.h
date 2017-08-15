#include <stdio.h>
#include <math.h>

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int checkPrimos(int x){
    int lim = sqrt(x);
    int test=0;
    for(int i=2; i<=x/2; i++){
        if(x%i==0)
            test=1;
    }
    if(test==0){
        printf("%d%s\n", x," PRIMO");
        return 1;
    }
    else{
        printf("%d%s\n", x," NO PRIMO");
        return 0;
    }
}
int checkAll(char *a, int start, int end, int isP)
{
    int rtrn = isP;
    int i;
    int test;
    if (start == end){
        sscanf(a, "%d", &test);
        rtrn *= checkPrimos(test);
        return rtrn;
    }
    else
    {
        for (i = start; i <= end; i++)
        {
            swap((a+start), (a+i));
            rtrn = checkAll(a, start+1, end, rtrn);
            swap((a+start), (a+i));
        }
    }
    return rtrn;
}
