#define _GNU_SOURCE
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void promedioCarga(int inter, int tot){
    
}

int main(int argc, char **argv){
    const struct option long_options [] = {
    { "cpuInformation", 0, NULL,'c'},
    { "kernelInformation", 0, NULL, 'k'},
    {NULL, 0, NULL, 0}
    };
    int c = 0;
    int option_index = 0;
    promedioCarga(2, 10);
    while (c!=-1){
        c = getopt_long(argc, argv, "ck", long_options, &option_index);

        switch(c){
            case 'c':
            printCpuInfo();
            kernelVersion();
            uptime();
            numKernel();
            break;
            case 'k':
            printCpuInfo();
            break;
            /* Something else: unexpected. */
            // abort ();
            }
        }
        return 0;
}