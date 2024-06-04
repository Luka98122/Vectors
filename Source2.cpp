#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#include <cstdlib>
#include <crtdbg.h>
#include <conio.h>

class BinaryTree {
public:
	BinaryTree(int dat);
	~BinaryTree();
	int data;
	BinaryTree* left = NULL;
	BinaryTree* right = NULL;
	BinaryTree* top = NULL;

	void add(int dat);
	bool isSorted();
};


BinaryTree::BinaryTree(int dat) {
	data = dat;
};

BinaryTree::~BinaryTree(){
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
		if (a_parents[i+aoff] == b_parents[i+boff]) {
			return a_parents[i];
		}
	}

	return NULL;
}

void fprint_tree(BinaryTree* root,int depth) {
	
	int l = 0;
	int r = 0;

	printf("Depth %d | %d | Left ", depth, root->data);
	if (root->left == NULL){
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
		fprint_tree(root->left,depth+1);
	}
	if (r == 1) {
		fprint_tree(root->right, depth + 1);
	}
};


int bintree() {
	BinaryTree* bt = new BinaryTree(100);

	for (int i = 0; i < 10; i++) {
		int a;
		scanf_s("%d", &a, sizeof(a));
		bt->add(a);
	}
	
	printf("Ello\n");
	fprint_tree(bt, 0);

	bool test = bt->isSorted();

	BinaryTree* testing = first_parent(bt->left->left->left, bt->left->right->left);

	delete bt;
	return 0;
}