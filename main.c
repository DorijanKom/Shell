#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>



void prompt(){
    
    char hostname[HOST_NAME_MAX];
    char *username = getenv("USER");
    gethostname(hostname,HOST_NAME_MAX);
    getlogin_r(username,LOGIN_NAME_MAX);
    printf("[%s]@",hostname);
    printf("[%s]$",username);
}


int main(void){

    // We use the input variable for user input
    char input[1024];
    
    while (1)
    {
        prompt();
        /* fgets is more optimal than scanf for user input because it reads a line of text and is
        better at handling overflow of arrays */
        fgets(input,1024,stdin);
    }
        
    return 0;
}