#include<stdio.h>

void array_size(int [5]);
int main(void)
{
    int zippo[4][2] = {1,2,3,4,5};
    printf("zippo       = %p,&zippo       = %p \n"
           "zippo[0]    = %p,&zippo[0]    = %p \n"
           "&zippo[0][0] = %p\n",
            zippo,&zippo,zippo[0],&zippo[0],&zippo[0][0]);
    printf("sizeof(int) = %d\n",sizeof(int));
    printf("zippo + 1 = %p\n",zippo + 1);
    printf("&zippo + 1 = %p\n",&zippo + 1);
    printf("&zippo[0] + 1 = %p\n",&zippo[0] + 1);

    int arr[5] = {1,2,3,4,5};
    printf("sizeof(arr) = %d\n",sizeof(arr));
    array_size(arr);
    return 0;
}
void array_size(int arr[5])
{
    printf("in function array_size,sizeof(arr) = %d\n",sizeof arr);
}
