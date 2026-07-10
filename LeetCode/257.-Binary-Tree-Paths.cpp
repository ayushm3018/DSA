/*
 * LeetCode: 257. Binary Tree Paths
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/binary-tree-paths/
 * Language: C++
 * Runtime: 0 ms | Memory: 17.9 MB
 * 
 * Given the root of a binary tree, return all root-to-leaf paths in any order.
 * 
 * A leaf is a node with no children.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: root = [1,2,3,null,5]
 * Output: ["1->2->5","1->3"]
 * 
 * Example 2:
 * 
 * Input: root = [1]
 * Output: ["1"]
 * 
 *  
 * 
 * Constraints:
 * 
 * 	  - The number of nodes in the tree is in the range [1, 100].
 * 
 * 	  - -100 <= Node.val <= 100
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, string path, vector<string>&ans){
        if(root == NULL) return;
        if(path.empty()) path+=to_string(root->val);
        else path+="->" + to_string(root->val);


        if(root->left == NULL and root->right == NULL )
        {ans.push_back(path);
        return;}
        dfs(root->left, path, ans);
        dfs(root->right, path, ans);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        dfs(root, "", ans);

        return ans;
        
        
    }
};
