/* 二叉树的最大深度
给定一个二叉树，找出其最大深度。
二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree
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

int getdepth (TreeNode *root, int high) {
    if (root == nullptr)
        return high;
    else
        ++high;
//    return (getdepth(root->left, high) > getdepth(root->right, high) ? getdepth(root->left, high) : getdepth(root->right, high));
    //用库函数就不超时？？？
    return max(getdepth(root->left, high), getdepth(root->right, high));
}

//超时                                2021/9/28
int question_104(TreeNode *root) {
    int high = 0;
    return getdepth(root, high);

    //简写
//    if (!root)
//        return 0;
//    return 1 + max(question_104(root->left),question_104(root->right));
}
