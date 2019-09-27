// #include <getopt.h>
// #include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "filetools.h"

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
        char *url, finalt[200];
        FILE *archivo;
        size_t bytes_read;

        char command[200] = "sudo cat ";
        url = detecurl(pid, "stack");
        strcat(command, url);
        system(command);
        // archivo = popen(command, "r");
        // bytes_read = fread(finalt, -1, 200, archivo);
        // FILE command;
    }

    int main(){
        limits("3014");
        char *hoa;
        hoa = detecurl("3014", "fd\0");
        puts(hoa);
        kernelstacktrace("3014");
        //printf("%s", hoa);
        return 0;
    }