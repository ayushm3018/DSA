/*
 * LeetCode: 2385. Amount of Time for Binary Tree to Be Infected
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/
 * Language: C++
 * Runtime: 150 ms | Memory: 195.1 MB
 * 
 * You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.
 * 
 * Each minute, a node becomes infected if:
 * 
 * 	  - The node is currently uninfected.
 * 
 * 	  - The node is adjacent to an infected node.
 * 
 * Return the number of minutes needed for the entire tree to be infected.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: root = [1,5,3,null,4,10,6,9,2], start = 3
 * Output: 4
 * Explanation: The following nodes are infected during:
 * - Minute 0: Node 3
 * - Minute 1: Nodes 1, 10 and 6
 * - Minute 2: Node 5
 * - Minute 3: Node 4
 * - Minute 4: Nodes 9 and 2
 * It takes 4 minutes for the whole tree to be infected so we return 4.
 * 
 * Example 2:
 * 
 * Input: root = [1], start = 1
 * Output: 0
 * Explanation: At minute 0, the only node in the tree is infected so we return 0.
 * 
 *  
 * 
 * Constraints:
 * 
 * 	  - The number of nodes in the tree is in the range [1, 10^5].
 * 
 * 	  - 1 <= Node.val <= 10^5
 * 
 * 	  - Each node has a unique value.
 * 
 * 	  - A node with a value of start exists in the tree.
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
    void markParent(TreeNode* root,
                    unordered_map<TreeNode*, TreeNode*>& parent,
                    TreeNode*& startNode,
                    int start) {

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->val == start)
                startNode = node;

            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }

            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        if (root == NULL)
            return 0;

        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* startNode = NULL;

        markParent(root, parent, startNode, start);

        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;

        q.push(startNode);
        vis[startNode] = true;

        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool infected = false;

            while (size--) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left && !vis[node->left]) {
                    vis[node->left] = true;
                    q.push(node->left);
                    infected = true;
                }

                if (node->right && !vis[node->right]) {
                    vis[node->right] = true;
                    q.push(node->right);
                    infected = true;
                }

                if (parent.count(node) && !vis[parent[node]]) {
                    vis[parent[node]] = true;
                    q.push(parent[node]);
                    infected = true;
                }
            }

            if (infected)
                time++;
        }

        return time;
    }
};
