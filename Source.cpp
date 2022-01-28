#include<iostream>
#include"BinaryTree.h"

//function to count number of paths of nodes from a node that sum to a specific value
template <typename T>
void BinaryTree<T>::pathcheck(Node* node, T value, int& path, T sum)
{
	if (node == NULL)//base case if Node is NULL or becomes NULL 
		return;
	else
	{
		sum += node->data;//calculating sum

		if (sum == value)//if sum is equal to value then increments the count of path
			path++;

		//recursive calls for left and right subtrees 
		BinaryTree<T>::pathcheck(node->left, value, path, sum);
		BinaryTree<T>::pathcheck(node->right, value, path, sum);
	}
}

template <typename T>
int BinaryTree<T>::calculatepaths(Node* node, T value)
{
	int path = 0;
	if (node)
	{
		queue<Node*> Q;//queue for traversing
		Node* currnode = NULL;

		Q.push(node);

		while (!Q.empty())//to look for paths in the whole tree
		{
			currnode = Q.front();
			Q.pop();

			pathcheck(currnode, value, path);//counting number of paths that sum to specific value for currnode

			if (currnode->left != NULL)
				Q.push(currnode->left);
			if (currnode->right != NULL)
				Q.push(currnode->right);
		}
	}
	return path;
}

int main()
{
	BinaryTree<int> BT;
	
	BT.Insert(13);
	BT.Insert(-4);
	BT.Insert(5);
	BT.begin()->left->right = new BinaryTree<int>::Node(2);
	BT.begin()->right->left = new BinaryTree<int>::Node(4);
	BT.begin()->right->left->right = new BinaryTree<int>::Node(5);
	BT.begin()->right->left->right->left = new BinaryTree<int>::Node(2);
	BT.begin()->right->left->right->left->right = new BinaryTree<int>::Node(2);
	
	cout << "Q6:\nManually created Binary Tree (inorder):\n";
	BinaryTree<int>::DFIterator it;
	for (it = BT.begin(); !it.end(); it++)
		cout << *it << endl;

	cout << "Number of paths in above Binary Tree for 9 are " << BinaryTree<int>::calculatepaths(BT.begin(), 9) << ".\n";
}