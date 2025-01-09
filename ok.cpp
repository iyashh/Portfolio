#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Binary Tree Node Structure
struct Node {
int data;
Node* left;
Node* right;
Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to insert nodes in level order
Node* insertLevelOrder(vector<int>& arr, int i) {
if (i < arr.size()) {
Node* root = new Node(arr[i]);
root->left = insertLevelOrder(arr, 2 * i + 1);
root->right = insertLevelOrder(arr, 2 * i + 2);
return root;
}
return nullptr;
}

// Function to check if a binary tree is complete
bool isComplete(Node* root) {
if (!root) return true;
queue<Node*> q;
q.push(root);
bool end = false;
while (!q.empty()) {
Node* current = q.front();
q.pop();
if (current) {
if (end) return false;
q.push(current->left);
q.push(current->right);
} else {
end = true;
}
}
return true;
}

// Function to check if the binary tree satisfies Max Heap property
bool isMaxHeap(Node* root) {
if (!root) return true;
queue<Node*> q;
q.push(root);
while (!q.empty()) {
Node* current = q.front();
q.pop();
if (current->left) {
if (current->data < current->left->data) return false;
q.push(current->left);
}
if (current->right) {
if (current->data < current->right->data) return false;
q.push(current->right);
}
}
return true;
}

// Main function to check if the binary tree is a Max Heap
int main() {
int n;
cin >> n;
vector<int> arr(n);
for (int i = 0; i < n; i++) {
cin >> arr[i];
}
Node* root = insertLevelOrder(arr, 0);
if (isComplete(root) && isMaxHeap(root)) {
cout << "The binary tree is a Max Heap" << endl;
} else {
cout << "The binary tree is not a Max Heap" << endl;
}
return 0;
}