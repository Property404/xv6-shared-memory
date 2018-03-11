#include "types.h"
#include "user.h"
#include "assert.h"

int main()
{
	void *ptr;
	void *ptr2;

	ptr = shmem_access(3);
	assert(ptr != NULL);

	ptr2 = shmem_access(3);
	assert(ptr2 != NULL);

	assert(ptr == ptr2);

	printf(1, "TEST PASSED\n");
	exit();
}
