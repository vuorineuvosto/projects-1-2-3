// LÄHTEET: https://pubs.opengroup.org/onlinepubs/007904875/functions/open.html

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>


void executeCommand(char** parsed) {
    // Forking a child
    printf("\n");
    pid_t pid = fork(); 
  
    if (pid == -1) {
        printf("\nFailed forking child..");
        return;
    } else if (pid == 0) {

		//missä ">" sijaitsee listassa
		int j = 0;
		int pos = 2;
		for(; parsed[j] != NULL; j++){
		    if(strcmp(parsed[j], ">") == 0){
		        pos = j;
		    }
		}

		//redirect
		if ((j > 2) && (strcmp(parsed[pos], ">")) == 0){

		    char *outputFile;
		    char redir[100] = "";
		    outputFile = parsed[pos+1];

		    //komennon luominen
		    for(int k = 0; k < pos; k++){
		        
		        strcat(redir, parsed[k]);
		        strcat(redir, " ");
		    }

		    if (fork() == 0) {
		        // child
		        int fd = open(outputFile, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

		        dup2(fd, 1);   
		        dup2(fd, 2);   
		                       
		        close(fd);     
		        system(redir);
		        wait(NULL); 
		    }
		    wait(NULL); 
			//redirect end
		}else{
		    if (execvp(parsed[0], parsed) < 0) {
		        printf("\nCould not execute command: %s", parsed[0]);
		    }
		}
        	exit(0);
    } else {
        // waiting for child to terminate
        wait(NULL); 
        return;
    }
}
