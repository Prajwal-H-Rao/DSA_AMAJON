#include <bits/stdc++.h>
#include <vector>
#include "../include/n-ary-tree.h"

using namespace std;

class mMxDepthNary
{

public:
    int maxDepth(Node *root)
    {
        if (!root)
            return 0;

        int height = 0;

        for (Node *node : root->children)
        {
            height = max(height, maxDepth(node));
        }

        return 1 + height;
    }
};

int main()
{
    Node *root = new Node(1);
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(3));
    root->children.push_back(new Node(4));
    root->children[0]->children.push_back(new Node(5));
    root->children[0]->children.push_back(new Node(6));

    mMxDepthNary mxDepth;
    int depth = mxDepth.maxDepth(root);

    cout << "Max Depth of N-ary Tree: " << depth << endl;

    return 0;
}