// 00543: Diameter of Binary Tree
// https://leetcode.com/problems/diameter-of-binary-tree/

#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* creator(vector<int> values, TreeNode** root, int i, int n) {
    if (n==0) return NULL;
    if (i<n) {
        TreeNode *temp = new TreeNode(values[i]);
        *root = temp;
        (*root)->left = creator(values, &((*root)->left), 2*i+1, n);
        (*root)->right = creator(values, &((*root)->right), 2*i+2, n);
    }
    return *root;
};

void createTree(TreeNode** root, vector<int> inputs) {
    creator(inputs, root, 0, inputs.size());
}

void showTree(TreeNode* root) {
    queue<TreeNode*> q;
    vector<vector<int>> result = {};
    vector<int> c;
    if (root==NULL) { cout << "Empty !" << endl; return; }
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        TreeNode *t = q.front();
        q.pop();
        if (t==NULL) {
            result.push_back(c);
            c.resize(0);
            if (q.size() > 0) q.push(NULL);
        } else {
            c.push_back(t->val);
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
        }
    }

    cout<<"["; for (auto x : result) {
        cout<<"["; for (auto y : x) {
            if (!y) { cout << "NULL,"; continue; }
            cout<<y<<",";
        } cout<<"\b],";
    } cout<<"\b]"<<endl;
}

class Solution {
private:
    int dfs(TreeNode* root, int& result) {
        if (root == NULL) return 0;

        int left = dfs(root->left, result);
        int right = dfs(root->right, result);

        result = max(result, left + right);
        return 1 + max(left, right);
    }

public:
    // SOLUTION
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        int result = 0;
        dfs(root, result);
        return result;
    }

};



int main() {
    Solution o;
    TreeNode* root = NULL;

    // INPUT
    vector<int> tn = {1,2,3,4,5};
    createTree(&root, tn);

    // OUTPUT
    auto result = o.diameterOfBinaryTree(root);
    cout << result << endl;

    return 0;
}
