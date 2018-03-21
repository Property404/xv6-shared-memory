#!/usr/bin/env python3
# Make a "super" test that runs all tests

TESTS = [];
with open("../user/makefile.mk", "r") as f:
    contents = f.read().replace("\\","");
    contents = contents[contents.find("wc"):contents.find("zombie")]
    TESTS = contents.split()[1::];

source = """
#include "types.h"
#include "user.h"

int main(int argc, char** argv)
{
int p;
"""

for t in TESTS:
    source += f"""
    p = fork();
    if(p<0)
        printf(2, "Supertest fork failed"), exit();
    else if(p==0)
        printf(1, ":{t}\\n"),exec("{t}", argv), printf(2, "Supertest exec %s failed\\n", "{t}"), exit();
    else
        wait();
"""

source += "exit();}"

with open("../user/supertest.c", "w") as f:
    f.write(source);
