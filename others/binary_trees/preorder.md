
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

## 非递归版本的前序遍历

参考https://www.cnblogs.com/greedyco/p/7182555.html
核心思想：
在二叉树先序遍历非递归算法中，先将根结点压栈，在栈不为空的时候执行循环：
让栈顶元素p出栈，访问栈顶元素p，如果p的右孩子不为空，则让其右孩子先进栈，如果p的左孩子不为空，则再让其左孩子进栈(注意：进栈顺序一定是先右孩子，再左孩子)。

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
        std::stack<TreeNode*> st;
        //ret.push_back(root->val);
        st.push(root);
        while (!st.empty()) {
            TreeNode* tmp = st.top();
            st.pop();
            if (tmp) {
                ret.push_back(tmp->val);
            }
            else {
                break;
            }
            if (tmp->right) {
                st.push(tmp->right);
            }
            if (tmp->left) {
                st.push(tmp->left);
            }
        }
        return ret;
    }
};
```
