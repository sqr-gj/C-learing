/* 删除二叉搜索树中的节点
给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。
返回二叉搜索树（有可能被更新）的根节点的引用。

一般来说，删除节点可分为两个步骤：
首先找到需要删除的节点；
如果找到了，删除它。

示例 1:
输入：root = [5,3,6,2,4,null,7], key = 3
输出：[5,4,6,2,null,null,7]
解释：给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。
一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。
另一个正确答案是 [5,2,6,null,4,null,7]。

示例 2:
输入: root = [5,3,6,2,4,null,7], key = 0
输出: [5,3,6,2,4,null,7]
解释: 二叉树不包含值为 0 的节点

示例 3:
输入: root = [], key = 0
输出: []

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/delete-node-in-a-bst
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//                                      2021/10/15
TreeNode* question_450(TreeNode* root, int key) {
    if (!root)
        return nullptr;
    if (root->val == key) {             //找到后 更新节点
        if (!root->left)               //左子树为空时返回右子树（右子树为空即为nullptr） 右子树同理
            return root->right;
        if (!root->right)
            return root->left;

        //左右子树均不为空      （找出右子树中最小值代替删除的节点）
        TreeNode *pre = root->right;

        if (pre->left) {
            TreeNode *next = pre->left;
            while (next->left) {
                pre = next;
                next = next->left;
            }
            pre->left = next->right;
            next->left = root->left;
            next->right = root->right;
            return next;
        }
        else {
            pre->left = root->left;
            return pre;
        }

    }
    else if (root->val  < key)
        root->right = question_450(root->right, key);
    else
        root->left = question_450(root->left, key);

    return root;
}
