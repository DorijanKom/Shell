#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char *argv[]){
    char *input=malloc(sizeof(int));
    
    for(;;){
        printf("prompt$");
        scanf("%s",input);
    }
    free(input);
    return 0;
}