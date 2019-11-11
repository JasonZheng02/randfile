#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

int *rand_num(){
	int fd = open("/dev/random", O_RDONLY);
	int *rand;
	read(fd, rand, sizeof(int));
	if(errno) {
		printf("%s\n", strerror(errno));
	}
	return rand;
}

int main(){
	int i;
	int arr[10];
	
	for (i = 0; i < 10; i++){
		arr[i] = *rand_num();
		printf("%d\n", arr[i]);
	}
}