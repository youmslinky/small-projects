#include <iostream>

using namespace std;

class TreeNode
{
    public:
        TreeNode* left;
        TreeNode* right;
        int value;
};

class Solution
{
  public:
    static int maxSum(TreeNode* root)
    {
    	if(root == NULL)
    		return 0;
        int sum = root->value;
        int leftSum = sum;
        int rightSum = sum;
        if(root->left != nullptr){
        	leftSum += maxSum(root->left);
        }
        if(root->right != nullptr){
        	rightSum += maxSum(root->right);
        }
        if(leftSum > rightSum)
        	return leftSum;
        else
        	return rightSum;

        return -1;
    }
};

int main(){

	TreeNode easyNode = {new TreeNode {nullptr, nullptr, 1}, new TreeNode {new TreeNode {nullptr, nullptr, 1}, nullptr, 1},10};
	TreeNode* root = NULL;
	cout << Solution::maxSum(root) << endl;
	return 0;
}