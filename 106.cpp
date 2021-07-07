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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size() - 1;
        int m = postorder.size() - 1;
         return build(inorder,postorder,0,n,0,m);
    }
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,int l1,int r1,int l2,int r2){
        if(l1 > r1||l2 > r2)
        return nullptr;
        int temp = postorder[r2];
        TreeNode* root = new TreeNode(temp);
        int mid = l1;
        while(inorder[mid] != temp) mid++;
        int lsize = mid - l1;
        root->left = build(inorder,postorder,l1,mid -1,l2,l2+lsize-1);
        root->right = build(inorder,postorder,mid +1,r1,l2+lsize,r2-1);
        return root;



    }
};
