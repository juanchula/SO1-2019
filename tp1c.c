#define _GNU_SOURCE
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filetools.h"

void numberreq(){
    char r[50], w[50];
    char* line = searchline("/proc/diskstats", "sda");
    puts(line);
    sscanf(line, "%*s %s %*s %*s %*s %s", r, w);
    puts(r);
    puts(w);
}
void promedioCarga(int inter, int tot){
    
}

int main(int argc, char **argv){
    numberreq();
    return 0;
}