#include <stdio.h>
#include <stdlib.h>

typedef int Data;
struct Node {
    Data val;
    struct Node * left;
    struct Node * right;
};

void tree_print (struct Node * tree);
struct Node * tree_add (struct Node * tree, Data x);
void tree_destroy (struct Node * tree);

int main() {
    struct Node *tree=NULL;
    int n;
    while(scanf("%d", &n) && n != 0) {
        tree = tree_add(tree, n);
    }
    n = 0;
    tree_print(tree);
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

void tree_print (struct Node * tree) {
    if (tree == NULL) {
        return;
    }
    if (tree->left!=NULL) {
        tree_print(tree->left);
    }
    if (tree->right!=NULL) {
        tree_print(tree->right);
    }
    if (tree->left==NULL && tree->right==NULL) {
        printf("%d ", tree->val);
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