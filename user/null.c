// Test:
// Null pointer dereference should kill process
#include "types.h"
#include "user.h"

int main()
{
	int ppid = getpid();
	int pid = fork();
	if(pid<0){
		printf(1, "TEST FAILED\n");
		exit();
	}
	else if(pid == 0){
		uint * nullp = (uint*)0;
		printf(1, "null dereference: "
				"%x, %x\n", nullp, *nullp);
		// This process should be killed
		printf(1, "TEST_FAILED\n");
		kill(ppid);
		exit();
	}
	else{
		wait();
		printf(1, "TEST PASSED\n");
		exit();
	}
}
