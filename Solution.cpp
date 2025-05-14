class Solution {
public:
    typedef unsigned long long ll;  // To handle large indices without overflow

    /**
     * Function to compute the maximum width of a binary tree.
     * The width is defined as the length between the end-nodes
     * (the leftmost and rightmost non-null nodes) at each level.
     */
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;

        // Queue stores pairs of TreeNode and its position index in the tree
        queue<pair<TreeNode*, ll>> que;
        que.push({root, 0});  // Start from root at index 0

        ll maxWidth = 0;

        while (!que.empty()) {
            int n = que.size();
            ll f = que.front().second;  // Index of first node at current level
            ll l = que.back().second;   // Index of last node at current level

            // Width is last index - first index + 1
            maxWidth = max(maxWidth, l - f + 1);

            // Process all nodes at the current level
            while (n--) {
                TreeNode* curr = que.front().first;
                ll d = que.front().second - f;  // Normalize indices to avoid overflow
                que.pop();

                // Push left and right children with calculated indices
                if (curr->left)
                    que.push({curr->left, 2 * d + 1});
                if (curr->right)
                    que.push({curr->right, 2 * d + 2});
            }
        }

        return maxWidth;
    }
};
