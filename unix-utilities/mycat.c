#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 50

void tiedoston_tulostaminen(char nimi[]) {

    char merkkijono[LEN];
    FILE* fp = fopen(nimi, "r");

    if (fp == NULL) {
        perror("cannot open file\n");
        exit(1);
    }


    while (fgets(merkkijono, LEN, fp) != NULL)
        printf("%s", merkkijono);
    fclose(fp);

}

int main( int argc, char argv[]) {

    if (argc==1) {
        printf("Et antanut tiedostonimeä\n");
        exit(0);
    } else {
        char tdsto_nimi[LEN];

        for(int i = 1; i < argc; i++){
                    sprintf(tdsto_nimi,"%s",argv[i]);
                    tiedoston_tulostaminen(tdsto_nimi);
            }
    }

    return(0);
}

/ eof */
