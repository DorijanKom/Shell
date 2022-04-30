#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>


int main (void){
    
    int ret = -1;
    char filename[] = "file.txt";


    
    ret = remove(filename);

    if(ret == 0) {
    printf("File deleted successfully");
     } else {
    printf("Error: unable to delete the file");
    }

    

    
}


