#include<stdio.h>
#define ROWS 3
#define COLS 2
int sum_2d(int,int,int ar[*][*]);
int main(void)
{
    int arr[ROWS][COLS] ={
        {1,2},
        {3,4},
        {5,6,} };
    printf("sum of ar = %d\n",sum_2d(ROWS,COLS,arr) );
    return 0;
}
int sum_2d(int rows,int cols,int ar[rows][cols])
{
    int r,c;
    int sum = 0;
    for(r = 0; r < rows; r++)
        for(c = 0; c < cols;c++)
            sum += ar[r][c];
    return sum;
}
