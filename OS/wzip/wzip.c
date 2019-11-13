#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define sz(container) sizeof(container)

int main(int argc, char *argv[]){

    // Get the files from the command parameters in the terminal.
    for (int i = 1; i < argc; i++){
        FILE *fp;

        // Open the file to read from it.
        fp = fopen(argv[i], "r");

        // Handling if the file not found
        if(fp == NULL){
            printf("wzip: %s: No such file or directory\n", argv[i]);
            continue;
        }

        // Zipping the selected file
        while(!feof(fp)){
            char buffer[(int)1e5];
            fgets(buffer, sz(buffer), fp);

            int cnt = 1; // Counter for the repeated characters
            for (int j = 0; j < strlen(buffer)-1; j++){
                while(buffer[j+1] == buffer[j]) j++, cnt++;
                
                if(cnt > 1){

                    // if true means that it's a special character from those: \ ( ) 
                    // Otherwise it's a normal charcter
                    (buffer[j] == '(' || buffer[j] == ')' || buffer[j] == '\\') ? printf("(%d)\\%c", cnt, buffer[j]) : printf("(%d)%c", cnt, buffer[j]);
                    
                    // Reset the counter
                    cnt = 1;
                }
                // The same in the if statement but for one character
                else (buffer[j] == '(' || buffer[j] == ')' || buffer[j] == '\\') ? printf("\\%c", buffer[j]) : printf("%c", buffer[j]);
            }
        }
        // Close the file
        fclose(fp);
    }
    return 0;
}