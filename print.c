void print(char* c, int size){
	/*ssize_t write(int fd, const void *buf, size_t count);
	eax = sycall
	ebx = unsigned int fd
	ecx = const char __user *buf
	edx = size_t count
	*/
	int ret_val;
	__asm__ volatile(
			"int $0x80":
			 "=a" (ret_val): //Guarda en ret_val 
			 "a" (4), //eax: 32 bits x86 syscall for write
			 "b" (1), // ebx: stdin
			 "c" (c), //ecx: address
			 "d" (size) // edx: num of bytes
		);
	}
int main(char argc, char** argv){
	char str[] = {"Hola C!\n"}; 
	print(str,sizeof(str));
	return 0;
}
