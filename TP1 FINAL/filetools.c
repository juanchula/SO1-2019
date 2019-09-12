#include <stdio.h>
#include <string.h>
#include "filetools.h"


char* separatesentence(char *line, int num){
    int i = 1, j = 0, word = 1, condgeneral = 1, cond = 1;
    char sentence[200];
    while(condgeneral){
        if(line[i] != ' ' && line[i] != '\n'){
            if(!cond){
                cond = 1;
                word++;
            }
            if(word == num){
                sentence[j] = line[i];
                j++;
            }
        } else{
            cond = 0;
        }
        i++;
        if(word > num){
            condgeneral = 0;
        }
    }
    sentence[j] = '\0';
    return strdup(sentence);
}


char* linebreak(char* text){
    int cond = 1;
    int i = 0;
    char finalt[500];
    while(cond || i>500){
        if(text[i+1] == '\n'){
            cond = 0;
            finalt[i+1] = '\0';
        }
        finalt[i] = text[i];
        i++;
    }
    finalt[i] = '\0';
    return strdup(finalt);
}

char* viewline(char* file, int line){
    //TODO: Controlar que salga todo completo puesto que se esta comiendo parte
    FILE *fileopen = fopen(file, "rb");
    char arg[500];
    char finalt[500];
    int i = 1;
    int j = 0;
    int cond = 1;
    while(fgets(arg, 500, fileopen)){
        if(i == line){
           while(cond){
                finalt[j] = arg[j];
                if(arg[j+1] == '\n'){
                    finalt[j+1] = '\0';
                    cond = 0;
                }
                j++;
            }
        }
        i++;
    }
    fclose(fileopen);
    //TODO: para probar: puts(final);
    return strdup(finalt);
}

char* searchline(char* file, char* word){
    FILE *fileopen = fopen(file, "rb");
    char arg[500];
    char *sfinal = NULL;
    while(fgets(arg, 500, fileopen)){
        sfinal = strstr(arg, word);
        if(sfinal != NULL)
            break;
    }
    fclose(fileopen);
    char *finalt = linebreak(sfinal);
    return finalt;
}