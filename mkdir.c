#include <stdio.h>

int mkdir(char* pathname){
	int ret_val;
	/* int mkdir(const char *pathname, mode_t mode);
		eax: syscall id 0x27
		ebx: *pathname
		ecx: mode
	*/
	__asm__ volatile
		(
		"int $0x80":
		"=a" (ret_val):
		"a" (0x27),
		"b" (pathname),
		"c" (0x1ef)
		);
	printf("Directorio: %s creado!\n", pathname);
	return ret_val;
	}

int main(char argc, char **argv){
	mkdir(argv[1]);
	return 0;
	}
