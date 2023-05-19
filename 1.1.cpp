struct Node {
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
};

bool search(int n, Node* root) {
    if (root != nullptr) {
        if (n == root->val) return true;
        else {
            bool left_side = search(n, root->left);
            bool right_side = search(n, root->right);
            if (left_side || right_side)
                return true;
            else return false;
        }
    }
    return false;
}
