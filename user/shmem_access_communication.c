// One process writing something and the other
// process reading it
#include "types.h"
#include "user.h"
#include "assert.h"
int main()
{
	char *ptr;
	int i;
	char arr[6] = "CS537";

	ptr = shmem_access(2);
	assert(ptr != NULL);

	int pid = fork();
	assert(pid >= 0);

	if(pid == 0)
	{
		sleep(20);

		for(i = 0; i < 5; i++){
			assert(*(ptr+i) == arr[i])
		}
		printf(1, "TEST PASSED\n");
	}else{
		for(i = 0; i < 5; i++){
			*(ptr+i) = arr[i];
		}
		wait();
	}

	exit();
	
}
