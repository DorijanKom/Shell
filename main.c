#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lsh_loop(void);

int main(int argc, int **argv){

    lsh_loop();

    return EXIT_SUCCESS;
}

void lsh_loop(void){
    
    char *line;
    char **args;
    int status;

    while (status)
    {
        printf("prompt$");
        line = lsh_read_line(line);
        args = lsh_split_line(line);
        status = lsh_execute(args);
    }
    
}