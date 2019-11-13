#include <stdio.h>
#include <stdlib.h>

#define sz(container) sizeof(container)

int main(int argc, char *argv[]){

    // Get files from the command parameters in terminal. 
    for(int i = 1; i < argc; i++){
        FILE *fp;
        char buffer[(int)1e5];

        // open the selected file to read from it.
        fp = fopen(argv[i], "r");

        // Handling if the file not found.
        if (fp == NULL) {
            printf("wcat: %s: No such file or directory\n", argv[i]);
            continue;
        }

        // printing file data
        while(fgets(buffer, sz(buffer), fp) != NULL)
            printf("%s\n", buffer);
        
        // close the file
        fclose(fp);
    }
    return 0;
}
