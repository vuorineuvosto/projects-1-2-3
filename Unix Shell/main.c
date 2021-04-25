/* Lähteet: Kurssin materiaalit, https://www.geeksforgeeks.org/making-linux-shell-c/, https://eli.thegreenplace.net/2016/basics-of-using-the-readline-library/ */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "initialize.h"
#include "parser.h"
#include "cmdhandler.h"
#include "processor.h"
#include "scanner.h"
#include "executor.h"
#include "readbatch.h"

#define MAXLETTERS 500 

int main(int argc, char* argv[]) {

	char inputString[MAXLETTERS];
    	char* Args[MAXLIST];
    	int execFlag = 0;
    	init_shell();
    	
    	if (argc == 2) { 

            char *batchFile;
            batchFile = argv[1];
            printf("%s\n", batchFile);
            readbatch(batchFile);

    	} 
        else if (argc == 1) {

    		while (1) {
    	
			printDir();
    		
			if (checkInput(inputString))
		    continue;

			execFlag = checkString(inputString, Args);
		
			if (execFlag == 1) {
	      		executeCommand(Args);
	      		}    	
    		}
    		

        } else {
        	printf("This shell takes 0 or 1 command-line arguments\n");
        }
    	return 0;
}
  

