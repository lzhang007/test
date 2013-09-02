#include<stdio.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main()
{
    struct book library[MAXBKS];
    int count = 0;
    int index;

    printf("please input the book title:(press enter to stop)");
    while(count < MAXBKS && (gets(library[count].title) != NULL) && library[count].title[0] != '\0')
    {
        printf("now enter the author:");
        gets(library[count].author);
        fprintf(stdout,"enter the value:");
        fscanf(stdin,"%f",&library[count].value);
        while(getchar() != '\n')
            continue;
        count++;
        if(count < MAXBKS)
            puts("enter the next title:");
    }

    if(count > 0)
    {
        fputs("here is the list of you bookks:\n",stdout);
        for(index = 0;index < count;index++)
        {
            printf("%s by %s:$%.2f.\n",library[index].title,library[index].author,library[index].value);
        }
    }
    else
        printf("no book in library.");

    return 0;
}
