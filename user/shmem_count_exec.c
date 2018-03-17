#include "assert.h"
char *args[] = {"echo", 0};

int main(int argc, char*argv[])
{
	void *ptr;
	int n;
	int i;

	for(i=0; i<4; i++){
		ptr = shmem_access(i);
		if(ptr == NULL){
			test_failed();
		}
	}

	int pid = fork();
	if(pid< 0){
		test_failed();
	}
	else if(pid == 0){
		for(int i = 0; i <4; i++){
			n = shmem_count(i);
			if(n!=2)test_failed();
		}
		exec("echo", args);
		printf(1, "exec failed\n");
		test_failed();
		exit();
	}
	else{
		wait();
	}
	test_passed();
	exit();
}
