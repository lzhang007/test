#include<stdio.h>
#include<stdlib.h>

#define NUM 40

void fillArray(double[],int);
void showArray(const double[],int);
int myComp(const void *,const void *);

int main()
{
    double vals[NUM];
    fillArray(vals,NUM);
    puts("random list:");
    showArray(vals,NUM);
    qsort(vals,NUM,sizeof(double),myComp);
    puts("sorted list:");
    showArray(vals,NUM);
    return 0;
}

void fillArray(double ar[],int n)
{
    int index;
    for(index = 0;index < n;index++)
    {
        ar[index] = (double)rand()/((double)rand() + 0.1);
    }
}

void showArray(const double ar[],int n)
{
    int index;
    for(index = 0;index < n;index++)
    {
        printf("%9.4f ",ar[index]);
        if(index % 6 == 5)
            putchar('\n');
    }
    putchar('\n');
}

int myComp(const void *p1,const void *p2)
{
    const double *a1 = p1;
    const double *a2 = p2;
    if(*a1 < *a2)
    {
        return -1;
    }
    else if(*a1 == *a2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
