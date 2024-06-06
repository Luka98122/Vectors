#include <stdio.h>
#include <cstdlib>
#include <crtdbg.h>
#include <conio.h>
#include "LukaLib.h"


int tester() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// Strings
	printf("===Strings===\n");

	String* str1 = new String("String1");
	String* str2 = new String("String2");
	String* str3 = *str1 + *str2;

	String* testStr = new String("String1String2");
	String* str12 = new String("String1");
	String* str22 = new String("String2");


	if ((*str3==*testStr) == 0) {
		printf("[T] Added strings show correct value: PASS\n");
	}
	else {
		printf("[T] Added strings show correct value: FAIL <----------------\n");
	}

	if ((*str1 == *str12)==0 && (*str2 == *str22)==0) {
		printf("[T] Strings retain value after being added: PASS\n");
	}
	else {
		printf("[T] Strings retain value after being added: FAIL  <----------------\n");
	}
	
	printf("\n");
	printf("[P] %s", str3->data);
	printf("\n");
	printf("[P] ");
	str3->print();
	printf("\n");





	// String Vectors
	printf("===String Vectors===\n");
	StringVector* stringVec = new StringVector();
	
	stringVec->Append(str1);
	stringVec->Append(str3);
	stringVec->Append(str2);

	StringVector* stringVec2 = new StringVector();

	stringVec2->Append(str3);
	stringVec2->Append(str2);

	stringVec->Remove(str1);

	if ((*stringVec == *stringVec2)==0) {
		printf("[T] Removing items from String Vectors: PASS\n");	
	}
	else {
		printf("[T] Removing items from String Vectors: FAIL <-------------\n");
	}


	if ((*str1 == *str12) == 0 && (*str2 == *str22) == 0 && (*str3 == *testStr) == 0) {
		printf("[T] Strings retain value after being removed from vector: PASS\n");
	}
	else {
		printf("[T] Strings retain value after being removed from vector: FAIL  <----------------\n");
	}



	// Vectors
	printf("===Vectors===\n");
	Vector* test = new Vector();
	test->Append(1);
	test->Append(2);
	test->Append(3);
	test->Append(4);

	Vector* test2 = new Vector();
	test2->Append(1);
	test2->Append(2);
	test2->Append(3);
	
	test->Remove(4);

	if ((*test == *test2)==0) {
		printf("[T] Removing numbers from Vectors: PASS\n");
	}
	else {
		printf("[T] Removing numbers from Vectors: FAIL <---------------\n");
	}
	

	// Linked Lists
	printf("===Linked Lists===\n");
	LinkedList* LinkedL = new LinkedList(0);
	for (int i = 1; i < 10; i++) {
		LinkedL->add(i);
	}

	printf("[P] ");
	LinkedL->print();

	LinkedL->del(5);
	printf("[P] ");
	LinkedL->print();
	//Binary Tree
	printf("===Binary Tree===\n");
	BinaryTree* BinTree = new BinaryTree(1000);
	BinTree->add(500);
	BinTree->add(1500);
	BinTree->add(250);
	BinTree->add(750);
	printf("\n");

	// Deleting everything
	printf("Delete everything\n");
	delete str1;
	delete str2;
	delete str3;
	delete str12;
	delete str22;
	delete testStr;



	delete test;
	delete test2;



	delete LinkedL;

	delete BinTree;
	delete stringVec;
	delete stringVec2;
	return 0;
}
