#include <iostream>
#include <cmath>

using namespace std;
class TreeNode
{
    public:
        // static bool isPerfect(TreeNode* root)
        // {
        //     if(root == NULL)
        //         return true;
        //     if(root->right == nullptr && root->left == nullptr){
        //         return true;
        //     }
        //     if(root->right == nullptr || root->left == nullptr)
        //         return false;
            
        //     return isPerfect(root->right) && isPerfect(root->left);
            
        //     return false;
        // }


        static bool isPerfect(TreeNode* root)
        {
            int count = countNodes(root);
            //this works because a perfect tree (with no values in it) will always be of size (2^n)-1
            //first level 1
            //second level 2
            //etc...
            for(int i=1;i<30;i++){
                if(count==pow(2,i)-1) return true;
            }
        return false;
            
        }

        static int countNodes(TreeNode* root){
            int sum=1;
            if(root->right != nullptr){
                sum += countNodes(root->right);
            }
            if(root->left != nullptr){
                sum += countNodes(root->left);
            }
            return sum;
        }
        
        static TreeNode* leaf() 
        {
            return new TreeNode();
        }

        static TreeNode* join(TreeNode* left, TreeNode* right)
        {
            return (new TreeNode())->withChildren(left, right);
        }
    
        TreeNode* withLeft(TreeNode* left)
        {
            this->left = left;
            return this;
        }
    
        TreeNode* withRight(TreeNode* right)
        {
            this->right = right;
            return this;
        }
    
        TreeNode* withChildren(TreeNode* left, TreeNode* right)
        {
            this->left = left;
            this->right = right;
            return this;
        }
    
        TreeNode* withLeftLeaf()
        {
            return withLeft(leaf());
        }
    
        TreeNode* withRightLeaf()
        {
            return withRight(leaf());
        }
    
        TreeNode* withLeaves()
        {
            return withChildren(leaf(), leaf());
        }
        
    private:
        TreeNode* left;
        TreeNode* right;
        
        TreeNode()
          : left(NULL), right(NULL)
        {
        } 
};

int main(){
    TreeNode* root = TreeNode::leaf()->withLeftLeaf();
    cout << TreeNode::isPerfect(root) << endl;
    cout << TreeNode::countNodes(root) << endl;
    return 0;
}