
#include "types.h"
#include "user.h"

int main(int argc, char** argv)
{
int p;

    p = fork();
    if(p<0)
        printf(2, "Supertest fork failed"), exit();
    else if(p==0)
        exec("null", argv), printf(2, "Supertest exec %s failed\n", "null"), exit();
    else
        wait();

    p = fork();
    if(p<0)
        printf(2, "Supertest fork failed"), exit();
    else if(p==0)
        exec("null2", argv), printf(2, "Supertest exec %s failed\n", "null2"), exit();
    else
        wait();
exit();}