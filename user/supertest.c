
#include "types.h"
#include "user.h"

int main(int argc, char** argv)
{
int p;

    p = fork();
    if(p<0)
        printf(2, "Supertest fork failed"), exit();
    else if(p==0)
        printf(1, ":simple_shmem_test\n"),exec("simple_shmem_test", argv), printf(2, "Supertest exec %s failed\n", "simple_shmem_test"), exit();
    else
        wait();

    p = fork();
    if(p<0)
        printf(2, "Supertest fork failed"), exit();
    else if(p==0)
        printf(1, ":bounds\n"),exec("bounds", argv), printf(2, "Supertest exec %s failed\n", "bounds"), exit();
    else
        wait();

    p = fork();
    if(p<0)
        printf(2, "Supertest fork failed"), exit();
    else if(p==0)
        printf(1, ":null\n"),exec("null", argv), printf(2, "Supertest exec %s failed\n", "null"), exit();
    else
        wait();

    p = fork();
    if(p<0)
        printf(2, "Supertest fork failed"), exit();
    else if(p==0)
        printf(1, ":null2\n"),exec("null2", argv), printf(2, "Supertest exec %s failed\n", "null2"), exit();
    else
        wait();

    p = fork();
    if(p<0)
        printf(2, "Supertest fork failed"), exit();
    else if(p==0)
        printf(1, ":shmem_test\n"),exec("shmem_test", argv), printf(2, "Supertest exec %s failed\n", "shmem_test"), exit();
    else
        wait();

    p = fork();
    if(p<0)
        printf(2, "Supertest fork failed"), exit();
    else if(p==0)
        printf(1, ":shmem_access_return_value\n"),exec("shmem_access_return_value", argv), printf(2, "Supertest exec %s failed\n", "shmem_access_return_value"), exit();
    else
        wait();

    p = fork();
    if(p<0)
        printf(2, "Supertest fork failed"), exit();
    else if(p==0)
        printf(1, ":shmem_access_invalid_input\n"),exec("shmem_access_invalid_input", argv), printf(2, "Supertest exec %s failed\n", "shmem_access_invalid_input"), exit();
    else
        wait();

    p = fork();
    if(p<0)
        printf(2, "Supertest fork failed"), exit();
    else if(p==0)
        printf(1, ":shmem_access_double_call\n"),exec("shmem_access_double_call", argv), printf(2, "Supertest exec %s failed\n", "shmem_access_double_call"), exit();
    else
        wait();

    p = fork();
    if(p<0)
        printf(2, "Supertest fork failed"), exit();
    else if(p==0)
        printf(1, ":shmem_access_double_call_fork\n"),exec("shmem_access_double_call_fork", argv), printf(2, "Supertest exec %s failed\n", "shmem_access_double_call_fork"), exit();
    else
        wait();

    p = fork();
    if(p<0)
        printf(2, "Supertest fork failed"), exit();
    else if(p==0)
        printf(1, ":shmem_access_read_write\n"),exec("shmem_access_read_write", argv), printf(2, "Supertest exec %s failed\n", "shmem_access_read_write"), exit();
    else
        wait();

    p = fork();
    if(p<0)
        printf(2, "Supertest fork failed"), exit();
    else if(p==0)
        printf(1, ":shmem_access_communication\n"),exec("shmem_access_communication", argv), printf(2, "Supertest exec %s failed\n", "shmem_access_communication"), exit();
    else
        wait();

    p = fork();
    if(p<0)
        printf(2, "Supertest fork failed"), exit();
    else if(p==0)
        printf(1, ":shmem_access_full_address_space\n"),exec("shmem_access_full_address_space", argv), printf(2, "Supertest exec %s failed\n", "shmem_access_full_address_space"), exit();
    else
        wait();

    p = fork();
    if(p<0)
        printf(2, "Supertest fork failed"), exit();
    else if(p==0)
        printf(1, ":shmem_access_full_address_space2\n"),exec("shmem_access_full_address_space2", argv), printf(2, "Supertest exec %s failed\n", "shmem_access_full_address_space2"), exit();
    else
        wait();

    p = fork();
    if(p<0)
        printf(2, "Supertest fork failed"), exit();
    else if(p==0)
        printf(1, ":shmem_access_persistent\n"),exec("shmem_access_persistent", argv), printf(2, "Supertest exec %s failed\n", "shmem_access_persistent"), exit();
    else
        wait();

    p = fork();
    if(p<0)
        printf(2, "Supertest fork failed"), exit();
    else if(p==0)
        printf(1, ":shmem_access_exec\n"),exec("shmem_access_exec", argv), printf(2, "Supertest exec %s failed\n", "shmem_access_exec"), exit();
    else
        wait();

    p = fork();
    if(p<0)
        printf(2, "Supertest fork failed"), exit();
    else if(p==0)
        printf(1, ":shmem_access_exec2\n"),exec("shmem_access_exec2", argv), printf(2, "Supertest exec %s failed\n", "shmem_access_exec2"), exit();
    else
        wait();
exit();}