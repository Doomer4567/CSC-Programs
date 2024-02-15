#ifndef BST_H
#define BST_H

#include<iostream>
using namespace std;

class BST
{
	private:
		struct treeNode
		{
			int value;
			treeNode* left;
			treeNode* right;
		};

		treeNode* root;

		void copy(treeNode*& nodePtr, treeNode* copyNode){
			insertNode(copyNode->value);
			if(copyNode->left != NULL)
				copy(nodePtr,copyNode->left);
			if(copyNode->right != NULL)
				copy(nodePtr,copyNode->right);
		}
		void insert(treeNode*& nodePtr, treeNode* newNode){
			if(nodePtr == NULL)
				nodePtr = newNode;
			else if (newNode->value < nodePtr->value)
				insert(nodePtr->left, newNode);
			else
				insert(nodePtr->right, newNode);

 
		}
		void displayInOrder(treeNode* nodePtr) const { 
			if(nodePtr->left != NULL)
				displayInOrder(nodePtr->left);

			cout << nodePtr->value << " ";

			if(nodePtr->right != NULL)
				displayInOrder(nodePtr->right);
		}
		void destroySubTree(treeNode* nodePtr){ 
			if(nodePtr){
				if (nodePtr->left)
					destroySubTree(nodePtr->left);
				if (nodePtr->right)
					destroySubTree(nodePtr->right);
				delete nodePtr;
			}
		} 

	public:
		BST() { root = NULL; }			//default constructor
		BST(const BST &tree){ 
			root = NULL;	
			copy(root, tree.root);

		}	//copy constructor
		~BST() { destroySubTree(root); }

		void insertNode(int num){
			treeNode *newNode = NULL;	


			newNode = new treeNode;
			newNode->value = num;
			newNode->left = NULL;
			newNode->right = NULL;
			
		
			insert(root, newNode);

		}
		void display(){ displayInOrder(root); }
};

#endif