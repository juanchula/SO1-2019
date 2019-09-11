#define _GNU_SOURCE
#include "filetools.h"
#include <getopt.h>
#include <stdlib.h>


void welcome(){
    printf( "nombre de maquina: ");
	puts(viewLine("/proc/sys/kernel/hostname", 1));
	puts(viewLine("/proc/driver/rtc", 1));
}

void kernelVersion(){
    printf("version de kernel: ");
    char *kernel = viewLine("/proc/version", 1);
    puts(kernel);
}
void printCpuInfo(){
    // printf("Tipo y modelo de CPU: ");
    char *cpu = viewLine("/proc/cpuinfo", 5);
    puts(cpu);
}

void uptime(){
    char *times = viewLine("/proc/uptime", 1);
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

int main(int argc, char **argv){
    const struct option long_options [] = {
    { "cpuInformation", 0, NULL,'c'},
    { "kernelInformation", 0, NULL, 'k'},
    {NULL, 0, NULL, 0}
    };
    int c = 0;
    int option_index = 0;

    while (c!=-1){
        c = getopt_long(argc, argv, "ck", long_options, &option_index);

        switch(c){
            case 'c':
            welcome();
            printCpuInfo();
            kernelVersion();
            uptime();
            numKernel();
            break;
            case 'k':
            //prueba();
            break;
            /* Something else: unexpected. */
            // abort ();
            }
        }
        return 0;
}