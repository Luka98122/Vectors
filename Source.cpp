#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#include <cstdlib>
#include <crtdbg.h>
#include <conio.h>

int bintree();
int string();


class Vector {
public:
	Vector();
	~Vector();

	int *elements;
	int size;
	int occupied;
	void Append(int x);
	void Print();
	void Remove(int x);
	void DebugPrint();
};

Vector::Vector() {
	size = 16;
	occupied = 0;
	elements = (int*)(malloc(size*sizeof(int)));
	DebugPrint();
}

Vector::~Vector() {
	printf("Destructing vec at %p\n", this);
	free(elements);
}

void Vector::Append(int x) {
	if (occupied < size) {
		elements[occupied] = x;
		occupied += 1;
	}
	else {
		size += 16;
		int* temp;
		temp = (int*)(malloc(size * sizeof(int)));
		for (int i = 0;i < size - 16;i++) {
			temp[i] = elements[i];
		}
		free(elements);
		elements = temp;
		elements[occupied] = x;
		occupied += 1;
	}
}

void Vector::Print() {
	printf("{");
	for (int i = 0;i < occupied;i++) {
		printf(" %d", elements[i]);
		printf(",");
	}
	printf("}\n");
}

void Vector::Remove(int x) {
	for (int i = 0;i < occupied;i++) {
		if (elements[i] == x) {
			//logic
			int* temp;
			temp = (int*)(malloc(size * sizeof(int)));
			for (int j = 0;j < occupied;j++) {
				if (j == x) {
					continue;
				}
				if (j > x) {
					temp[j-1] = elements[j];
				}
				else { temp[j] = elements[j]; }
			}
			free(elements);
			elements = temp;
			occupied -= 1;
			return;
		}
	}
	printf("Value was not found!\n");
}

void Vector::DebugPrint() {
	printf("Vector {");
	printf("%p ", this);
	printf("Slots %d ", occupied);
	printf("Alloc %d ", size);
	printf("Data ptr %p ", elements);

	printf("}\n");

}


class LinkedList {
public:
	LinkedList(int dat);
	~LinkedList();
	int data;
	LinkedList* next;
	LinkedList* prev;
	void add(int dat);
	void del(int dat);
	void print();
	void r_print();
	void insert(int dat);
	bool isSorted();
};

void LinkedList::del(int dat) {
	LinkedList* current = this;
	LinkedList* previous = nullptr;

	while (current != nullptr) {
		if (current->data == dat) {
			if (previous != nullptr) {
				previous->next = current->next;
				current->next->prev = previous;
			}
			else {
				if (current->next != nullptr) {
					LinkedList* temp = current->next;
					this->data = temp->data;
					this->next = temp->next;
					delete temp;
					return;
				}
				else {
					this->data = 0;
					this->next = nullptr;
					this->prev = nullptr;
					return;
				}
			}
			current->next = NULL;
			delete current;
			break;
		}
		else {
			previous = current;
			current = current->next;
		}
	}
}

LinkedList::~LinkedList() {
	delete next;	
}

void LinkedList::print() {
	LinkedList* current = this;
	while (true)
	{
		if (current->next == NULL) {
			printf("%d\n", current->data);
			break;
		}
		else {
			printf("%d\n", current->data);
			current = current->next;
		}
	}
}

void LinkedList::r_print() {
	LinkedList* current = this;
	while (true)
	{
		if (current->next == NULL) {
			break;
		}
		else {
			current = current->next;
		}
	}

	while (true) 
	{
		if (current->prev == NULL) {
			printf("%d\n", current->data);
			break;
		}
		else {
			printf("%d\n", current->data);
			current = current->prev;
		}
	}
}

bool LinkedList::isSorted() {
	LinkedList* current = this;
	int bigEqual = data;
	while (true)
	{
		if (current->next == NULL) {
			printf("%d\n", current->data);
			break;
		}
		else {
			if (current->data > current->next->data) {
				return false;
			}
		}
		current = current->next;
	}
	return true;
}

LinkedList::LinkedList(int dat) {
	data = dat;
	next = NULL;
	LinkedList* prev = NULL;
}

void LinkedList::add(int dat) {
	LinkedList* current = this;
	while (true)
	{
		if (current->next == NULL) {
			LinkedList* newLl = new LinkedList(dat);
			newLl->prev = current;
			current->next = newLl;

			break;
		}
		else {
			current = current->next;
		}
	}
}

void LinkedList::insert(int dat) {
	LinkedList* current = this;

	if (dat < current->data) {
		LinkedList* temp1 = new LinkedList(dat);
		LinkedList* temp2 = new LinkedList(dat);

		temp1->next = current->next;
		temp1->data = current->data;
		temp1->prev = current;
		current = temp2;
		next = temp1;
		prev = NULL;
		data = dat;
		delete temp2;
		return;
	}

	while (true) {
		if (current->next == NULL) {
			LinkedList* newLl = new LinkedList(dat);
			newLl->prev = current;
			current->next = newLl;
			return;
		}
		else {
			if (dat >= current->data && dat <= current->next->data) {
				LinkedList* newLl = new LinkedList(dat);
				newLl->prev = current;
				newLl->next = current->next;
				current->next = newLl;
				return;
			}
		}
		current = current->next;
	}
}

void memory_leak() {
	for (int i = 0;i < 1000000;i++) {
		Vector vec;
		for (int j = 0;j < 1000;j++) {
			vec.Append(j);
		}
	}
}

void steps() {
	Vector nums;
	for (int i = 0;i < 35;i++) {
		nums.Append(i);
	}

	nums.Print();
	nums.Remove(17);
	nums.Print();
}

void manually_alloc() {
	Vector* vec2 = new Vector();
	vec2->Append(100);
	vec2->Print();
	delete vec2;
}


void linkedlist() {
	LinkedList* test = new LinkedList(1);
	for (int i = 0; i < 15; i++) {
		test->insert(i);
	}
	test->del(2);
	test->del(3);
	test->del(4);
	test->print();
	test->insert(3);
	test->insert(20);
	//test->insert(-1);
	test->print();
	printf("=========\n");
	test->r_print();
	test->add(1);
	bool res = test->isSorted();
	delete test;

}


int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//linkedlist();
	//bintree();
	string();

	_getch();
	return 0;
}