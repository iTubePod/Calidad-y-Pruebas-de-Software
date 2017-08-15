#include <stdio.h>
#include <math.h>

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void checkPrimos(int x){
    int lim = sqrt(x);
    int test=0;
    for(int i=2; i<=x/2; i++){
        if(x%i==0)
            test=1;
    }
    if(test==0)
        printf("%d%s\n", x," PRIMO");
    else
        printf("%d%s\n", x," NO PRIMO");
}
void checkAll(char *a, int start, int end)
{
    int i;
    int test;
    if (start == end){
        sscanf(a, "%d", &test);
        checkPrimos(test);
    }
    else
    {
        for (i = start; i <= end; i++)
        {
            swap((a+start), (a+i));
            checkAll(a, start+1, end);
            swap((a+start), (a+i));
        }
    }
}
int main(){
    char x[256];
    scanf ("%s",&x);
    int size;
    sscanf(x, "%d", &size);
    size=log10(size);
    checkAll(x, 0, size);
}
