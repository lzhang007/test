#include<stdio.h>

#define LEN 20

struct name
{
    char first[LEN];
    char last[LEN];
};
struct guy
{
    struct name handle;
    char favfood[LEN];
    float income;
};

int main()
{
    struct guy fellow[2] =
    {
        {{"lei","zhang"},
        "xifan",
        12345.123},
        {{"zhang","lei"},
        "fanxi",
        1234.12}
    };
    struct guy *him;
    printf("address: #1 %p,#2 %p\n",&fellow[0],&fellow[1]);
    him = &fellow[0];
    printf("pointer: #1 %p,#2 %p\n",him,him + 1);
    printf("him->income is %f;(*him).income is %f.\n",him->income,(*him).income);

}
