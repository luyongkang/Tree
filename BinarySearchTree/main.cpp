#include "tree.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	BST btree{25, 3, 7, 23, 56, 12, 74, 8};
	btree.print();
	btree.del(25);
	btree.del(74);
	btree.del(12);
	btree.del(324234);
	btree.insert(1234);
	btree.insert(213);
	btree.print();
	return 0;
}