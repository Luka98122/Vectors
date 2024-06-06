#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#include <cstdlib>
#include <crtdbg.h>
#include <conio.h>

#include "LukaLib.h"

int tester();

void int_binary(int n) {
    int k;
    for (int c = 31; c >= 0; c--)
    {
        k = n >> c;
        if (k & 1)
            printf("1");
        else
            printf("0");
    }

    printf("\n");
}


int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
    tester();


	unsigned char a = 5, b = 9;

	printf("And: ");
    int_binary(a & b);
	printf("\nOr : ");
    int_binary(a | b);
    printf("\nXor : ");
    int_binary(a ^ b);
	
	return 0;
}