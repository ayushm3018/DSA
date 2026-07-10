/*
 * LeetCode: 257. Binary Tree Paths
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/binary-tree-paths/
 * Language: C++
 * Runtime: 4 ms | Memory: 17.9 MB
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
    void dfs(TreeNode* root, vector<int>& path, vector<string>& ans) {
        if (root == NULL)
            return;

        path.push_back(root->val);

        // If it's a leaf node, convert the path to a string
        if (root->left == NULL && root->right == NULL) {
            string s = "";

            for (int i = 0; i < path.size(); i++) {
                s += to_string(path[i]);
                if (i != path.size() - 1)
                    s += "->";
            }

            ans.push_back(s);
        }

        dfs(root->left, path, ans);
        dfs(root->right, path, ans);

        // Backtrack
        path.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        vector<int> path;

        dfs(root, path, ans);

        return ans;
    }
};
