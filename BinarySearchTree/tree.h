#include <memory>

using std::initializer_list;
using std::shared_ptr;

class treeNode
{
private:
	int value;
	shared_ptr<treeNode> left;
	shared_ptr<treeNode> right;

public:
	treeNode(int);
	treeNode(int, shared_ptr<treeNode> &, shared_ptr<treeNode> &);
	int getValue() const;
	shared_ptr<treeNode> getLeft() const;
	shared_ptr<treeNode> getRight() const;
	void setLeft(shared_ptr<treeNode> &);
	void setLeft(shared_ptr<treeNode> &&);
	void setRight(shared_ptr<treeNode> &);
	void setRight(shared_ptr<treeNode> &&);
};

class BST
{
private:
	shared_ptr<treeNode> root;
	int size;

public:
	BST();
	BST(initializer_list<int> values);
	void insert(int value);
	void del(int value);
	bool find(int value) const;
	int getSize() const;
	void print() const;
};