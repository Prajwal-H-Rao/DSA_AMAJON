#include <bits/stdc++.h>
#include "../include/tree.h"

using namespace std;

class InOrderTraversal
{
private:
    void dfs(TreeNode *root, vector<int> &inOrderVector)
    {
        if (!root)
            return;

        dfs(root->left, inOrderVector);
        inOrderVector.push_back(root->val);
        dfs(root->right, inOrderVector);
    }

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        dfs(root, res);
        return res;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> res = InOrderTraversal().inorderTraversal(root);

    cout << "{";
    for (int ele : res)
        cout << ele << " ";
    cout << "}" << endl;

    return 0;
}