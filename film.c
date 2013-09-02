#include<stdio.h>
#include<stdlib.h>
#include"list.h"

void ShowMovies(Item item);
int main()
{
    List movies;
    Item temp;

    InitializeList(&movies);
    if(ListIsFull(&movies))
    {
        fprintf(stderr,"no memory available!\nBye!\n");
        exit(1);
    }

    puts("enter first movie title:");
    while(gets(temp.title) != NULL && temp.title[0] != '\0')
    {
        puts("enter your rating:");
        scanf("%d",&temp.rating);
        while(getchar() != '\n')
            continue;
        if(AddItem(temp,&movies) == false)
        {
            fprintf(stderr,"Problem allocating memory\n");
            break;
        }
        if(ListIsFull(&movies))
        {
            puts("the list is full");
            break;
        }
        puts("enter next movie title:");
    }

    if(ListIsEmpty(&movies))
    {
        printf("no data entered.");
    }
    else
    {
        printf("here is the movie list:\n");
        Traverse(&movies,ShowMovies);
    }
    printf("you entered %d movies.\n",ListItemCount(&movies));
    EmptyTheList(&movies);
    printf("Bye!\n");
    return 0;
}

void ShowMovies(Item item)
{
    printf("movies: %s,rating %d\n",item.title,item.rating);
}
