#include "types.h"
#include "user.h"
#include "assert.h"
#include "param.h"
int main(){
	char *ptr = (char*)(USERTOP - 4096);
	*ptr = 'c';
	test_failed();
	exit();
}
