// Shmem_count should return 2 after fork if the parent process has accessed a shared page

#include "assert.h"

int main(){
	void *ptr;
	int n;

	for(int i=0;i<4;i++){
		ptr = shmem_access(i);
		if(ptr == NULL){
			test_failed();
		}
	}

	int pid = fork();
	if(pid<0){
		test_failed();
	}else if(pid == 0){
		for(int i = 0; i < 4; i++){
			n = shmem_count(i);
			if(n != 2){
				test_failed();
			}
		}
		exit();
	}
	else{
		wait();
	}
	test_passed();
	exit();
}

