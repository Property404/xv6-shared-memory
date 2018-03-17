#include "assert.h"
// shmem_count should return 1 after 2 accesses to the same page
//

int main(int argc, char*argv[]){
	void *ptr;
	int n;

	for(int i=0; i<4; i++){
		ptr = shmem_access(i);
		if(ptr == NULL)test_failed();
		ptr = shmem_access(i);
		if(ptr == NULL)test_failed();
		n = shmem_count(i);
		if(n!=1)test_failed();
	}
	test_passed();
	exit();
}


