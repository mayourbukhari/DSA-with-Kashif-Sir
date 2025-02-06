#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

public:
    BST() : root(nullptr) {}
    
    void insert(int value) {
        Node* newNode = new Node(value);

        if (root == nullptr) {
            root = newNode;
            cout << value << " inserted as root\n";
            return;
        }
        
        for (Node* current = root; ; ) {
            if (value < current->data) {
                if (current->left == nullptr) {
                    current->left = newNode;
                    cout << value << " inserted to left of " << current->data << endl;
                    break;
                }
                current = current->left;
            } else {
                if (current->right == nullptr) {
                    current->right = newNode;
                    cout << value << " inserted to right of " << current->data << endl;
                    break;
                }
                current = current->right;
            }
        }
    }
    
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
    
    void display() {
        cout << "BST (Inorder): ";
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    
    for (int i = 0; i < 7; i++) {
        tree.insert(arr[i]);
    }
    
    tree.display();
    return 0;
}