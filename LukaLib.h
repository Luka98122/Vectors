#pragma once
#include <type_traits>





template <class T> class Vec {
public:
	Vec();
	T* elements;
	int size;
	int occupied;
	void Append(T* x);
};

template <class T>
Vec<T>::Vec<T>() {
	size = 16;
	occupied = 0;
	elements = (T*)(malloc(size * sizeof(T)));
}

template <class T>
void Vec<T>::Append(T* x) {
	if (occupied < size) {
		elements[occupied] = *x;
		occupied += 1;
	}
	else {
		size += 16;
		T* temp;
		temp = (T*)(malloc(size * sizeof(T)));
		for (int i = 0; i < size - 16; i++) {
			temp[i] = elements[i];
		}
		free(elements);
		elements = temp;
		elements[occupied] = *x;
	}
}

class String {
public:
	String(const char* st);
	~String();
	char* data;
	int len;

	void print();
	void debugPrint();
	int has(const char* other, int start);
	int operator== (String& other);
	String* operator + (String& obj);
	Vec<String> split(String splitter);
};






class Vector {
public:
	Vector();
	~Vector();

	int* elements;
	int size;
	int occupied;
	void Append(int x);
	void Print();
	void Remove(int x);
	void DebugPrint();
	int operator== (const Vector& other) const;
};


class StringVector {
public:
	StringVector();
	~StringVector();

	String **elements;
	int size;
	int occupied;
	void Append(String* x);
	void Print();
	void Remove(String* x);
	void DebugPrint();
	int operator== (StringVector& other);
};


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

class BinaryTree {
public:
	BinaryTree(int dat);
	~BinaryTree();
	int data;
	BinaryTree* left;
	BinaryTree* right;
	BinaryTree* top;

	void add(int dat);
	bool isSorted();
};


class HashMap {
public:
	HashMap();
	~HashMap();

	String* elements;
	int* occupieds;
	void Append(String* key, String* value);
	String Get(String* key);
	void Del(String* key);

	int maxSize;
};