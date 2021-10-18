/* 验证二叉搜索树
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

有效 二叉搜索树定义如下：
节点的左子树只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。

示例 1：
输入：root = [2,1,3]
输出：true

示例 2：
输入：root = [5,1,4,null,null,3,6]
输出：false
解释：根节点的值是 5 ，但是右子节点的值是 4 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/validate-binary-search-tree
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

//                                          2021/10/13
bool isValid(TreeNode *root, long int min, long int max) {
    if (!root)
        return true;
    if (root->val <= min || root->val >= max)       //每个节点数值都应存在一个范围
        return false;

    return isValid(root->left, min, root->val) && isValid(root->right, root->val, max);   //左子树数值变小更新上限，右子树数值变大更新下限
}

bool question_98(TreeNode* root) {
    if (!root)
        return true;

    return isValid(root->left, -2147483649, root->val) && isValid(root->right, root->val, 2147483648);     //测试用例还真弄到了2^31
}
