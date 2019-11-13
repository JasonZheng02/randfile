#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

int rand_num(){
	int fd, buff;
	fd = open("/dev/urandom", O_RDONLY);
	read(fd, &buff, sizeof(int));
	if(fd < 0) {
		printf("%s\n", strerror(errno));
	}
	close(fd);
	return buff;
}

int main(){
	int i, arr[10], arr2[10], fd, fd2;
	
	printf("Generating random numbers\n");
	for (i = 0; i < 10; i++){
		arr[i] = rand_num();
		printf("random %d: %d\n", i, arr[i]);
	}
	
	printf("Writing numbers to file\n");
	fd = open("file", O_RDWR | O_CREAT, 0666);
	write(fd, arr, sizeof(arr));
	close(fd);
	
	printf("Reading numbers from file\n");
	fd2 = open("file", O_RDONLY);
	read(fd2, arr2, sizeof(arr2));
	close(fd2);
	
	printf("Verification that written values were the same\n");
	for (i = 0; i < 10; i++){
		printf("random %d: %d\n", i, arr2[i]);
	}
}