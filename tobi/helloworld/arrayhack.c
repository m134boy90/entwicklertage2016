#include<stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

int main()
{

    unsigned char mya[] = {0xB8, 0x04, 0x00, 0x00, 0x00, 0xBB,  0x01, 0x00, 0x00, 0x00, 0x59, 0xBA, 0x0E, 0x00,
    0x00, 0x00, 0xCD, 0x80, 0xEB, 0x09, 0xB8, 0x01,  0x00, 0x00, 0x00, 0x31, 0xDB, 0xCD, 0x80, 0xE8,
    0xDE, 0xFF, 0xFF, 0xFF, 0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x2C, 0x20, 0x57, 0x6F, 0x72, 0x6C, 0x64, 0x21, 0x0A
    };

    int Buffer1[5] = {1, 1, 1, 1, 1};
    int Buffer2[3] = {2, 2, 2};
    int Buffer3[3] = {3, 3, 3};

    void *addr = (void*)((unsigned long)mya & ((0UL - 1UL) ^ 0xfff));/*get memory page*/
    int ans = mprotect(addr, 1, PROT_READ|PROT_WRITE|PROT_EXEC);/*set page attributes*/

    ((void(*)(void))&Buffer3[12])();/*execute array*/

    return 0;
}