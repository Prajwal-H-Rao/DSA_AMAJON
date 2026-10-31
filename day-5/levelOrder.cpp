#include <bits/stdc++.h>

#include "../include/tree.h"

using namespace std;

class LevelOrder
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;

        if (!root)
            return {};

        vector<vector<int>> res;
        q.push(root);

        while (!q.empty())
        {
            vector<int> currentLevel;
            int lvlSize = q.size();

            for (int i = 0; i < lvlSize; i++)
            {
                TreeNode *front = q.front();
                q.pop();
                currentLevel.push_back(front->val);

                if (front->left)
                    q.push(front->left);

                if (front->right)
                    q.push(front->right);
            }
            res.push_back(currentLevel);
        }
        return res;
    }
};

int main()
{
    LevelOrder lo;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<vector<int>> result = lo.levelOrder(root);

    for (const auto &level : result)
    {
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}