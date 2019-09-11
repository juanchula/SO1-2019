#include "filetools.h"
#include "tp1a.h"
#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void welcome(){
    printf( "nombre de maquina: ");
	puts(viewline("/proc/sys/kernel/hostname", 1));
	puts(viewline("/proc/driver/rtc", 1));
}

void kernelVersion(){
    printf("version de kernel: ");
    char *kernel = viewline("/proc/version", 1);
    puts(kernel);
}
void printCpuInfo(){
    // printf("Tipo y modelo de CPU: ");
    char *cpu = viewline("/proc/cpuinfo", 5);
    puts(cpu);
}

void uptime(){
    char *times = viewline("/proc/uptime", 1);
    char time[100];
    int i = 0;
    int cond = 1;
    while(cond){
        time[i] = times[i];
        if(times[i+1] == ' '){
            cond = 0;
        }
        i++;
    }
    char *end;
    int t = atoi(time);
    //double t = strtod(time, &end);
    int dd= t/86400;
    t = t%86400;
    int hh = t/3600;
    t = t % 3600;
    int mm = t/60;
    int ss = t%60;
    printf("tiempo transcurrido: %02d %02d:%02d:%02d \n",dd, hh, mm, ss);
}

void numKernel(){
    FILE *filesystems = fopen("/proc/filesystems", "rb");
    char arg[200];
    int num = 0;
    while(fgets(arg, 200, filesystems)){
        num++;
    }
    fclose(filesystems);
    printf("cantidad de sistemas de archivos soportados por el kernel: %i \n", num);
}

void pa(){
    welcome();
    printCpuInfo();
    kernelVersion();
    uptime();
    numKernel();
}