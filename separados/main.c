#include "tp1a.h"
#include "tp1b.h"
#include "tp1c.h"
#include "tp1d.h"
#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv){
    const struct option long_options [] = {
    { "puntob", 0, NULL,'s'},
    { "puntoc", 0, NULL,'l'},
    { "puntod", 0, NULL,'p'},
    {NULL, 0, NULL, 0}
    };

    int c = 0;
    int option_index = 0;
    unsigned int *a=&(unsigned int){0}, *b=&(unsigned int){0}, *pid=&(unsigned int){0};
    //pa();
    //pb();
    //pc(1, 2);
    //pd("10199");
    while (c!=-1){
        c = getopt_long(argc, argv, "slp", long_options, &option_index);

        switch(c){
            case 's':
            break;
            case 'l':
            sscanf(argv[2], "%u", a);
			sscanf(argv[3], "%u", b);
			pc(*a, *b);
            break;
            case 'p':
            break;
        }
    }
    return 0;
}