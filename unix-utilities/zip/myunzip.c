#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//gcc -o myunzip myunzip.c -Wall -Werror

void read_file(char *outputfilename, char *inputfilename);
void unzip(FILE *fpOut, char id, char name);

struct term
{
	char id;
	char name;
};

int main(int argc, char **argv){
	if(argc == 3){
		
			char *outputfilename = argv[argc-1];
			char *inputfilename = argv[1];
			read_file(outputfilename, inputfilename);
	
	}else{
		
		printf("Usage: $ ./myunzip zippedfile.z destination.txt\n");
	}
	

	
	return 0;
}

void read_file(char *outputfilename, char *inputfilename){
	struct term output;
	FILE *fpIn;
	if((fpIn = fopen(inputfilename, "rb")) == NULL){
		perror("fail");
		exit(1);
	}
	FILE *fpOut;
	if((fpOut = fopen(outputfilename, "w")) == NULL){
		perror("fail");
		exit(1);
	}
		//fprintf(fpOut, "\n");
	while(fread(&output, sizeof(struct term), 1, fpIn)){
		
        unzip(fpOut, output.id, output.name);
        
	}
  
    fclose (fpIn);
	
         
}
void unzip(FILE *fpOut, char id, char name){
	//aaabbdddddd fkkfk
	//3a2b6d1 1f2k1f1k
	// 6 -> 5 ... 1 -> 0
	for(; id>0; id--){
		//printf("%c", name);
		fprintf(fpOut, "%c", name);
	}
	//fprintf(fpOut, "\n");


}
//
