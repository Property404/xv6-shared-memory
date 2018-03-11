#include "types.h"
#include "user.h"
#include "assert.h"

int main()
{
	void *ptr;

	ptr = shmem_access(3);
	assert(ptr != NULL);

	int pid = fork();
	assert(pid >= 0);

	if(pid == 0)
	{
		void *ptr2;

		ptr2 = shmem_access(3);
		assert(ptr2 != NULL);

		assert(ptr == ptr2);

		exit();
	}
	else{
		wait();
	}

	printf(1, "TEST PASSED\n");
	exit();
}



