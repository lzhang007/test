#include     <stdio.h>      
#include     <stdlib.h> 
#include     <string.h>    
#include     <unistd.h>     
#include     <sys/types.h>  
#include     <sys/stat.h>   
#include     <fcntl.h>      
#include     <termios.h>    
#include     <errno.h>     



int main(int argc, char **argv)
{
    int ch;
    struct termios new, old;
    tcgetattr (0, &old);
    new = old;
    new.c_lflag &= (~ICANON);
    new.c_cc[VTIME] = 0;
    new.c_cc[VMIN] = 1;
    tcsetattr (0, TCSANOW, &new);
    while ((ch=getchar()) != '\n')
        printf("%c", ch);
    tcsetattr (0, TCSANOW, &old);
    return 0;
} 
