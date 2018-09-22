#include <iostream>
#include <vector>

using namespace std;

class TreeNode 
{
  public:
  	TreeNode* m_left;
    TreeNode* m_right;
    int m_value;
    TreeNode(int value, TreeNode* left, TreeNode* right)
    	: m_value(value), m_left(left), m_right(right)
    {
    }

    TreeNode(int value)
    	: m_value(value), m_left(NULL), m_right(NULL)
    {
    }
};

class Solution
{
  public:
    static TreeNode* arrayToTree(std::vector<int> arr) 
    {
    	int levelWidth = 1;	//width of current level
    	int levels = 1;
    	int lowLevelElements = arr.size();
    	for(int i=1;i<arr.size();i+=levelWidth){
    		levels++;
    		lowLevelElements -= levelWidth;
    		levelWidth *= 2;
    	}
    	//form bottom layer
    	for(int i=0;i<levels;i++){
    		
    	}
    	cout << lowLevelElements;
        return NULL;
    }
};


int main(){
	cout << "hello" << endl;
	std::vector<int> arr = {17, 0, -4, 3, 15};
	TreeNode* expected = new TreeNode(17, new TreeNode(0, new TreeNode(3), new TreeNode(15)), new TreeNode(-4));
	Solution::arrayToTree(arr);
	cout << endl;
	return 0;
}