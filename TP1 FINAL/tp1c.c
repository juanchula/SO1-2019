#include "filetools.h"
#include "tp1c.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void numberreq(){
    char *r, *w;
    int read, write, total;
    char* line = searchline("/proc/diskstats", "sda");
    r = separatesentence(line, 2);
    w = separatesentence(line, 6);
    // sscanf(line, "%*s %s %*s %*s %*s %s", r, w);
    read = atoi(r);
    write = atoi(w);
    total = read + write;
    printf("peticiones a disco: %i \n", total);
}

void amountmemori(){
    char *total, *free;
    char* line1 = searchline("/proc/meminfo", "MemTotal:");
    char* line2 = searchline("/proc/meminfo", "MemFree:");
    total = separatesentence(line1, 2);
    free = separatesentence(line2, 2);
    printf("memoria disponible / total: %s / %s \n", total, free);
}

void loadaverage(){
    char *time;
    char* line = viewline("/proc/loadavg", 1);
    time = separatesentence(line, 1);
    printf("promedio de carga en el último minuto: %s \n", time);
}

void pc(int a, int b){
    printf("--------------------------------Punto C--------------------------------\n");
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
    printf("\n");
}


//TODO: para probar solo
// int main(int argc, char **argv){
//     numberreq();
//     amountmemori();
//     loadaverage();
//     pc(2,10);
//     return 0;
// }