/* 左叶子之和
计算给定二叉树的所有左叶子之和。

示例：

    3
   / \
  9  20
    /  \
   15   7

在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-left-leaves
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

//
void get_left(TreeNode *root, bool is_left, int &sum) {
    if (root->left == nullptr && root->right == nullptr) {          //判断为叶子节点
        if (is_left)                                                //且为左叶子节点
            sum += root->val;
        return;
    }
    if (root->left)
    get_left(root->left, true, sum);        //左子树路径
    if (root->right)
    get_left(root->right, false, sum);       //右子树路径
}

//                              2021/9/30
int sumOfLeftLeaves(TreeNode* root) {
    int sum = 0;
    if (!root)
        return sum;
    if (root->left)                     //确保不传递空节点
        get_left(root->left, true, sum);        //左子树路径
    if (root->right)
        get_left(root->right, false, sum);       //右子树路径
    return sum;
}
