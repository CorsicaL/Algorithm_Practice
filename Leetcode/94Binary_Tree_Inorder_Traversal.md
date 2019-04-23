## 94Binary_Tree_Inorder_Traversal

**题目描述**：给定一个二叉树，返回他的中序遍历。

**示例:**

```
输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
```

**二叉树遍历**：

```
		↓			//第一次从父节点向下访问后就输出：前序
		o
	  ↗  ↖		//第一次从左儿子返回后输出：中序；右儿子：后序
```

**递归**

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
    vector<int> ans;
        
    void visit(TreeNode *u) {
        // ans.push_back(u->val);	//前序
        
        if (u->left != NULL) {
            visit(u->left);
        }
        
        ans.push_back(u->val);	//中序
        
        if (u->right != NULL) {
            visit(u->right);
        }
        
        // ans.push_back(u->val);	//后序
        
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return ans;
        }
        
        visit(root);
        return ans;
    }
};
```



**非递归**

注意访问过后要标记

```c++
class Solution {
public:
    vector<int> ans;
    map<TreeNode*, bool> vis;	//是否输出过的标记
    void visit(TreeNode *u) {
        stack<TreeNode*> stack;	//访问的栈
        stack.push(u);
        while (!stack.empty()) {
            u = stack.top();
            if (u->left != NULL && !vis[u->left]) {
                stack.push(u->left);
                continue;
            }
            if (!vis[u]) {		//u没有输出过，第一次从左儿子回来
                ans.push_back(u->val);	//u应该被输出
                vis[u] = true;			//u已经输出过，标记为true
            }
            if (u->right != NULL && !vis[u->right]) {
                stack.push(u->right);
                continue;
            }
            stack.pop();
        }
        
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return ans;
        }
        
        visit(root);
        return ans;
    }
};
```

