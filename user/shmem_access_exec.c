#include "types.h"
#include "user.h"
#include "assert.h"
char *args[]= {"shmem_access_exec_helper", 0};

int main()
{
	void *ptr;
	int i;

	for(i = 0; i < 4; i++){
		ptr = shmem_access(i);
		if(ptr == NULL){
			test_failed();
		}
	}

	int pid = fork();
	if (pid < 0){
		test_failed();
	}
	else if(pid == 0){
		exec("shmem_access_exec_helper", args);
		printf(1, "exec failed!\n");
		test_failed();
		exit();
	}
	else {
		wait();
	}
	test_passed();
	exit();
}

