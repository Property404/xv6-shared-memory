#include "assert.h"
// Shmem count should return 0 after child process accesses and exits
//

int main()
{
	void *ptr;
	int n;
	int i;

	for(i=0; i<4; i++){
		n = shmem_count(i);
		if(n!=0)test_failed();
	}

	int pid = fork();
	if(pid<0)
	{
		test_failed();
	} else if(pid == 0){
		for(i = 0; i<4; i++){
			ptr = shmem_access(i);
			if(ptr == NULL){
				test_failed();
			}
		}
		exit();
	}
	else{
		wait();
		for(i = 0; i < 4; i++){
			n = shmem_count(i);
			if (n != 0){
				test_failed();
			}
		}
	}
	test_passed();
	exit();
}

