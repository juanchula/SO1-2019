#define _GNU_SOURCE
#include <stdio.h>
#include <pwd.h>
#include <unistd.h>
#include <string.h>

// void cd{

// }
int PrintPrompt(){

	 uid_t id = geteuid();
	 struct passwd *pwd = getpwuid(id);
	 char* direc = pwd->pw_dir;
	 pwd->pw_dir = strcat(direc, "/git");
	 puts(pwd->pw_dir);

	 FILE *machineName = fopen ("/proc/sys/kernel/hostname", "rb");
	 char arg[200];
	 fgets(arg, 200, machineName);
	 fclose(machineName);

	 printf("%s@%s\n",pwd->pw_name,arg);

	return 0;

}
// void directory(char *url){
//     if(-d url){
        
//     }
// }
int main(int argc, char **argv){
	PrintPrompt();
}
