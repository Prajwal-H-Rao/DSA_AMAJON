#pragma once
#include <iostream>
#include <vector>
using namespace std;

typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int value, TreeNode *leftChild = nullptr, TreeNode *rightChild = nullptr)
        : val(value), left(leftChild), right(rightChild) {}
} TreeNode;

TreeNode *createBinaryTree()
{
    int input;

    cout << "Enter Node Value (-9999 for NULL): ";
    cin >> input;

    if (input == -9999)
        return NULL;

    TreeNode *root = new TreeNode;

    root->val = input;

    cout << "Enter the Left of " << input << ":\n";
    root->left = createBinaryTree();

    cout << "Enter the Right of " << input << ":\n";
    root->right = createBinaryTree();

    return root;
}

int treeSize(TreeNode *root)
{
    if (!root)
        return 0;

    return 1 + treeSize(root->left) + treeSize(root->right);
}

void destroyTree(TreeNode *&root)
{
    if (!root)
        return;

    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
    root = nullptr;
}

int treeHeight(TreeNode *root, int &currHeight)
{
    if (!root)
        return 0;

    return 1 + max(treeHeight(root->left, *(&currHeight + 1)), treeHeight(root->left, *(&currHeight + 1)));
}

int leafNodes(TreeNode *root)
{
    if (!root)
        return 0;

    bool isLeaf = !root->left && !root->right;
    return (isLeaf ? 1 : 0) + leafNodes(root->left) + leafNodes(root->right);
}

vector<TreeNode *> inOrder(TreeNode *root)
{
    if (!root)
        return {};

    vector<TreeNode *> result = inOrder(root->left);

    result.push_back(root);

    vector<TreeNode *> right = inOrder(root->right);

    result.insert(result.end(), right.begin(), right.end());

    return result;
}

vector<TreeNode *> preOrder(TreeNode *root)
{
    if (!root)
        return {};

    vector<TreeNode *> result;
    result.push_back(root);

    vector<TreeNode *> left = preOrder(root->left);
    result.insert(result.end(), left.begin(), left.end());

    vector<TreeNode *> right = preOrder(root->right);
    result.insert(result.end(), right.begin(), right.end());

    return result;
}

vector<TreeNode *> postOrder(TreeNode *root)
{
    if (!root)
        return {};

    vector<TreeNode *> result = postOrder(root->left);

    vector<TreeNode *> right = postOrder(root->right);
    result.insert(result.end(), right.begin(), right.end());

    result.push_back(root);

    return result;
}

void printVectorTree(vector<TreeNode *> tree)
{
    cout << "[ ";

    for (TreeNode *nodeVal : tree)
        cout << nodeVal->val << " ";

    cout << "]" << endl;
    return;
} 