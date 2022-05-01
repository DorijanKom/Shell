#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>


int main(char *input[],int argc){
    

    unsigned int charcounter;
    unsigned int argscharcount=0;

    /*In case a user only types in cowsay this is printed out*/
    if( argc == 1 ) {
        printf("This program displays all of it arguments in a speech bubble.\n"
        "After typing in the command, type in what you want Tux to say.");
        exit(EXIT_FAILURE);
    }

    
    for(charcounter=1;charcounter<argc;charcounter++){
        argscharcount=(argscharcount+1+strlen(input[charcounter])); //Counts the characters in the given argument
    }
    if(argscharcount==0){
        printf("This program displays all of it arguments in a speech bubble.\n"
        "After typing in the command, type in what you want Tux to say."); //If no arguments are given this message is printed out.
        exit(EXIT_FAILURE);
    }

    argscharcount=argscharcount+1;

    //Displays the speech bubble
    printf(" ");
    for(charcounter=1;charcounter<=argscharcount;charcounter++){
        printf("_");
    }
    printf("\n<");

    for(charcounter=1;charcounter<argscharcount;charcounter++){
        printf("%s",input[charcounter]);
    }
    printf(">\n");
    for(charcounter=1;charcounter<=argscharcount;charcounter++){
        printf("-");
    }
    printf("\n");

    
    char *line1 = "   \\ \n";           // Character that displays when you type in cowsay
    char *line2 = "    \\ \n";
    char *line3 = "        .--. \n";
    char *line4 = "       |o_o | \n";
    char *line5 = "       |:_/ | \n";
    char *line6 = "      //   \\ \\ \n";
    char *line7 = "     (|     | ) \n";
    char *line8 = "    /'\\_   _/`\\ \n";
    char *line9 = "    \\___)=(___/ \n";


    printf("%s", line1);
    printf("%s", line2);
    printf("%s", line3);
    printf("%s", line4);
    printf("%s", line5);
    printf("%s", line6);
    printf("%s", line7);
    printf("%s", line8);
    printf("%s", line9);
    
    return 0;

}

