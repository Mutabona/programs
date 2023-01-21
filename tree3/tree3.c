#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef int Data;
struct Node {
    Data val;
    struct Node * left;
    struct Node * right;
};

int isBalanced(struct Node* root);
int height(struct Node* node);
struct Node * tree_add (struct Node * tree, Data x);
void tree_destroy (struct Node * tree);

int main() {
    struct Node *tree=NULL;
    int n;
    while(scanf("%d", &n) && n != 0) {
        tree = tree_add(tree, n);
    }
    if (isBalanced(tree)) {
        printf("YES");
    }
    else {
        printf("NO");
    }
    tree_destroy(tree);
    return 0;
}

struct Node * tree_add(struct Node * tree, Data x) {
    if (tree == NULL) {
        tree = (struct Node *)malloc(sizeof(struct Node));
        tree->left = NULL;
        tree->right = NULL;
        tree->val = x;
        return tree;
    }
    else if (x < tree->val) {
        tree->left = tree_add(tree->left, x);
        return tree;
    }
    else if (x > tree->val) {
        tree->right = tree_add(tree->right, x);
        return tree;
    }
    else {
        return tree;
    }
}

void tree_destroy (struct Node * tree) {
    if (tree == NULL) {
        return;
    }
    if (tree->left!=NULL) {
        tree_destroy(tree->left);
    }
    if (tree->right!=NULL) {
        tree_destroy(tree->right);
    }
    free(tree);
}

int height(struct Node* node) {
    if (node == NULL)
        return 0;
    int hl = height(node->left), hr = height(node->right);
    return 1 + (hl>=hr?hl:hr);
}

int isBalanced(struct Node* root) {
    int lh, rh;
    if (root == NULL)
        return 1;
    lh = height(root->left);
    rh = height(root->right);
 
    if ((abs(lh - rh) <= 1) && isBalanced(root->left) && isBalanced(root->right))
        return 1;
    return 0;
}