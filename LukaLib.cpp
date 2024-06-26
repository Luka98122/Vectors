#include <stdio.h>
#include <cstdlib>
#include <crtdbg.h>
#include <conio.h>
#include "LukaLib.h"



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
	n = (n << c) | (n >> 64 - c);
	return n;
}

int rotate_right(int n, int c) {
	n = (n >> c) | (n << 64 - c);
	return n;
}




Vector::Vector() {
	size = 16;
	occupied = 0;
	elements = (int*)(malloc(size * sizeof(int)));
	//DebugPrint();
}

Vector::~Vector() {
	//printf("Destructing vec at %p\n", this);
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
		for (int i = 0; i < size - 16; i++) {
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
	for (int i = 0; i < occupied; i++) {
		printf(" %d", elements[i]);
		printf(",");
	}
	printf("}\n");
}

void Vector::Remove(int x) {
	for (int i = 0; i < occupied; i++) {
		if (elements[i] == x) {
			//logic
			int* temp;
			temp = (int*)(malloc(size * sizeof(int)));
			for (int j = 0; j < occupied; j++) {
				if (j == x) {
					continue;
				}
				if (j > x) {
					temp[j - 1] = elements[j];
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

int Vector::operator==(const Vector& other) const {
	if (occupied != other.occupied) {
		return 1;
	}
	else {
		for (int i = 0; i < occupied; i++) {
			if (elements[i] != other.elements[i]) {
				return 1;
			}
		}
	}
	return 0;
}



LinkedList::LinkedList(int dat) {
	data = dat;
	next = NULL;
	LinkedList* prev = NULL;
}


LinkedList::~LinkedList() {
	delete next;
}

void LinkedList::print() {
	LinkedList* current = this;
	printf("{");
	while (true)
	{
		if (current->next == NULL) {
			printf(" %d}\n", current->data);
			break;
		}
		else {
			printf(" %d", current->data);
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




BinaryTree::BinaryTree(int dat) {
	data = dat;
	left = NULL;
	right = NULL;
	top = NULL;
};

BinaryTree::~BinaryTree() {
	delete left;
	delete right;

}

void BinaryTree::add(int dat) {
	BinaryTree* current = this;

	while (true) {
		if (dat > current->data) {
			if (current->right == NULL) {
				BinaryTree* temp = new BinaryTree(dat);
				temp->top = current;
				current->right = temp;
				return;
			}
			else {
				current = current->right;
			}
		}
		else {
			if (current->left == NULL) {
				BinaryTree* temp = new BinaryTree(dat);
				temp->top = current;
				current->left = temp;
				return;
			}
			else {
				current = current->left;
			}
		}
	}

};

bool BinaryTree::isSorted() {
	if (left != NULL && !left->isSorted()) {
		return false;
	}

	if (right != NULL && !right->isSorted()) {
		return false;
	}

	if (right != NULL && data > right->data) {
		return false;
	}

	if (left != NULL && data < left->data) {
		return false;
	}

	return true;
}


BinaryTree* first_parent(BinaryTree* a, BinaryTree* b) {
	BinaryTree* a_parents[100];
	BinaryTree* b_parents[100];

	for (int i = 0; i < 100; i++) {
		a_parents[i] = NULL;
	}

	BinaryTree* current = a;
	int adepth = 0;
	while (true) {
		if (current->top != NULL) {
			a_parents[adepth] = current->top;
			adepth += 1;
			current = current->top;
		}
		else {
			break;
		}
	}
	current = b;
	int bdepth = 0;
	while (true) {
		if (current->top != NULL) {
			b_parents[bdepth] = current->top;
			bdepth += 1;
			current = current->top;
		}
		else {
			break;
		}
	}
	int min;
	int aoff = 0;
	int boff = 0;

	if (adepth >= bdepth) {
		min = bdepth;
		aoff = adepth - bdepth;
	}
	else {
		min = adepth;
		boff = bdepth - adepth;
	}

	for (int i = 0; i < min; i++) {
		if (a_parents[i + aoff] == b_parents[i + boff]) {
			return a_parents[i];
		}
	}

	return NULL;
}

void fprint_tree(BinaryTree* root, int depth) {

	int l = 0;
	int r = 0;

	printf("Depth %d | %d | Left ", depth, root->data);
	if (root->left == NULL) {
		printf("NULL,");
	}
	else {
		printf("%d,", root->left->data);
		l = 1;
	}
	if (root->right == NULL) {
		printf("NULL,");
	}
	else {
		printf("%d,", root->right->data);
		r = 1;
	}
	printf("\n");
	if (l == 1) {
		fprint_tree(root->left, depth + 1);
	}
	if (r == 1) {
		fprint_tree(root->right, depth + 1);
	}
};


String::String() {
	data = NULL;
	len = 0;
	printf("Empty String @ %p\n", this);
}

String::String(const String& other) {
	printf("String copy constructor %p -> %p\n", &other, this);

	*this = other;
}

void String::operator=(const String& other) {
	printf("String operator= %p -> %p\n", &other, this);
	len = other.len;
	data = new char[len + 1];
	for (int i = 0; i < len + 1; i++) {
		data[i] = other.data[i];
	}

}


String::String(const char* st) {
	int l = 0;
	while (true) {
		if (st[l] == '\0') {
			break;
		}
		else {
			l += 1;
		}
	}
	len = l;
	char* dat = new char[len+1];
	for (int i = 0; i < len; i++) {
		dat[i] = st[i];
	}
	dat[len] = 0;
	data = dat;
	printf("String @ %p - %s\n", this, data);
	//printf("Constructor: ");
	//debugPrint();

}

String::~String() {
	printf("~String @ %p - %s\n", this, data);
	delete []data;
}

String* String::operator+(String& other) {
	int newLen = len + other.len;
	char* temp = new char[newLen + 1];
	for (int i = 0; i < len; i++) {
		temp[i] = data[i];
	}
	for (int i = 0; i < other.len; i++) {
		temp[len + i] = other.data[i];
	}
	temp[newLen] = '\0';

	String* res = new String(temp);
	delete []temp;
	return res;
}

void String::print() {
	printf("%s", data);
}

void String::debugPrint() {
	printf("ptr: %p len: %d data-ptr: %p Str: %s\n", this, len, data, (data ? data : ""));
}

int String::operator==(String& other) {
	if (len != other.len) {
		return 1;
	}
	for (int i = 0; i < len; i++) {
		if (data[i] == other.data[i]) {
			
		}
		else {
			return 1;
		}
	}
	return 0;
}

Vec<String>* String::split(String* splitter) {
	Vec<String>* result = new Vec<String>;
	int startPos = 0;
	int splitterLen = splitter->len;
	int pos = 0;
	while ((pos = has(splitter->data, startPos)) != -1) {
		char* substr = new char [pos - startPos + 1];
		for (int i = startPos; i < pos; i++) {
			substr[i - startPos] = data[i];
		}
		substr[pos - startPos] = '\0';
		String *newString = new String(substr);
		result->Append(*newString);
		delete []substr;
		startPos = pos + splitterLen;
	}
	if (startPos < len) {
		char* substr = new char[len - startPos + 1];
		for (int i = startPos; i < len; i++) {
			substr[i - startPos] = data[i];
		}
		substr[len - startPos] = '\0';
		String *newString = new String(substr);
		result->Append(*newString);
		free(substr);
	}
	return result;
}

int String::has(const char* other, int start) {
	int otherLen = 0;
	while (other[otherLen] != '\0') {
		otherLen++;
	}
	for (int i = start; i <= len - otherLen; i++) {
		int j;
		for (j = 0; j < otherLen; j++) {
			if (data[i + j] != other[j]) {
				break;
			}
		}
		if (j == otherLen) {
			return i;
		}
	}
	return -1;
}	

StringVector::StringVector () {
	size = 16;
	occupied = 0;
	elements = (String**)malloc(size * sizeof(String*));
	//DebugPrint();
}

StringVector::~StringVector() {
	//printf("Destructing vec at %p\n", this);
	for (int i = 0; i < occupied; i++) {
		delete elements[i];
	}
	free(elements);
}



void StringVector::Append(String* x) {

	String* temp2 = new String(x->data);

	if (occupied < size) {
		elements[occupied] = temp2;
		occupied += 1;
	}
	else {
		size += 16;
		String** temp = (String**)malloc(size * sizeof(String*));
		for (int i = 0; i < occupied; i++) {
			temp[i] = elements[i];
		}
		free(elements);
		elements = temp;
		elements[occupied] = temp2;
		occupied += 1;
	}
}

void StringVector::Print() {
	printf("{");
	for (int i = 0; i < occupied; i++) {
		printf(" %s", elements[i]->data);
		printf(",");
	}
	printf("}\n");
}

void StringVector::Remove(String* x) {
	for (int i = 0; i < occupied; i++) {
		if ((elements[i]->data == x->data) == 0) {
			delete elements[i];
			for (int j = i; j < occupied - 1; j++) {
				elements[j] = elements[j + 1];
			}
			occupied -= 1;
			return;
		}
	}
	printf("Value was not found!\n");
}

void StringVector::DebugPrint() {
	printf("Vector {");
	printf("%p ", this);
	printf("Slots %d ", occupied);
	printf("Alloc %d ", size);
	printf("Data ptr %p ", elements);

	printf("}\n");
}

int StringVector::operator==(StringVector& other) {
	if (occupied != other.occupied) {
		return 1;
	}
	else {
		for (int i = 0; i < occupied; i++) {
			if ((elements[i] == other.elements[i])==1) {
				return 1;
			}
		}

	}
	return 0;
}



int hash(int inp) {
	int out = rotate_left(inp, 13) ^ (inp * 17);
	return out;
}

int hash_string(String* obj) {
	int val = 0;
	for (int i = 0; i < obj->len; i++) {
		val += obj->data[i];
	}
	return hash(val);
}


HashSpot::HashSpot() {
	printf("HashSpot @ %p\n", this);
	keys = new Vec<String>;
	values = new Vec<String>;
}

HashSpot::~HashSpot() {
	printf("~HashSpot @ %p\n", this);
	delete []keys;
	delete []values;
}

String* HashSpot::Get(String* key) {
	int res = 0;
	for (int i = 0; i < keys->size; i++) {
		if ((*key == keys->elements[i])==0) {
			res = i;
			break;
		}
	}

	
	return &values->elements[res];
}


HashMap::HashMap() {
	maxSize = 128;
	elements = new HashSpot[maxSize];
	occupieds = new int[maxSize];
	for (int i = 0; i < maxSize; i++) {
		occupieds[i] = 0;
	}
}

HashMap::~HashMap() {
	
	for (int i = 0; i < maxSize; i++) {
		if (occupieds[i] == 1) {
			//for (int j = 0; j < elements[i]->values->occupied;j++) {
				//delete &elements[i]->values[j];
				//delete &elements[i]->keys[j];
			//}
			delete &elements[i];
		}
	}
	free(occupieds);
	free(elements);
}

void HashMap::Set(String* key, String* val) {
	int realKey = hash_string(key) % maxSize;
	String* copy = new String(val->data);
	String* copy2 = new String(key->data);


	HashSpot* spot = new HashSpot();
	spot->keys->Append(*copy2);
	spot->values->Append(*copy);

	if (occupieds[realKey] == 0) {
		elements[realKey] = *spot;
		occupieds[realKey] = 1;
	}
	else {
		delete spot;
		delete copy;
		delete copy2;
		printf("Failed to add string! Slot allready occupied ( Hash collision )!\n");
	}

};

String* HashMap::Get(String* key) {
	int realKey = hash_string(key) % maxSize;
	if (occupieds[realKey] == 1) {
		String* newStr = new String(elements[realKey].Get(key)->data);
		return newStr;
	}
	else {
		printf("Key not found! Key: %s", key->data);
		return NULL;
	}
}