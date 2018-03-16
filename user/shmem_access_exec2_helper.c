#include "types.h"
#include "user.h"
#include "assert.h"
#include "param.h"

int main()
{
	char *ptr;
	int i;

	for(i = 3; i>=0; i--){
		ptr = shmem_access(i);
		if(ptr == NULL){
			test_failed();
		}

		*ptr = 'c';
	}

	test_passed();
	exit();
}
