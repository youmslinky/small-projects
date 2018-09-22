#include <stdio.h>
//#include <criterion/criterion.h>
#include <stdlib.h> // rand(), malloc(), free()
#include <stddef.h> // NULL

struct node
{
  int value;
  struct node* left;
  struct node* right;
};


void build_tree(struct node* current, int sum)
{
  if (sum > 0) current->value = rand()%sum + 1;
  else current->value = 0;
  sum -= current->value;
  
  if (sum > 0) {
    int part = rand()%16 + 1;
    current->left = (struct node*)malloc(sizeof(struct node));
    current->right = (struct node*)malloc(sizeof(struct node));
    
    build_tree(current->left, sum/part);
    build_tree(current->right, sum - sum/part);
  }
  else {
    current->left = current->right = NULL;
  }
}


void remove_tree(struct node* current)
{
  if (current == NULL) return;
  
  remove_tree(current->left);
  remove_tree(current->right);
  free(current);
}


int sumTheTreeValues(struct node*);


void dotest(int expected)
{
  struct node* root = (struct node*)malloc(sizeof(struct node));
  int actual = 0;
  
  build_tree(root, expected);
  
  actual = sumTheTreeValues(root);
  
  if (root != NULL) remove_tree(root);
  root = NULL;
  
  cr_assert_eq(expected, actual, "Expected %d, but got %d.\n", expected, actual);
}


Test(the_multiply_function, should_pass_all_the_tests_provided)
{
  dotest(4);
  dotest(8);
  dotest(15);
  dotest(16);
  dotest(23);
  dotest(42);
}

// Return the sum of all values in the tree, including the root
int sumTheTreeValues(struct node*) {
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
	//node easyNode = {10, new node {1, nullptr, nullptr}, new node {2, nullptr, nullptr}};
	//node unbalancedNode = {11, new node {5, nullptr, nullptr}, new node {0, nullptr, new node {1, nullptr, nullptr}}};
	//cout << easyNode.left->value << endl;
	//printf("%d\n",easyNode.left->value);
	//cout << unbalancedNode.right->right->value << endl;
	//cout << sumTree(&easyNode) << endl;
	//cout << sumTree(&unbalancedNode) << endl;

	printf("hello\n");

}