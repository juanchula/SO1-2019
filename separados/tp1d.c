#include "filetools.h"
#include "tp1d.h"
// #include <getopt.h>
// #include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* detecurl(char *pid, char *last){
    char finalt[200] = "/proc/";
    //finalt = "/proc/";
    strcat(finalt, pid);
    strcat(finalt, "/");
    strcat(finalt, last);
    return strdup(finalt);
}

void limits(char *pid){
    char line1[50], line2[50], *url, *line;
    url = detecurl(pid, "limits");
    line = (searchline(url, "Max open files"));
    sscanf(line, "%*s %*s %*s %s %s", line1, line2);
    puts(line1);
}

void kernelstacktrace(char *pid){
    char *url;
    // char finalt[200];
    // FILE *archivo;
    // size_t bytes_read;

    char command[200] = "sudo cat ";
    url = detecurl(pid, "stack");
    strcat(command, url);
    //system(command);
    FILE *data = popen(command, "r");
    char arg [200];
    while(fgets(arg, 200, data)){
        printf("%s", arg);
    }
    // archivo = popen(command, "r");
    // bytes_read = fread(finalt, -1, 200, archivo);
    // FILE command;
}

void filedescriptor( char *pid){
    int cond = 0;
    char permision[50], typefile[50], namefile[50], direcctionfile[50];
    char *url;
    char command[200] = "ls -l ";
    url = detecurl(pid, "fd");
    strcat(command, url);
    //system(command);
    FILE *data = popen(command, "r");
    char arg [200];
    while(fgets(arg, 200, data)){
        if(cond){
            sscanf(arg, "%s %s %*s %*s %*s %*s %*s %*s %s %*s %s", permision, typefile, namefile, direcctionfile);
            printf("%s %s %s -> %s\n", permision, typefile, namefile, direcctionfile);
        }
        cond++;
    }
}
void pd(char *pid){
    printf("-----------------------Punto D-----------------------\n");
    limits(pid);
    // hoa = detecurl(pid, "fd\0");
    // puts(hoa);
    kernelstacktrace(pid);
    filedescriptor(pid);
    printf("\n");
}

//TODO: para probar solo
// int main(){
//     char pidof[10] = "10199\0";
//     limits(pidof);
//     char *hoa;
//     hoa = detecurl(pidof, "fd\0");
//     puts(hoa);
//     kernelstacktrace(pidof);
//     //printf("%s", hoa);
//     return 0;
//     }