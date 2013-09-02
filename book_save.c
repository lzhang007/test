#include<stdio.h>
#include<stdlib.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10

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
    int index,filecount;
    FILE *pbooks;
    int size = sizeof(struct book);

    if((pbooks = fopen("bool.dat","a+")) == NULL)
    {
        fprintf(stderr,"can't open file\n");
        exit(1);
    }
    rewind(pbooks);
    while(count < MAXBKS && fread(&library[count],size,1,pbooks) == 1)
    {
        if(count == 0)
            puts("current contents of book.dat:");
        printf("%s by %s: %.2f\n",library[count].title,library[count].author,library[count].value);
        count++;
    }
    
    filecount = count;
    if(count == MAXBKS)
    {
        fputs("the book.dat is full.\n",stderr);
        exit(2);
    }
    puts("please add new book:(press enter at the start of new line to stop)");
    puts("title:");
    while(count < MAXBKS && gets(library[count].title) != NULL && library[count].title[0] != '\0')
    {
        puts("now enter the author:");
        gets(library[count].author);
        puts("value:");
        scanf("%f",&library[count].value);
        count++;
        while(getchar() != '\n')
            continue;
        if(count < MAXBKS)
            puts("new title:");
    }

    if(count > 0)
    {
        puts("here is you book:");
        for(index = 0; index < count;index++)
        {
            printf("%s by %s: %.2f\n",library[index].title,library[index].author,library[index].value);
        }
        fwrite(&library[filecount],size,count - filecount,pbooks);
    }
    else
        puts("no books?too bad");
    puts("bye.\n");
    fclose(pbooks);
    return 0;
}
