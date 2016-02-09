#include <stdio.h>
#include <sys/mman.h>

int main(int argc, char** argv)
{
	unsigned char code[] = {
										// 08048060 <_start>:
		0xEB, 0x20, 					// 8048060:	eb 20                	jmp    8048082 <STACKUP>
										// 08048062 <RUN>:
		0xB8, 0x04, 0x00, 0x00, 0x00,	// 8048062:	b8 04 00 00 00       	mov    $0x4,%eax
		0xBB, 0x01, 0x00, 0x00, 0x00,	// 8048067:	bb 01 00 00 00       	mov    $0x1,%ebx
		0x59,							// 804806c:	59                   	pop    %ecx
		0xBA, 0x0B, 0x00, 0x00, 0x00,	// 804806d:	ba 0b 00 00 00       	mov    $0xb,%edx
		0xCD, 0x80,						// 8048072:	cd 80                	int    $0x80
		0xEB, 0x0C,						// 8048074:	eb 0c                	jmp    8048082 <STACKUP>
		0xB8, 0x01, 0x00, 0x00, 0x00,	// 8048076:	b8 01 00 00 00       	mov    $0x1,%eax
 		0xBB, 0x00, 0x00, 0x00, 0x00,	// 804807b:	bb 00 00 00 00       	mov    $0x0,%ebx
 		0xCD, 0x80,						// 8048080:	cd 80                	int    $0x80
										// 08048082 <STACKUP>:
		0xE8, 0xDB, 0xFF, 0xFF, 0xFF,	// 8048082:	e8 db ff ff ff 50 77 6e 65 64 20 59 6f 75 21 0a     .....Pwned You!.
		0x50, 0x77, 0x6E, 0x65, 0x64,
		0x20, 0x59, 0x6F, 0x75, 0x21,
		0x0A 
	};

	// from startaddress of shellcode array, get start of the containing memody page
	void* page = (void*)((unsigned long)code & ((0UL - 1UL) ^ 0xfff));

	/* 
	 * tell linux that there may be executable code in the memory page.
	 * http://www.tutorialspoint.com/unix_system_calls/mprotect.htm
	*/
	mprotect(page, 1, PROT_READ|PROT_WRITE|PROT_EXEC);

	char myarray[16] = {14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29};

	// a direct jump to the code above: cast start addr of array to function pointer and execute it:
	// ((void(*)(void)) code)(); // lame.

	// the "hack": do not use code array descriptor, but the fact that it is placed after myarray in memory - overflow myarray by one:
	((void(*)(void)) &myarray[16])();

	return 0;
}

