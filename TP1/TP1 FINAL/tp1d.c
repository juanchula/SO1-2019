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
    char *line1, *line2, *url, *line;
    url = detecurl(pid, "limits");
    line = (searchline(url, "Max open files"));
    line1 = separatesentence(line, 4);
    line2 = separatesentence(line, 5);
    printf("SoftLimit: %s, HardLimit: %s \n", line1, line2);
    // puts(line1);
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
    char *permision, *typefile, *namefile, *direcctionfile;
    char *url;
    char command[200] = "ls -l ";
    url = detecurl(pid, "fd");
    strcat(command, url);
    //system(command);
    FILE *data = popen(command, "r");
    char arg [200];
    while(fgets(arg, 200, data)){
        if(cond){
            permision = separatesentence(arg, 1);
            typefile = separatesentence(arg, 2);
            namefile = separatesentence(arg, 9);
            direcctionfile = separatesentence(arg, 11);
            printf("%s %s %s -> %s\n", permision, typefile, namefile, direcctionfile);
        }
        cond++;
    }
}

void pdp(char *pid){
    printf("-----------------------Punto D (FileDescriptors)-----------------------\n");
    filedescriptor(pid);
    printf("\n");
}

void pdf(char *pid){
    printf("----------------------------Punto D (Limits)---------------------------\n");
    limits(pid);
    printf("\n");
}


void pdt(char *pid){
    printf("----------------------Punto D (KernelStackTrace)-----------------------\n");
    kernelstacktrace(pid);
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