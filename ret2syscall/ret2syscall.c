#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFSIZE 100

void vuln() {
	printf("Get access to the shell!\n");
	char input[BUFSIZE];
	fgets(input, 360, stdin);
}

int main(int argc, char **argv){
	setvbuf(stdout, NULL, _IONBF, 0);
	
	// Set the gid to the effective gid
	// this prevents /bin/sh from dropping the privileges
	gid_t gid = getegid();
	setresgid(gid, gid, gid);
	
	vuln();
	printf("You failed! Better luck next time.\n");

	return 0;
}