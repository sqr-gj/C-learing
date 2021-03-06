/* 修剪二叉搜索树
给你二叉搜索树的根节点 root ，同时给定最小边界low 和最大边界 high。通过修剪二叉搜索树，使得所有节点的值在[low, high]中。
修剪树不应该改变保留在树中的元素的相对结构（即，如果没有被移除，原有的父代子代关系都应当保留）。 可以证明，存在唯一的答案。
所以结果应当返回修剪好的二叉搜索树的新的根节点。注意，根节点可能会根据给定的边界发生改变。

示例 1：
输入：root = [1,0,2], low = 1, high = 2
输出：[1,null,2]

示例 2：
输入：root = [3,0,4,null,2,null,null,1], low = 1, high = 3
输出：[3,2,null,1]

示例 3：
输入：root = [1], low = 1, high = 2
输出：[1]

示例 4：
输入：root = [1,null,2], low = 1, high = 3
输出：[1,null,2]

示例 5：
输入：root = [1,null,2], low = 2, high = 4
输出：[2]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/trim-a-binary-search-tree
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

//                                          2021/10/18
TreeNode* question_669(TreeNode* root, int low, int high) {
    if (!root)
        return nullptr;
    if (root->val > high) {                         //递归左子树，减去root及其右子树
        root->left = question_669(root->left, low, high);
        return root->left;
    }
    else if (root->val < low) {                     //递归右子树，减去root及其左子树
        root->right = question_669(root->right, low, high);
        return root->right;
    }
    else {
        root->left = question_669(root->left, low, high);
        root->right = question_669(root->right, low, high);
    }
    return root;
}
