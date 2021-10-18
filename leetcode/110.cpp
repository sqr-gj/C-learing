/* 平衡二叉树
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。



示例 1：


输入：root = [3,9,20,null,null,15,7]
输出：true
示例 2：


输入：root = [1,2,2,3,3,null,null,4,4]
输出：false
示例 3：

输入：root = []
输出：true

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/balanced-binary-tree
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

//
int getdepth(TreeNode *root) {
    if (!root)
        return 0;
    int left_depth = getdepth(root->left);
    if (left_depth == -1)
        return -1;

    int right_depth = getdepth(root->right);
    if (right_depth == -1)
        return -1;

    return abs(left_depth - right_depth) < 2 ? 1 + max(left_depth, right_depth) : -1;

}

//                                  2021/9/29
bool question_110(TreeNode *root) {
    if (!root)
        return true;
    return getdepth(root) == -1 ? false : true;
}
