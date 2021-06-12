#include <memory>

using std::shared_ptr;

class treeNode
{
public:
	explicit treeNode(int);
	int getValue() const;
	int getSize() const;
	void setValue(int);
	shared_ptr<treeNode> getLeft() const;
	shared_ptr<treeNode> getRight() const;
	void setLeft(shared_ptr<treeNode> &);
	void setLeft(shared_ptr<treeNode> &&);
	void setRight(shared_ptr<treeNode> &);
	void setRight(shared_ptr<treeNode> &&);

private:
	int value;
	int size; //树的大小（包括本节点）
	shared_ptr<treeNode> left;
	shared_ptr<treeNode> right;
};

class AVLTree
{
public:
	AVLTree();
	void add(int);
	void del(int);
	bool find(int) const;

private:
	int size;				   //树的大小
	shared_ptr<treeNode> root; //AVLTree的起始节点，注意AVL树为空时，root为nullptr
};