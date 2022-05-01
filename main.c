#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

                            // Color values using the ANSI color method from the  <stdlib.h>
#define BRED "\e[1;31m"     // Red with bold characters
#define BYEL "\e[1;33m"     // Yellow with bold characters
#define BCYN "\e[1;36m"     // Cyan with bold characters
#define reset "\e[0m"       // Value for reseting the characters to the default format

void prompt(){
    
    char hostname[HOST_NAME_MAX]; // We pass the hostname to this variable
    
    /* We call the getenv function which is located in the <stdlib.h> library
    and we pass the argument USER to get the username, after which we save it
    into the username pointer (Works only on Linux!). We can achieve the same with getlogin() */
    char *username = getenv("USER");
    gethostname(hostname,HOST_NAME_MAX); // We get the hostname through the gethostname function
    
    printf(BRED"[");            // We implement the colors from this line and reset them to the default on line 30
    printf(BYEL"%s",hostname);
    printf(BRED"]");
    printf(BCYN"@");
    printf(BRED"[");
    printf(BYEL"%s",username);
    printf(BRED"]");
    printf(BCYN":~$ ");
    printf(reset);
}

void cat(char filename[FILENAME_MAX]){ // We pass the filename as paramater

    FILE *fpReadFile; 

    
    char c; // This is used for reading for reading characters in a file

    fpReadFile = fopen(filename,"r"); // Opens the file

    if(fpReadFile==NULL){
        
        printf("\nError: Unable to open file.");
        exit(0);
    }
    while ((c = getc(fpReadFile)) != EOF) // Reads file character by character
    {
        printf("%c",c); // Prints it out
        c=fgetc(fpReadFile);
    }
    fclose(fpReadFile);     // Closes the file
    printf("\n"); 
}

void rm(char filename[FILENAME_MAX]){

    int ret = -1;

    ret = remove(filename);

    if(ret == 0){
        printf("File deleted succesfully.\n");
    }
    else{
        printf("Error: Unable to delete file.\n");
    }
}

void cowsay(int argc,char *input[]){
    

    unsigned int counter;
    unsigned int argscharcount=0;

    /*In case a user only types in cowsay this is printed out*/
    if( argc == 1 ) {
        printf("This program displays all of it arguments in a speech bubble.\n"
        "After typing in the command, type in what you want Tux to say.");
        exit(EXIT_FAILURE);
    }

    
    for(counter=1;counter < argc;counter++){
        argscharcount=(argscharcount+1+strlen(input[counter])); //Counts the characters in the given argument
    }
    if(argscharcount==0){
        printf("This program displays all of it arguments in a speech bubble.\n" 
        "After typing in the command, type in what you want Tux to say."); //If no arguments are given this message is printed out.
        exit(EXIT_FAILURE);
    }

    argscharcount=argscharcount+1;

    //Displays the speech bubble
    printf(" ");
    for(counter=1;counter<=argscharcount;counter++){
        printf("_");
        if(counter==50) break;
    }
     printf("\n<");

    for(counter=1;counter<argc;counter++){
        printf("%s",input[counter]);
        if(counter%7==0) printf("\n< ");
    }
    printf(">\n");
    printf(" ");
    for(counter=1;counter<=argscharcount;counter++){
        printf("-");
        if(counter==50) break;
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

}

void clear(){
    const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J"; // ANSI code for clearing screen (Works only on Linux because of the file descriptor we are using)
    write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 11);    // Write method takes in the CLEAR_SCREEN_ANSI variable and
}                                                   // outputs it, which clears the screen

int main(void){

    // We use the input variable for user input
    char input[MAX_INPUT];
    system("clear"); //When we first initiate our shell the screen is cleared(This is Linux specific, on Windows it is system("cls"))
    while (1)
    {
        prompt();
        /* fgets is more optimal than scanf for user input because it reads a line of text and is
        better at handling overflow of arrays */
        fgets(input,MAX_INPUT,stdin);
    }
        
    return 0;
}