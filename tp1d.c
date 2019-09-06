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

    int main(){
        limits("6038");
        char *hoa;
        hoa = detecurl("6038", "fd\0");
        puts(hoa);
        //printf("%s", hoa);
        return 0;
    }