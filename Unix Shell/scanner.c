#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "initialize.h"

int checkInput(char* str) { 
    	char* buf;
  
    	buf = readline("Wish> ");
    	if (strlen(buf) != 0) {
        	add_history(buf);
        	strcpy(str, buf);
        	return 0;
    	} else {
        	return 1;
    	}
}

