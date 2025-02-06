// Binary Tree Construction and Traversal.

// It involves the following key tasks:
// 1. Constructing a binary tree based on a given structure.
// 2. Performing tree traversal operations (inorder, preorder, and postorder).
// 3. Displaying the results of each traversal.


#include <iostream>
using namespace std;

struct TreeNode {
    char value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char val) : value(val), left(nullptr), right(nullptr) {}
};

void inorder(TreeNode* node) {
    if (node) {
        inorder(node->left);
        cout << node->value << " ";
        inorder(node->right);
    }
}

void preorder(TreeNode* node) {
    if (node) {
        cout << node->value << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(TreeNode* node) {
    if (node) {
        postorder(node->left);
        postorder(node->right);
        cout << node->value << " ";
    }
}

int main() {
    
    TreeNode* A = new TreeNode('A');
    TreeNode* B = new TreeNode('B');
    TreeNode* C = new TreeNode('C');
    TreeNode* D = new TreeNode('D');
    TreeNode* E = new TreeNode('E');
    TreeNode* F = new TreeNode('F');
    TreeNode* G = new TreeNode('G');
    TreeNode* H = new TreeNode('H');
    TreeNode* I = new TreeNode('I');
    TreeNode* K = new TreeNode('K');
    TreeNode* L = new TreeNode('L');
    TreeNode* Z = new TreeNode('Z');

    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;
    D->left = F;
    D->right = G;
    C->left = H;
    C->right = I;
    H->left = L;
    H->right = Z;
    L->left = K;
    L->right = G;

    cout << "Inorder Traversal: ";
    inorder(A);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorder(A);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(A);
    cout << endl;

    return 0;
}