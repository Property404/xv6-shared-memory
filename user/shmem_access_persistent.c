#include "types.h"
#include "user.h"
#include "assert.h"
int main()
{
	char *ptr;
	int i;
	char arr[6] = "CS537";

	int pid = fork();
	if (pid < 0){
		test_failed();
	}
	else if (pid == 0){
		ptr = shmem_access(3);
		if(ptr == NULL) test_failed();

		for (i=0; i<5; i++)
		{
			*(ptr+i) = arr[i];
		}
		exit();
	}
	else{
		wait();
		ptr = shmem_access(3);
		if(ptr == NULL)
			test_failed();

		for(i=0;i<5;i++){
			if(*(ptr+i) != arr[i]){
				test_failed();
			}
		}
	}
	test_passed();
	exit();
}
