#define _GNU_SOURCE
#include <stdio.h>
#include <pwd.h>
#include <unistd.h>

int PrintPrompt(){

	 uid_t id = geteuid();
	 struct passwd *pwd = getpwuid(id);
	 puts (pwd->pw_name);

	FILE *machineName = fopen ("/proc/sys/kernel/hostname", "rb");
	char arg[200];
	fgets(arg, 200, machineName);
	fclose(machineName);

	return 0;

}

int main(int argc, char **argv){
	PrintPrompt();
}
