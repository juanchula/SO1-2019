#include "filetools.h"
#include <getopt.h>
#include <stdlib.h>

void timeCpu(){
    char user[20];
    char sys[20];
    char idle[20];
    int i = 0;
    int space = 0;
    int j = 0;
    int cond = 1;

    char *tot = viewLine("/proc/stat", 1);

    while(cond){
        if(tot[i-1] == ' '){
            space++;
            j = 0;
        }
        if(tot[i] != ' '){
             switch(space){
                case 2:
                    user[j] = tot[i];
                    user[j+1] = '\0';
                    j++;
                    break;
                case 4:
                    sys[j] = tot[i];
                    sys[j+1] = '\0';
                    j++;
                    break;
                case 5:
                    idle[j] = tot[i];
                    idle[j+1] = '\0';
                    j++;
                    break;
                case 6:
                    cond = 0;
                    break;
            }
        }
        i++;
    }
    printf("cantidad de tiempo de CPU utilizado por el usuario %s, por el systema %s y por el proceso idle %s \n", user, sys, idle);
    // puts(tot);
    // puts(user);
    // puts(sys);
    // puts(idle);
}

void contextc(){
    int cond = 1;
    int space = 0;
    int i = 0;
    int j = 0;
    char time[20];
    char *tot = searchline("/proc/stat", "ctxt");

    while(cond){
        if(tot[i-1] == ' '){
            space++;
            j = 0;
        }
        if(tot[i] != ' ' && space){
            time[j] = tot[i];
            j++;
            if(time[i] == '\0')
                break;
        }
        i++;
    }
    printf("cantidad de cambios de contexto %s \n", time);
}

void processes(){
    int cond = 1;
    int space = 0;
    int i = 0;
    int j = 0;
    char proc[20];
    char *tot = searchline("/proc/stat", "processes");

    while(cond){
        if(tot[i-1] == ' '){
            space++;
            j = 0;
        }
        if(tot[i] != ' ' && space){
            proc[j] = tot[i];
            j++;
            if(proc[i] == '\0')
                break;
        }
        i++;
    }
    printf("número de procesos creados desde el inicio del sistema %s \n", proc);
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
            timeCpu();
            contextc();
            processes();
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