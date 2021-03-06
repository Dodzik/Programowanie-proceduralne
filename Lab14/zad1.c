#include<stdio.h>

#define SQ2(x) x*x
#define SQ3(x) (x)*(x)
#define SQ4(x) ((x)*(x))
#define PR(X) printf("kwadratem " #X " jest %d \n",X)
#define PP printf(" \n ********** \n")
#define plus_i(x) a##x

int main(void)
{
int plus_i(1) = 7;
printf("\na1 = %d\n",a1);
int a=2;
PR(SQ2(7));
PR(SQ3(7));
PR(SQ4(7));
PP;
PR(SQ2(2+3));
PR(SQ3(2+3));
PR(SQ4(2+3));
PP;
PR(4/SQ2(2));
PR(4/SQ3(2));
PR(4/SQ4(2));
PP;
a=2;
PR(SQ2(++a));
a=2;
PR(SQ3(++a));
a=2;
PR(SQ4(++a));
return 0;
}
