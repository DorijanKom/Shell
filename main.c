#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

#define BRED "\e[1;31m"     // Color values using the ANSI color method from the  <stdlib.h>
#define BYEL "\e[1;33m"      
#define BCYN "\e[1;36m"
#define reset "\e[0m"

void prompt(){
    
    char hostname[HOST_NAME_MAX]; // We pass the hostname to this variable
    
    /* We call the getenv function which is located in the <stdlib.h> library
    and we pass the argument USER to get the username, after which we save it
    into the username pointer (Works only on Linux!). We can achieve the same with getlogin() */
    char *username = getenv("USER");
    gethostname(hostname,HOST_NAME_MAX); // We get the hostname through the gethostname function
    
    printf(BRED"[");
    printf(BYEL"%s",hostname);
    printf(BRED"]");
    printf(BCYN"@");
    printf(BRED"[");
    printf(BYEL"%s",username);
    printf(BRED"]");
    printf(BCYN":~$");
    printf(reset);
}

void cat(char filename[FILENAME_MAX]){ // We pass the filename as paramater
    
    char c; // This is used for reading for reading characters in a file

    fgets(filename,FILENAME_MAX,stdin); 
    FILE *fpReadFile; 

    fpReadFile = fopen(filename,"r"); // Opens the file

    if(fpReadFile){
        while ((c = getc(fpReadFile)) != EOF) // Reads file character by character
        {
            printf("%c",c); // Prints it out
        }
        fclose(fpReadFile);     // Closes the file
    } else{
        printf("\nError: Unable to open file.");
        exit(0);
    }
}

void rm(char filename[FILENAME_MAX]){

    int ret = -1;
    fgets(filename,FILENAME_MAX,stdin);

    ret = remove(filename);

    if(ret == 0){
        printf("File deleted succesfully.");
    }
    else{
        printf("Unable to delete file.");
    }
}

void cowsay(char input[MAX_INPUT]){
    
    fgets(input,MAX_INPUT,stdin);

    int charcounter=strlen(input);
    int linecount;

    printf(" ");
    for(linecount = 1;linecount<=charcounter;linecount++){
        printf("_");
    }
    
    char *line1 = "   \\ \n";           // Character that displays when you type in cowsay
    char *line2 = "    \\ \n";
    char *line3 = "        .--. \n";
    char *line4 = "       |o_o | \n";
    char *line5 = "       |:_/ | \n";
    char *line6 = "      //   \\ \\ \n";
    char *line7 = "     (|     | ) \n";
    char *line8 = "    /'\\_   _/`\\ \n";
    char *line9 = "    \\___)=(___/ \n";

    
    if(strcmp(input,"") == 0){
        printf("Linux");
    }else{
        printf("%s", input);
    }
    for(linecount = 1;linecount<=charcounter;linecount++){
        printf("-");
    }
    printf("%s", line1);
    printf("%s", line2);
    printf("%s", line3);
    printf("%s", line4);
    printf("%s", line5);
    printf("%s", line6);
    printf("%s", line7);
    printf("%s", line8);
    printf("%s", line9);

}

int main(void){

    // We use the input variable for user input
    char input[1024];
    system("clear");
    
    while (1)
    {
        prompt();
        /* fgets is more optimal than scanf for user input because it reads a line of text and is
        better at handling overflow of arrays */
        fgets(input,1024,stdin);
        

    }
        
    return 0;
}