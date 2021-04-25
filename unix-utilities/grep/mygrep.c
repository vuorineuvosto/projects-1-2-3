// LÄHTEET: https://stackoverflow.com/questions/16862096/trying-to-simulate-grep-command /

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {

    	FILE *fp;
    	char fline[100];
    	char *line = NULL;
  	size_t len = 0;

	if (argc < 2) {
      		printf("my-grep: searchterm [file ...]\n");
      		exit(1);
      		
    	} else if (argc == 2) {
    		printf("Write here the text u want to put into my-grep:\n");
    		while ((getline(&line, &len, stdin)) != -1) {
  			if (strstr(line, argv[1]) != NULL) {
  				printf("Match: %s", line);
				free(line);
			}	
  		}	
    	} else {

    		for(int i = 2; i < argc; i++){
    
        		if ((fp = fopen(argv[i], "r")) == NULL) {
            			printf("File %s could not be opened, found or whatever, errno is %d\n", argv[i], errno);
         			exit(1);
        		} 
        		while (fgets(fline, 100, fp) != NULL) {
            			if (strstr(fline, argv[1]) != NULL) {
                		printf("%s", fline);
            			}
        		}
   		}
   	}
    return 0;
}
