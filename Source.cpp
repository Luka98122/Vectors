#pragma warning(disable: 4996)
#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#include <cstdlib>
#include <crtdbg.h>
#include <conio.h>

#include "LukaLib.h"

int tester();
void int_binary(int n);
int hash_string(String* obj);


int names_age() {
    FILE* fp;
    char name[20];
    int age;


    printf("Enter your name: ");
    scanf("%s", name);

    String* nameString = new String(name);

    fp = fopen("data.txt", "r");

    char line[100];
    int cnt = 0;
    bool doAge = false;
    while (fgets(line, 100, fp) != NULL) {
        //printf("%s\n", line);
        if (doAge == true) {
            printf("Your age is: %s\n", line);
            break;
        }
        if (cnt % 2 == 0) {
            char* l = (char*)(malloc(sizeof(char) * 20));
            int end = 0;
            for (int i = 0; i < sizeof(name); i++) {
                if (line[i] == '\n') {
                    end = i;
                    break;
                }
            }

            for (int i = 0; i < end; i++) {
                l[i] = line[i];
            }
            l[end] = '\0';
            String* tmp = new String(l);
            if ((*tmp == *nameString) == 0) {
                doAge = true;
            }
            delete tmp;
        }
        cnt += 1;
    }
    if (doAge == false) {
        printf("Enter your age: ");
        scanf("%d", &age);

        fclose(fp);

        fp = fopen("data.txt", "a");

        fprintf(fp, "%s\n%d\n", name, age);

        fclose(fp);
    }

    return 0;
}   


int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    int tmp = 177;
    printf("%s", tmp);

    String* str1 = new String("Hello");
    String* str2 = new String(" World\n");

    HashMap* dict1 = new HashMap();
    dict1->Append(str1, str2);
    dict1->Append(str2, str1);

    dict1->Append(str2, str1);

    String world = dict1->Get(str1);
    printf("%s", world.data);

    Vec<String> newVec;
    newVec = str1->split(".");






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