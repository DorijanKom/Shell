#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    char input[1024];
    fgets(input, 1024, stdin);
    cowsay(input);

}





void cowsay(char output[1024]){


    char *line1 = "   \ \n";
    char *line2 = "    \ \n";
    char *line3 = "        .--. \n";
    char *line4 = "       |o_o | \n";
    char *line5 = "       |:_/ | \n";
    char *line6 = "      //   \ \ \n";
    char *line7 = "     (|     | ) \n";
    char *line8 = "    /'\_   _/`\ \n";
    char *line9 = "    \___)=(___/ \n";

    printf("%s", output);
    printf(line1);
    printf(line2);
    printf(line3);
    printf(line4);
    printf(line5);
    printf(line6);
    printf(line7);
    printf(line8);
    printf(line9);


}

