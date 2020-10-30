all:
	gcc -w -m32 -fno-stack-protector -no-pie -Wl,-z,relro,-z,now -o ret2libc ret2libc.c

clean:
	rm ret2libc