#include<stdio.h>
#include<unistd.h>
#include"initialize.h"

void init_shell() {
    clear();
}

void printDir() {
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("\n%s ", cwd);
}

void openHelp() {
	
	puts("\n***WELCOME TO THE HELP OF WISH***"
        "\nList of built-in commands supported:"
        "\n>exit"
        "\n>cd"
        "\n>path"
        "\n>help"
        "\n>redirecting"
        "\n>all other general commands available in UNIX shells"); 
    return;

}
