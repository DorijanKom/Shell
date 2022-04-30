#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>





int main(void){

    char input[1024];
    while (1)
    {
        printf("prompt$");
        fgets(input,1024,stdin);
    }
        
    return 0;
}