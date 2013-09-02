#include<stdio.h>
#include<math.h>

int main(void)
{
    int d,b,i,t;
    scanf("%d",&d);
    if(d < 2)
        printf("decimal: %d = hex: %x\n",d,d);
    else
    {
        i = 0;
        b = 0;
        t = d;
        do
        {
            b += t % 2 * (int)pow(2,i++);
            t /= 2;
        }while(t > 0);
        printf("decimal: %d = hex: %x\n",d,b);
    }
    return 0;
}
