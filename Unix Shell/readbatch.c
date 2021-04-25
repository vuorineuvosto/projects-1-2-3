#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"processor.h"
#include"executor.h"
#include"readbatch.h"

void readbatch(char *batchFile){

    FILE *fp;
    char *line =  NULL;
    char *linetopass = NULL;
    size_t bufferSize = 0;
    char *Args[500];



    fp = fopen(batchFile, "r");
    if (fp == NULL){
        perror("cannot open file %s\n");
        exit(1);
    }
       
    while ((getline(&line, &bufferSize, fp)) != -1){
    
    	linetopass = remove_tailing(line);
        checkString(linetopass, Args);
        executeCommand(Args);
        
    } 
    
    fclose(fp);
    free(line);

}

char *remove_tailing(char *str){

      char *end;

      while(isspace((unsigned char)*str)) str++;

      if(*str == 0)
        return str;

      // Trim trailing space
      end = str + strlen(str) - 1;
      while(end > str && isspace((unsigned char)*end)) end--;

      // Write new null terminator character
      end[1] = '\0';

      return str;
}
