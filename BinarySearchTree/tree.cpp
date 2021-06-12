#include "tree.h"

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::make_shared;
using std::vector;

treeNode::treeNode(int parm)
{
	value = parm;
	left.reset();
	right.reset();
}

treeNode::treeNode(int param, shared_ptr<treeNode> &pleft, shared_ptr<treeNode> &pright)
{
	value = param;
	left = pleft;
	right = pright;
}

int treeNode::getValue() const
{
	return value;
}

shared_ptr<treeNode> treeNode::getLeft() const
{
	return left;
}

shared_ptr<treeNode> treeNode::getRight() const
{
	return right;
}

void treeNode::setLeft(shared_ptr<treeNode> &p)
{
	left = p;
}

void treeNode::setLeft(shared_ptr<treeNode> &&p)
{
	left = p;
}

void treeNode::setRight(shared_ptr<treeNode> &p)
{
	right = p;
}

void treeNode::setRight(shared_ptr<treeNode> &&p)
{
	right = p;
}

BST::BST() : root(nullptr), size(0) {}

BST::BST(initializer_list<int> values) : root(nullptr), size(0)
{
	for (int i : values)
	{
		insert(i);
	}
}

void BST::insert(int value)
{
	do
	{
		auto index = make_shared<treeNode>(value);
		//root is nullptr
		if (root == nullptr)
		{
			root = index;
			++size;
			break;
		}

		//root is not nullptr
		shared_ptr<treeNode> temp = root;
		shared_ptr<treeNode> father;
		while (true)
		{
			if (temp == nullptr)
			{
				if (value < father->getValue())
				{
					father->setLeft(index);
				}
				else
					father->setRight(index);

				++size;
				break;
			}

			if (temp->getValue() > value)
			{
				father = temp;
				temp = temp->getLeft();
			}
			else if (temp->getValue() < value)
			{
				father = temp;
				temp = temp->getRight();
			}
			else
			{
				break;
			}
		}
	} while (false);

	return;
}

void BST::del(int value)
{
	do
	{
		auto temp = root;
		shared_ptr<treeNode> father = root;
		while (temp != nullptr && temp->getValue() != value)
		{
			father = temp;
			if (temp->getValue() > value)
				temp = temp->getLeft();
			else
				temp = temp->getRight();
		}

		if (temp == nullptr)
			break;

		//第一种情况：两个子节点都是nullptr
		if (temp->getLeft() == nullptr && temp->getRight() == nullptr)
		{
			if (temp == root)
			{
				root = nullptr;
				--size;
				break;
			}

			if (father->getLeft() == temp)
			{
				father->setLeft(nullptr);
			}
			else
			{
				father->setRight(nullptr);
			}
			--size;
			break;
		}

		//第二种情况：两个子节点有一个为nullptr
		//左节点为nullptr
		if (temp->getLeft() == nullptr)
		{
			if (temp == root)
			{
				root = temp->getRight();
				--size;
				break;
			}

			if (father->getLeft() == temp)
			{
				father->setLeft(temp->getRight());
			}
			else
			{
				father->setRight(temp->getRight());
			}
			--size;
			break;
		}

		//右节点为nullptr
		if (temp->getRight() == nullptr)
		{
			if (temp == root)
			{
				root = temp->getLeft();
				--size;
				break;
			}
			if (father->getLeft() == temp)
			{
				father->setLeft(temp->getLeft());
			}
			else
			{
				father->setRight(temp->getLeft());
			}
			--size;
			break;
		}

		//第三种情况：两个子节点都不是空,则寻找右节点的最小数。
		auto min = temp->getRight();
		auto premin = temp;
		while (min->getLeft() != nullptr)
		{
			premin = min;
			min = min->getLeft();
		}
		if (premin == temp)
		{
			premin->setRight(min->getRight());

			min->setLeft(temp->getLeft());
			min->setRight(temp->getRight());
		}
		else
		{
			premin->setLeft(min->getRight());

			min->setLeft(temp->getLeft());
			min->setRight(temp->getRight());
		}

		if (temp == root)
		{
			root = min;
			--size;
			break;
		}

		if (father->getLeft() == temp)
		{
			father->setLeft(min);
		}
		else
		{
			father->setRight(min);
		}
		--size;
		break;
	} while (false);

	return;
}

bool BST::find(int value) const
{
	auto temp = root;
	bool isfind = false;
	while (temp != nullptr && temp->getValue() != value)
	{
		if (temp->getValue() > value)
		{
			temp = temp->getLeft();
		}
		else
		{
			temp = temp->getRight();
		}
	}
	if (temp != nullptr)
		isfind = true;
	return isfind;
}

int BST::getSize() const
{
	return size;
}

void BST::print() const
{
	if (root == nullptr)
	{
		cout << "null" << endl;
		return;
	}

	vector<shared_ptr<treeNode>> father;
	vector<shared_ptr<treeNode>> son;
	father.push_back(root);

	while (!father.empty())
	{
		for (auto temp : father)
		{
			cout << temp->getValue() << "   ";
			if (temp->getLeft() != nullptr)
			{
				son.push_back(temp->getLeft());
			}
			if (temp->getRight() != nullptr)
			{
				son.push_back(temp->getRight());
			}
		}
		cout << endl;

		son.swap(father);
		son.clear();
	}

	return;
}