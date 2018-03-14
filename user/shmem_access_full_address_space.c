#include "types.h"
#include "user.h"
#include "assert.h"

int main()
{
	void *ptr;
	while(1){
		ptr = sbrk(1024);
		if(ptr == (char*) -1){
			break;
		}
	}

	ptr = shmem_access(0);
	if (ptr != NULL)
	{
		printf(2, "TEST FAILED\n");
	}

	printf(1, "TEST PASSED\n");
	exit();
}
