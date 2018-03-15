#include "types.h"
#include "user.h"
#include "assert.h"
int main(int argc, char** argv)
{
	printf(1, ">fname:%s\n", argv[0]);
	/*
	void *ptr;
	ptr = shmem_access(0);
	if(ptr == NULL)
	{
		test_failed();
	}

	void *ptr2;
	while(1) {
		ptr2 = sbrk(1024);
		if(ptr2 >= ptr && ptr2 != (char*) -1){
			test_failed();
		}
		if(ptr2 == (char *) -1){
			break;
		}
	}

	test_passed();
	*/
	exit();
}
