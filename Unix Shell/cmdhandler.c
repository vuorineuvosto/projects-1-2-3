#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include"cmdhandler.h"
#include"initialize.h"

int cmdHandler(char** parsed) {

    	int builtInCmds = 4, i, switchArg = 0;
    	char* ListOfOwnCmds[builtInCmds];
  
	ListOfOwnCmds[0] = "exit";
    	ListOfOwnCmds[1] = "cd";
    	ListOfOwnCmds[2] = "path";
    	ListOfOwnCmds[3] = "help";
  
    	for (i = 0; i < builtInCmds; i++) {
        	if (strcmp(parsed[0], ListOfOwnCmds[i]) == 0) {
            	switchArg= i + 1;
            	break;
        	}
    	}
  
    	switch (switchArg) {
    	case 1:
        	printf("\nThank you for using the wish shell\n");
        	exit(0);
    	case 2:
    		if (parsed[1] == NULL) {
    			chdir(getenv("HOME"));
    			printf("I built this \n");
    			return 1;
    		} else {
    			chdir(parsed[1]);
        		printf("I built this\n");
        		return 1;
    		}   	
   	case 3:
        	chdir(parsed[1]);
        	printf("I built this\n");	
        	return 1;
   	case 4:
        	openHelp();
        	return 1;  
    	default:
        	break;
    	}
  
    	return 0;
}
