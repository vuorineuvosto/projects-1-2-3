// LÄHTEET: https://stackoverflow.com/questions/16862096/trying-to-simulate-grep-command /

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char fline[100];

    if (argc < 3) {
      printf("Not enough command line parameters given!\n");
      exit(1);
    } 

    for(int i = 2; i < argc; i++){


        if ((fp = fopen(argv[i], "r")) == NULL) {
            printf("File could not be opened, found or whatever, errno is %d\n",errno);
            exit(1);
        } 

        while (fgets(fline, 100, fp) != NULL) {
            if (strstr(fline, argv[1]) != NULL) {
                printf("%s", fline);
            }
        }
    }
    return 0;
}
