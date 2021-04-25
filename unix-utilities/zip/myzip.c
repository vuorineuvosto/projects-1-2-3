#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//gcc -o myzip myzip.c -Wall -Werror

//aaabbcc --> 3a2b2c

void encode(FILE *fp, char str[]);
void write_file(FILE *fp, char count, char letter);
void file_to_zip(FILE *fp, FILE *fptozip);
void read_file(char *inputfilename);

struct term
{
	char id;
	char name;
};

int main(int argc, char **argv){
	FILE *fp;
	FILE *fptozip;
	
	if(argc == 3){
		char *outputfilename = argv[1];
		char *inputfilename = argv[2];

		if(strcmp(argv[1], "help") == 0){
			printf("Usage: $ ./myzip filetozip.txt zippedfile.z\n");
			exit(0);
		}
		if(strcmp(argv[1], "read") == 0){
			read_file(inputfilename);
			exit(0);
			
		}
		else if((fp = fopen(inputfilename, "ab")) == NULL){
			perror("No file found...");
			exit(1);
		}
		else if((fptozip = fopen(outputfilename, "r")) == NULL){
			perror("No file found...");
			exit(1);
		}
		
	
	}else{
		printf("Usage: $ ./myzip filetozip.txt zippedfile.z\n");
		exit(7);
	}
	
	
	file_to_zip(fp, fptozip);
	fclose(fp);
	fclose(fptozip);
	
	return 0;
}



void encode(FILE *fp, char str[]){
	
	char buffer[20];
	char letter = str[0];
	int count = 1;
	
	
	for(int i = 1; str[i] != '\0'; i++){
		
		if(str[i] == letter){
			count++;
		}
		else{
			
			//printf("%d%c", count, letter);
			snprintf(buffer, 12, "%d", count);
			write_file(fp, count, letter);
			letter = str[i];
			count = 1;

		}
	}

}

void write_file(FILE *fp, char count, char letter){
	
	struct term input1 = {count, letter};
	fwrite(&input1, sizeof(input1), 1, fp);

}


void read_file(char *inputfilename){
	struct term output;
	FILE *fpOut;
	if((fpOut = fopen(inputfilename, "rb")) == NULL){
		perror("fail");
		exit(1);
	}
		
	while(fread(&output, sizeof(struct term), 1, fpOut)){
        printf ("%d%c", output.id, output.name);
	}
  
    fclose (fpOut);
	    
}

void file_to_zip(FILE *fp, FILE *fptozip){

	char *line = NULL;
	size_t len = 0;


	while (getline(&line, &len, fptozip) != -1) {
        //printf("%s", line);
        encode(fp, line);
    }


	//encode(fp, str)
}
//
