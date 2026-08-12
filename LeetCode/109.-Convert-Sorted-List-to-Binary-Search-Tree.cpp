/*
 * LeetCode: 109. Convert Sorted List to Binary Search Tree
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
 * Language: C++
 * Runtime: 3 ms | Memory: 33.1 MB
 * 
 * Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced binary search tree.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: head = [-10,-3,0,5,9]
 * Output: [0,-3,9,-10,null,5]
 * Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
 * 
 * Example 2:
 * 
 * Input: head = []
 * Output: []
 * 
 *  
 * 
 * Constraints:
 * 
 * 	  - The number of nodes in head is in the range [0, 2 * 10^4].
 * 
 * 	  - -10^5 <= Node.val <= 10^5
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL; //!head is same as head==NULL
        if(head->next==NULL) return new TreeNode(head->val);

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* slowPrev=NULL;

        while(fast!=NULL and fast->next!=NULL){
            slowPrev = slow;
            slow = slow->next;
            fast = fast->next->next;

        }
        TreeNode* root = new TreeNode(slow->val);
        slowPrev->next = NULL;
        root->left = sortedListToBST(head);

        root->right = sortedListToBST(slow->next);
        return root;
    }
};
