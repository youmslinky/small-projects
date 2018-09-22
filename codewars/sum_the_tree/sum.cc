#include <iostream>

using namespace std;
struct node
{
	int value;
	node* left;
	node* right;
};

// Return the sum of all values in the tree, including the root
int sumTree(node* root) {
	int sum = root->value;
	if(root->left != nullptr){
		sum += sumTree(root->left);
	}
	if(root->right != nullptr){
		sum += sumTree(root->right);
	}
	return sum;
}

int main(){
	node easyNode = {10, new node {1, nullptr, nullptr}, new node {2, nullptr, nullptr}};
	node unbalancedNode = {11, new node {5, nullptr, nullptr}, new node {0, nullptr, new node {1, nullptr, nullptr}}};
	cout << easyNode.left->value << endl;
	cout << unbalancedNode.right->right->value << endl;
	cout << sumTree(&easyNode) << endl;
	cout << sumTree(&unbalancedNode) << endl;

}