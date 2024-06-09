#pragma once

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

class String {
public:
	String(const char* st);
	~String();
	char* data;
	int len;

	void print();
	void debugPrint();
	bool has(char* other);
	int operator== (String& other);
	String* operator + (String& obj);
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

class Node {
public:
	Node();
	~Node();
	int id;
	int data;
	int bestToReach;
	Node** neighbors;
};