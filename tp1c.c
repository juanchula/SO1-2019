#define _GNU_SOURCE
// #include <getopt.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
#include <stdlib.h>
#include <unistd.h>
// #include <dos.h>
#include "filetools.h"

void numberreq(){
    char r[50], w[50];
    int read, write, total;
    char* line = searchline("/proc/diskstats", "sda");
    sscanf(line, "%*s %s %*s %*s %*s %s", r, w);
    read = atoi(r);
    write = atoi(w);
    total = read + write;
    printf("peticiones a disco: %i \n", total);
}

void amountmemori(){
    char total[50], free[50];
    char* line1 = searchline("/proc/meminfo", "MemTotal:");
    char* line2 = searchline("/proc/meminfo", "MemFree:");
    sscanf(line1, "%*s %s", total);
    sscanf(line2, "%*s %s", free);
    printf("memoria disponible / total: %s / %s \n", total, free);
}

void loadaverage(){
    char time[50];
    char* line = viewLine("/proc/loadavg", 1);
    sscanf(line, "%s", time);
    printf("promedio de carga en el último minuto: %s \n", time);
}
void partc(int a, int b){
    int i = 1;
    int t = b/a;
    numberreq();
    amountmemori();
    loadaverage();
    while(i<t){
        sleep(a);
        printf("\n");
        numberreq();
        amountmemori();
        loadaverage();
        i++;
    }
}
int main(int argc, char **argv){
    // numberreq();
    // amountmemori();
    //loadaverage();
    partc(2,10);
    return 0;
}