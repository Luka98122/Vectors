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

int rotate_left(int n, int c) {
    n = (n << c) | (n >> 64-c);
    return n;
}

int rotate_right(int n, int c) {
    n = (n >> c) | (n << 64-c);
    return n;
}



int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    




    //int_binary(7);
    //int_binary(rotate_left(7,3));
    //int_binary(rotate_right(7,2));

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