#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define sz(container) sizeof(container)
#define el printf("\n")

void search(char *text, char *pat)
{
    for(int i = 0; i < strlen(text); i++){
        if(text[i] == pat[0]){
            char cpd [(int)1e5]= "";
            int flag = 0, pnt = 0;
            for (int j = 0; j < strlen(pat); j++)
            {
                if(text[i] == pat[j]){
                    cpd[pnt++] = text[i];
                    i++;
                }
                else break;
                if(j == strlen(pat) - 1){
                    printf("\033[0;31m");
                    printf("%s", pat);
                    printf("\033[0m");
                    flag = 1;
                }
            }
            i--;
            if(!flag) printf("%s", cpd);
        }
        else
            printf("%c", text[i]);
        
    }
}

int main(int argc, char *argv[])
{   
    char* pat = argv[1];
    for (int i = 2; i < argc; i++){
        char buffer[(int)1e5];
        FILE *fp;
        fp = fopen(argv[i], "r");
        if(fp == NULL){
            printf("grep: %s: No such file or directory\n", argv[i]);
            continue;
        }
        while(!feof(fp)){
            fgets(buffer, sz(buffer), fp);
            if(strstr(buffer, pat)){
                printf("\033[0;32m");
                printf("%s:", argv[i]);
                printf("\033[0m");
                search(buffer, pat);
            }
        }
        fclose(fp);
        el;
    }
    return 0;
}