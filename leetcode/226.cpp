/* 翻转二叉树
翻转一棵二叉树。

示例：
输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/invert-binary-tree
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

//递归                                2021/9/27
TreeNode* question_226(TreeNode* root) {
    if (!root || (!root->left && !root->right))
        return root;

    TreeNode *Node = root->left;
    root->left = root->right;
    root->right = Node;

    question_226(root->left);
    question_226(root->right);

    return root;
}
