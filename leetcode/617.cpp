/*合并二叉树
给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。
你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点
将直接作为新二叉树的节点。

示例 1:
输入:
    Tree 1                     Tree 2
          1                         2
         / \                       / \
        3   2                     1   3
       /                           \   \
      5                             4   7
输出:
合并后的树:
         3
        / \
       4   5
      / \   \
     5   4   7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-binary-trees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//                                  2021/8/20
TreeNode* question_617(TreeNode* root1, TreeNode* root2) {
    if(root1 == nullptr || root2 == nullptr)
        return (root1 == nullptr) ? root2 : root1;

    root1->val += root2->val;
    root1->left = question_617(root1->left, root2->left);
    root1->right = question_617(root1->right, root2->right);
//    if(root2->left != nullptr){
//        if(root1->left != nullptr)
//            question_617(root1->left, root2->left);
//        else
//            root1->left = root2->left;
//    }

//    if(root2->right != nullptr){
//        if(root1->right != nullptr)
//            question_617(root1->right, root2->right);
//        else
//            root1->right = root2->right;
//    }
    return root1;
}
