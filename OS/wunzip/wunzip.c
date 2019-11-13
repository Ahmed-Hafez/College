#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define sz(container) sizeof(container)
#define el printf("\n")

int main(int argc, char *argv[]){   

    // Get the files from the command parameters in the terminal.
    for (int i = 1; i < argc; i++){
        char buffer[(int)1e5];
        FILE *fp;

        // Open the file to read from it.
        fp = fopen(argv[i], "r");

        // Handling if the file not found.
        if(fp == NULL){
            printf("wunzip: %s: No such file or directory\n", argv[i]);
            continue;
        }

        // Unzipping the selected file
        while(!feof(fp)){
            fgets(buffer, sz(buffer), fp);

            // the pattern of the zipped data will be like that:
            // (3)a(2)hbre(2)b (23)2\(4343\)\\343\\c\\\(\)(5)a 
            // which should be converted to:
            // aaahhbrebb 22222222222222222222222(4343)\343\c\()aaaaa
            for (int j = 0; j < strlen(buffer)-1; j++){

                // unzip the zipped data
                if(buffer[j] == '('){
                    int n = 0;
                    j++;
                    while(isdigit(buffer[j])){
                        n = n * 10 + (buffer[j] - '0');
                        j++;
                    }
                    j++;
                    for (int k = 0; k < n; k++) printf("%c", buffer[j]);
                }

                // Handle my special characters which are: \ ( )  
                else if(buffer[j] == '\\'){
                    j++;
                    printf("%c", buffer[j]);
                }

                // normal data
                else printf("%c", buffer[j]);
            }
        }

        // Close the selected file.
        fclose(fp);
    }
    return 0;
}
