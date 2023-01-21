#include <bits/stdc++.h>
using namespace std;
 
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int dt): left(NULL), right(NULL), data(dt) {}
};

Node* add(int n, Node* root) {
    if (root == NULL) {
        root = new Node(n);
        return root;
    }
    else {
        if (root->data > n) {
            root->left = add(n, root->left);
            return root;
        }
        else if (root->data < n) {
            root->right = add(n, root->right);
            return root;
        }
    }
    return root;
} 

void destroy(Node* tree) {
    if (tree == NULL) {
        return;
    }
    if (tree->left!=NULL) {
        destroy(tree->left);
    }
    if (tree->right!=NULL) {
        destroy(tree->right);
    }
    delete tree;
}

int height(Node* node) {
    if (node == NULL)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}
 

bool isBalanced(Node* root)
{
    int lh, rh;
    if (root == NULL)
        return 1;
    lh = height(root->left);
    rh = height(root->right);
 
    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;
    return 0;
}
 
int main()
{
    Node *tree = NULL;
    int a;
    while(cin>>a) {
        tree = add(a, tree);
    }
    if (isBalanced(tree))
        cout << "YES";
    else
        cout << "NO";
    destroy(tree);
    return 0;
}