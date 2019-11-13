#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define sz(container) sizeof(container)
#define el printf("\n")

int main(int argc, char *argv[]){   

    // Get the pattern to find in the files.
    char* pat = argv[1];

    // Get the files from the command parameters in the terminal.
    for (int i = 2; i < argc; i++){
        char buffer[(int)1e5];
        FILE *fp;

        // Open the file to read from it.
        fp = fopen(argv[i], "r");

        // Handling if the file not found
        if(fp == NULL){
            printf("grep: %s: No such file or directory\n", argv[i]);
            continue;
        }

        // searching in the selected file.
        while(!feof(fp)){
            fgets(buffer, sz(buffer), fp);
            if(strstr(buffer, pat))
                printf("%s", buffer);
        }

        // Close the selected file.
        fclose(fp);
    }
    return 0;
}
