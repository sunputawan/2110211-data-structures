// Your code here

int maxImbalance = -1;
KeyT maxImbalanceKey = KeyT();
int abs(int a) {
    return (a > 0) ? a : -a;
}
int height(node *n) {
    if(n == NULL) return -1;
    int leftHeight = height(n->left);
    int rightHeight = height(n->right);
    int diff = abs(leftHeight - rightHeight);
    if(maxImbalance < diff) {
        maxImbalance = diff;
        maxImbalanceKey = n->data.first;
    }
    else if(diff == maxImbalance) {
        maxImbalanceKey = std::min(maxImbalanceKey, n->data.first);
    }

    return 1 + std::max(leftHeight, rightHeight);

}
KeyT getValueOfMostImbalanceNode() {
    // Your code here
    height(mRoot);
    return maxImbalanceKey;
}
