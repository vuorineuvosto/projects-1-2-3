#include<stdio.h>
#include<unistd.h>
#include"parser.h"
#include"cmdhandler.h"

int checkString(char* inputstr, char** parsed) {
  

   parseSpace(inputstr, parsed);
  
    if (cmdHandler(parsed))
        return 0;
    else
        return 1;
}
