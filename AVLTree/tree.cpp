#include "tree.h"
#include <cmath>
#include <vector>

using std::ceil;
using std::log2;
using std::make_shared;
using std::vector;

treeNode::treeNode(int v) : value(v), size(0), left(nullptr), right(nullptr) {}

int treeNode::getSize() const
{
	return size;
}

int treeNode::getValue() const
{
	return value;
}

void treeNode::setValue(int v)
{
	value = v;
}

void treeNode::setLeft(shared_ptr<treeNode> &pleft)
{
	left = pleft;
}

void treeNode::setLeft(shared_ptr<treeNode> &&pleft)
{
	left = pleft;
}

void treeNode::setRight(shared_ptr<treeNode> &pright)
{
	right = pright;
}

void treeNode::setRight(shared_ptr<treeNode> &&pright)
{
	right = pright;
}

AVLTree::AVLTree() : size(0), root(nullptr) {}

void AVLTree::add(int value)
{
	if (root == nullptr)
	{
		root = make_shared<treeNode>(value);
		++size;
		return;
	}

	vector<shared_ptr<treeNode>> path;
	shared_ptr<treeNode> temp = root;
	while (temp != nullptr)
	{
		if (temp->getValue() == value)
			return;
		else if (value < temp->getValue())
		{
			path.push_back(temp);
			temp = temp->getLeft();
		}
		else
		{
			path.push_back(temp);
			temp = temp->getRight();
		}
	}

	shared_ptr<treeNode> insertValue = make_shared<treeNode>(value);
}

void AVLTree::del(int value)
{
}

bool AVLTree::find(int value) const
{
	shared_ptr<treeNode> temp = root;
	while (temp != nullptr)
	{
		if (temp->getValue() == value)
		{
			break;
		}
		else if (temp->getValue() > value)
		{
			temp = temp->getLeft();
		}
		else
		{
			temp = temp->getRight();
		}
	}

	if (temp == nullptr)
		return false;
	else
		return true;
}
