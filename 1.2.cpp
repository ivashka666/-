class Solution
{
private:
    static void calculateMaxSum(TreeNode* node, int& max_sum, int curr_sum) {
        if (node == nullptr) return;
        if (node->left == nullptr && node->right == nullptr && (curr_sum + node->value) > max_sum) {
            max_sum = curr_sum + node->value;
            return;
        }
        calculateMaxSum(node->left, max_sum, curr_sum + node->value);
        calculateMaxSum(node->right, max_sum, curr_sum + node->value);
    }

public:
    static int getMaxSum(TreeNode* root)
    {
        int max_sum = 0;
        calculateMaxSum(root, max_sum, 0);
        return max_sum;
    }
};
