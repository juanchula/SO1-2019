#define _GNU_SOURCE
#include <stdio.h>
#include <pwd.h>
#include <unistd.h>

int PrintPrompt(){
	 uid_t id = geteuid();
	 struct passwd *pwd = getpwuid(id);

	 FILE *machineName = fopen ("/proc/sys/kernel/hostname", "rb");
	 char arg[200];
	 fgets(arg, 200, machineName);
	 fclose(machineName);

	 printf("%s@%s\n",pwd->pw_name,arg);
	 

	return 0;
}

int main(int argc, char **argv)
{
	PrintPrompt();
}
