#include <stdio.h>
#include <string.h>

char* viewLine(char* file, int line){
    //TODO: Controlar que salga todo completo puesto que se esta comiendo parte
    FILE *fileopen = fopen(file, "rb");
    char arg[500];
    char final[500];
    int i = 1;
    int j = 0;
    int cond = 1;
    while(fgets(arg, 500, fileopen)){
        if(i == line){
           while(cond){
                final[j] = arg[j];
                if(arg[j+1] == '\n'){
                    cond = 0;
                }
                j++;
            }
        }
        i++;
    }
    fclose(fileopen);
    //TODO: para probar: puts(final);
    return strdup(final);
}