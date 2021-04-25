#include <stdio.h>
#include <stdlib.h>
#include <string.h>
			//input file, output file
void readFile(char *x, char *y);
			//array of all lines, array lenght, output file
void reversePrint(char **allLines, int i, char *y);

int main(int argc, char **argv){

	//TODO: custom input/output name
	//		argv[1] == argv[2]

	char *inputFile, *outputFile;

	if(argc > 3){				//too many commanline
		fprintf(stderr, "usage: reverse <input> <output>\n");
		exit(1);
	}
	else if(argc == 1){			//no commandline arguments
		inputFile = "big.txt";
		outputFile = "defaultoutput.txt";
	}
	else if(argc == 2){			//only input file given as commandline argument
		inputFile = argv[1];
		outputFile = "defaultOutput.txt";
	}
	else {						//both given as commanline arguments
		inputFile = argv[1];
		outputFile = argv[2];
	}

	readFile(inputFile, outputFile);
	return 0;
}

//https://aticleworld.com/remove-trailing-newline-character-from-fgets/
void readFile(char *x, char *y){

	FILE * fPointer;
	char **allLines;
	int i = 0;

	//"/home/setit/Desktop/test2.txt"
	fPointer = fopen(x, "r");

	if(fPointer == NULL){
		fprintf(stderr, "error: cannot open file '%s'.\n", x);
		exit(1);
	}
	else{
		//read the amount of lines in the file for dynamic array.
		char c;
		int lineCount = 0;
		int longestLine = 0;
		int charCount = 0;
		for(c = getc(fPointer); c != EOF; c = getc(fPointer)){
			charCount = charCount + 1;
			if (c == '\n'){
				if(charCount > longestLine){
					longestLine = charCount;
				}
				charCount = 0;
				lineCount = lineCount + 1;
			}
			

		}
		//printf("%d longestLine\n", longestLine);
		rewind(fPointer); //rewind the pointer back to the start of the file
		
		//https://stackoverflow.com/questions/23427883/storing-the-buffer-of-fgets-in-array/23428556
		allLines = (char**)malloc(lineCount * sizeof(char *));
		if(allLines == NULL){
			fprintf(stderr, "Memory allocation failed!\n");
			exit(1);
		}
		
		char oneLine[longestLine];
		//printf("\n\nFile before reversing:\n\n");

		longestLine = longestLine + 1;
		while(fgets(oneLine, longestLine, fPointer) != NULL){ //read file line by line, each line is stored to 'oneLine' -buffer
			allLines[i] = strndup(oneLine, longestLine);
			i++;
			//printf("%s", oneLine); //prints file read.
		}									
		
		fclose(fPointer);

	}
	reversePrint(allLines, i, y);
	i -= 1;
	for(; i>-1; i--){	
		free(allLines[i]);
		allLines[i] = NULL;
	}
	free(allLines);
	allLines = NULL;

}
				//array of lines, lenght of the array, name of the output file
void reversePrint(char **allLines, int i, char *y){
	//printf("\n\nReversed file:\n\n");

	FILE *fOutPut = fopen(y, "w");
	
	if(fOutPut == NULL){
		fprintf(stderr, "Failed to create file called: %s\n", y);
		exit(1);
	}
	
	i -= 1;
	for(; i>-1; i--){
		//printf("%s", allLines[i]);	//prints reversed version to be printed.
		fprintf(fOutPut, "%s", allLines[i]);
	}
	
	fclose(fOutPut);	
}

//eof :D
