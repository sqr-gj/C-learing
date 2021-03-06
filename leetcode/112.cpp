/*路径总和
给你二叉树的根节点 root 和一个表示目标和的整数 targetSum ，判断该树中是否存在根节点到叶子节点的路径，
这条路径上所有节点值相加等于目标和 targetSum 。
叶子节点 是指没有子节点的节点。

示例 1：
输入：root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
输出：true

示例 2：
输入：root = [1,2,3], targetSum = 5
输出：false

示例 3:
输入：root = [1,2], targetSum = 0
输出：false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum
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

//                                  2021/9/1
bool question_112(TreeNode* root, int targetSum) {
    if(root == nullptr)
        return false;
//    if(root->val > targetSum)         //val可能为负数
//        return false;
    if(root->left == nullptr && root->right == nullptr){        //是否为叶子节点
        if(root->val == targetSum)
            return true;
        else
            return false;
    }

    while (true) {
        if(question_112(root->left, targetSum - root->val))
            return true;
        if(question_112(root->right, targetSum - root->val))
            return true;
        return false;
    }
    return false;
}
