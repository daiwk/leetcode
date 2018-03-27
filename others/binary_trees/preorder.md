
## 递归版本的前序遍历

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (root) {
            ret.push_back(root->val);
            if (root->left) {
                auto a = preorderTraversal(root->left);
                ret.insert(ret.end(),a.begin(), a.end());
            }
            if (root->right) {
                auto a = preorderTraversal(root->right);
                ret.insert(ret.end(),a.begin(), a.end());
            }
        }
        return ret;
    }
};
```
