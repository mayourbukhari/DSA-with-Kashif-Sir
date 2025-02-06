#include <iostream>
using namespace std;

// Define a TreeNode structure
struct TreeNode {
    char value;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(char val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to search and replace in Inorder traversal
bool searchAndReplaceInorder(TreeNode* node, char target, char newValue) {
    if (node) {
        if (searchAndReplaceInorder(node->left, target, newValue))
            return true;
        if (node->value == target) {
            node->value = newValue;
            return true;
        }
        return searchAndReplaceInorder(node->right, target, newValue);
    }
    return false;
}

// Function to search and replace in Preorder traversal
bool searchAndReplacePreorder(TreeNode* node, char target, char newValue) {
    if (node) {
        if (node->value == target) {
            node->value = newValue;
            return true;
        }
        if (searchAndReplacePreorder(node->left, target, newValue))
            return true;
        return searchAndReplacePreorder(node->right, target, newValue);
    }
    return false;
}

// Function to search and replace in Postorder traversal
bool searchAndReplacePostorder(TreeNode* node, char target, char newValue) {
    if (node) {
        if (searchAndReplacePostorder(node->left, target, newValue))
            return true;
        if (searchAndReplacePostorder(node->right, target, newValue))
            return true;
        if (node->value == target) {
            node->value = newValue;
            return true;
        }
    }
    return false;
}

// Utility function to perform Inorder traversal and display the tree
void inorder(TreeNode* node) {
    if (node) {
        inorder(node->left);
        cout << node->value << " ";
        inorder(node->right);
    }
}

int main() {
    // Create nodes
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

    // Connect nodes to construct the tree
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

    // Display the original tree
    cout << "Original Tree (Inorder Traversal): ";
    inorder(A);
    cout << endl;

    // Perform search and replace using Inorder traversal
    if (searchAndReplaceInorder(A, 'D', 'X')) {
        cout << "Node with value 'D' replaced with 'X' using Inorder traversal." << endl;
    } else {
        cout << "Node with value 'D' not found in Inorder traversal." << endl;
    }

    // Display the updated tree
    cout << "Updated Tree (Inorder Traversal): ";
    inorder(A);
    cout << endl;

    return 0;
}