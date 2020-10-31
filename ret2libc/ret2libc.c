void vuln() {
	char input[32];
	read(0, input, 64);
}

int main(int argc, char **argv){

	puts("Get access to the shell!");

	vuln();

	puts("You failed! Better luck next time.");

	return 0;
}