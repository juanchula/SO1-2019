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
    system(command);
    // archivo = popen(command, "r");
    // bytes_read = fread(finalt, -1, 200, archivo);
    // FILE command;
}

void pd(char *pid){
    limits(pid);
    // hoa = detecurl(pid, "fd\0");
    // puts(hoa);
    kernelstacktrace(pid);
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