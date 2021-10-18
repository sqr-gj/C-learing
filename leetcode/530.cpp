/* 二叉搜索树的最小绝对差
给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。

示例：
输入：

   1
    \
     3
    /
   2

输出：
1

解释：
最小绝对差为 1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int min_dif(TreeNode *root, int min, int max) {
    if (!root)
        return 1000000;         //题目保证至少两个节点，故仅叶子节点无效

    int min_val = abs(root->val - min) < abs(root->val - max) ? abs(root->val - min) : abs(root->val - max);
    int min_left = min_dif(root->left, min, root->val);
    int min_right = min_dif(root->right, root->val, max);
    return min_left < min_right ? min_left < min_val ? min_left : min_val : min_right < min_val ? min_right : min_val;
}
//                                  2021/10/13
int getMinimumDifference(TreeNode* root) {
    return min_dif(root->left, -1000000, root->val) < min_dif(root->right, root->val, 1000000) ? min_dif(root->left, -100000, root->val) : min_dif(root->right, root->val, 1000000);
}

