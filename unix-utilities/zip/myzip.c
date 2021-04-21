#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//gcc -o myzip myzip.c -Wall -Werror

//aaabbcc --> 3a2b2c

void encode(FILE *fp, FILE* filetozip, char str[]);
void write_file(FILE *fp, char count, char letter);
void read_file();

struct term
{
	char id;
	char name;
};

int main(int argc, char **argv){
	FILE *fp;
	FILE *fptozip;
	
	if(argc > 1){
		char *outputfilename = argv[argc-1];
		char *inputfilename = argv[1];

		if(strcmp(argv[1], "help") == 0){
			printf("Usage: $ ./myzip filetozip.txt zippedfile.z\n");
			exit(0);
		}
		if((fp = fopen(inputfilename, "wb")) == NULL){
			perror("fail");
			exit(1);
		}
		if((fptozip = fopen(outputfilename, "w")) == NULL){
			perror("fail");
			exit(1);
		}
	
	}else{
				//DESTINATION FILE
		if((fp = fopen("encoded.z", "wb")) == NULL){
			perror("fail");
			exit(1);
		}
		if((fptozip = fopen("encoded.txt", "wb")) == NULL){
			perror("fail");
			exit(1);
		}
	}
	char str[] = "aaabbdddddd fkkfk 53 jannea 66.5 kertaa:D\n";

	encode(fp, fptozip, str);
	fclose(fp);
	//read_file();
	fclose(fptozip);
	
	return 0;
}



void encode(FILE *fp, FILE *filetozip, char str[]){
	
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
	
	//printf("%d%c", count, letter);
	
	
	printf("Encode loppu.\n");

}

void write_file(FILE *fp, char count, char letter){
	
	struct term input1 = {count, letter};
	fwrite(&input1, sizeof(input1), 1, fp);

}


void read_file(){
	struct term output;
	FILE *fpOut;
	if((fpOut = fopen("encoded.z", "rb")) == NULL){
		perror("fail");
		exit(1);
	}
		
	while(fread(&output, sizeof(struct term), 1, fpOut)){
        printf ("%d%c", output.id, output.name);
	}
  
    fclose (fpOut);
	    
}
