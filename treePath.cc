#include <vector>
#include <stack>
#include <string>
#include <stddef.h>
#include <iostream>
using namespace std;
/**
 *
 *  * Definition for a binary tree node.
 */
 struct TreeNode {

     int val;

     TreeNode *left;

     TreeNode *right;

     TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};



class Solution {

	public:

    vector<string> binaryTreePaths(TreeNode* root) {
    
            
    
            vector<string> result;
    
            vector<int> path;
    
            stack<TreeNode*> node_stack;
    
            TreeNode *last=NULL;
    
            while (root || !node_stack.empty()) {
	    
	                while (root) {
			
			                node_stack.push(root);
			
			                path.push_back(root->val);
			
			                root = root->left;
			
			            }
	    
	                TreeNode *temp = node_stack.top();
	    
	                if (!temp->left && !temp->right) {
			
			                convert_to_string(path,result);
			
			                
			
			            }
	    
	                if (!temp->right && temp->right != last) {
			
			                root = temp->right;
			
			            } else {
				    
				                    last = temp;
				    
				                    node_stack.pop();
				    
				                    path.pop_back();
				    
				                    root = NULL;
				    
				                }
	    
	            }
    
            return result;
    
        }

    void convert_to_string(vector<int>&path, vector<string> &result) {
    
            string ss;
    
            int len = path.size();
    
            for (int i=0; i<len-1; i++) {
	    
	                ss += to_string(path[i]) + "->";
	    
	            }
    
            ss += to_string(path[len-1]);
    
            result.push_back(ss);
    
            return;
    
        }

};

int main(){
	TreeNode node1(1),node2(2),node3(3);
	node1.val = 1;
	node1.left = &node2;
	node1.right = &node3;

	Solution ss;
	vector<string> result = ss.binaryTreePaths(&node1);
	cout << "result " << result.size() << endl;
	return 0;
}
