#include <stdio.h>
#include <string.h>
#include "cmdhandler.h"
#include "parser.h"
  
// functio, joka parsii komentosanat
void parseSpace(char* inputstr, char** parsed) {
    int i;
  
    for (i = 0; i < MAXLIST; i++) {
        parsed[i] = strsep(&inputstr, " ");
  
        if (parsed[i] == NULL){
            break;
        }
        if (strlen(parsed[i]) == 0){
            i--;
        }
    }
}
