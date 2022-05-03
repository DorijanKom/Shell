#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/wait.h>
#include <signal.h>

                            // Color values using the ANSI color method from the  <stdlib.h>
#define BRED "\e[1;31m"     // Red with bold characters
#define BYEL "\e[1;33m"     // Yellow with bold characters
#define BCYN "\e[1;36m"     // Cyan with bold characters
#define reset "\e[0m"       // Value for reseting the characters to the default format

#define USER_INPUT 1024

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

void cat(char filename[]){ // We pass the filename as paramater

    FILE *fpReadFile; 

    char c; // This is used for reading for reading characters in a file

    fpReadFile = fopen(filename,"r"); // Opens the file

    if(fpReadFile==NULL){
        
        printf("\nError: Unable to open file.\n");
    }
    else{
        while ((c = getc(fpReadFile)) != EOF) // Reads file character by character
        {
            printf("%c",c); // Prints it out
        }
            fclose(fpReadFile);     // Closes the file
    }
    printf("\n"); 
}

void rm(char filename[]){

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
    unsigned int argscharcount=0;;
    unsigned short skiparg;
    unsigned short thought=0;
    char upperbubble = '\\';
    char lowerbubble = '\\';
   

    /*In case a user only types in cowsay this is printed out*/
    if( argc == 1 ) {
        printf("This program displays all of it arguments in a speech bubble.\n"
        "After typing in the command, type in what you want Tux to say.");
    }
    for(counter=1;counter<argc; counter++){
        if(!strcmp(input[counter],"-t") || (!strcmp(input[counter],"--thought"))){
            thought=1;
            strcpy(&upperbubble,"O");
            strcpy(&lowerbubble,"o");
        }
        else if(!strcmp(input[counter],"-v") || !strcmp(input[counter],"--version")){
            printf("Version 0.7\n");
        }
        else if(!strcmp(input[counter],"-h") || !strcmp(input[counter],"--help")){
            printf("Usage:\n"
            "The flags should be the first set of arguments.\n"
            "cowsay <flag(s)> Sentence to say\n"
            "\n"
            "Flags:\n"
            "-h or --help    - Displays this help text\n"
            "-v or --version - Displays the package version\n"
            "-t or --thought - Thought bubble\n");
        }
    }
    
    for(counter=1;counter<argc;counter++){
        skiparg=0;
        if(!strcmp(input[counter],"-t") || !strcmp(input[counter],"--thought")){
            skiparg=1;
        }
        else if(counter<argc && skiparg==0){
        argscharcount=(argscharcount+1+strlen(input[counter])); //Counts the characters in the given argument
        }
    }
    if(argscharcount==0){
        printf("This program displays all of it arguments in a speech bubble.\n"
        "After typing in the command, type in what you want Tux to say."); //If no arguments are given this message is printed out.
    }

    argscharcount=argscharcount+1;

    //Displays the speech bubble
    printf(" ");
    for(counter=1;counter<=argscharcount;counter++){
        printf("_");
        if(counter==50) break;
    }

    if ( thought == 0 ) {
        printf("\n< ");
    }
    else if ( thought == 1 ) {
        printf("\n( ");
    }

    int letterCounter=0;
    for(counter=1;counter<argc;counter++){
        // For loop which is going through the letters of each word, one by one.
        for(int j=0;j<strlen(input[counter]);j++){

            if(skiparg==0){
                printf("%c",input[counter][j]);

                // Counting how many letters have been displayed, to format them properly.
                letterCounter++;
                if (letterCounter % 39 == 0)
                {
                    printf("\n<");
                }
            }
            else{
                printf("%c",input[counter][j+1]);
                letterCounter++;
                if (letterCounter % 39 == 0){
                    printf("\n(");
                }
            }
        }
        printf(" ");
    }
    if ( thought == 0 ) {
        printf(">\n");
    }
    else if ( thought == 1 ) {
        printf(")\n");
    }

    printf(" ");
    for(counter=1;counter<=argscharcount;counter++){
        printf("-");
        if(counter==50) break;
    }
    printf("\n");


    printf("   %c \n"          // Character that displays when you type in cowsay
    "      %c \n"
    "        .--. \n"
    "       |o_o | \n"
    "       |:_/ | \n"
    "      //   \\ \\ \n"
    "     (|     | ) \n"
    "    /'\\_   _/`\\ \n"
    "    \\___)=(___/ \n",upperbubble,lowerbubble);
}

void clear(){
    const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J"; // ANSI code for clearing screen (Works only on Linux because of the file descriptor we are using)
    write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 11);    // Write method takes in the CLEAR_SCREEN_ANSI variable and
}                                                   // outputs it, which clears the screen

void myfork(){

    int rc = fork();

    if (rc < 0){

        printf("Fork failed \n");

    }else if (rc == 0){
        printf("hello, I am child (pid:%d)\n", (int) getpid());
        execv("./child", NULL);
        kill(getpid(),SIGINT);
        printf("process killed.");
    } else { 
        int rc_wait = wait(NULL);
        printf("\nhello, I am parent of %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait, (int) getpid());
    }

}

void forkbomb(){

    printf(BRED"\n<!ALERT!>\n");
    printf(reset"Are you sure you want to initiate the forkbomb program?"
    "\nIt is highly dangerous and it will " BRED"CRASH" reset" your system, \ncausing " 
    "you to restart\n");
    printf("\nContinue? (y/N): ");

    char input[MAX_INPUT];
    fgets(input,MAX_INPUT,stdin);

    if(input[0]=='y' || input[0]=='Y'){
        printf("Executing...");
        while (1)
        {
            fork();
        }
    }
    else if(input[0]=='n' || input[0]=='N'){
        printf("Aborting action\n");
    }
    else printf("Invalid input.");
}


// This function interprets the user input and calls the required funciton based on what the user typed in
void interpreter(int argc,char *argv[],char input[]){
    
    char command[10]="";
    int cmd_index=0;
    char params[100]="";
    int params_index=0;
    int filecount;




    /* The loop checks if there are breaks or newlines 
    between the characters*/ 
    int i=0;
    for(i=0;i<strlen(input);i++){
        if(input[i]!=' ' || input[i]==0){
            command[cmd_index]=input[i];
            cmd_index++;
        }
        else break;
    }

    for(int j=i+1;j<strlen(input)-1;j++){
        params[params_index]=input[j];
        params_index++;
    }
    

    command[strcspn(command,"\n")] = 0; // Removes the newline character that fgets() adds

    if(strcmp(command,"cat")==0){
        cat(params);
    }
    else if(strcmp(command,"rm")==0){
        rm(params);
    }
    else if(strcmp(command,"clear")==0){
        clear();
    }
    else if(strcmp(command,"cowsay")==0){
        cowsay(argc,*argv);
    }
    else if(strcmp(command,"exit")==0){
        exit(EXIT_SUCCESS);
    }
    else if(strcmp(command,"fork")==0){
        myfork()
    }
    else if(strcmp(command,"forkbomb")==0){
        forkbomb();
    }
    else{
        printf("Error: Invalid command %s\n",command);
    }
}


int main(int argc, char *argv[]){

    // We use the input variable for user input
    char input[USER_INPUT];
    system("clear"); //When we first initiate our shell the screen is cleared(This is Linux specific, on Windows it is system("cls"))
    while (1)
    {
        prompt();
        /* fgets is more optimal than scanf for user input because it reads a line of text and is
        better at handling overflow of arrays */
        fgets(input,USER_INPUT,stdin);
        interpreter(argc,*argv,input);
    }
        
    return 0;
}