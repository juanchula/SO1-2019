#include "tp1a.h"
#include "tp1b.h"
#include "tp1c.h"
#include "tp1d.h"
#include <getopt.h>
#include <stdlib.h>

int main(int argc, char **argv){
    const struct option long_options [] = {
    { "puntob", 0, NULL,'s'},
    { "puntoc", 0, NULL,'l'},
    { "puntod", 0, NULL,'p'},
    {NULL, 0, NULL, 0}
    };

    int c = 0;
    int option_index = 0;
    //pa();
    //pb();
    //pc(1, 2);
    pd(*"10199");
    while (c!=-1){
        c = getopt_long(argc, argv, "slp", long_options, &option_index);

        switch(c){
            case 's':
            break;
            case 'l':
            break;
            case 'p':
            break;
        }
    }
    return 0;
}