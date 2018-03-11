#include "types.h"
#include "user.h"
#include "assert.h"
int main(int argc, char* argv[])
{
	void *ptr;
	int invalid_inputs[] = {-1, -100, 4, 100, NULL};

	for(int i=0; invalid_inputs[i] != NULL;i++)
	{
		ptr = shmem_access(
				invalid_inputs[i]); 
		assert(ptr == NULL);
	}
	printf(1, "TEST PASSED\n");
	exit();
}


