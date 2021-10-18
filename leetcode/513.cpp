/* 找到树左下角的值
给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
假设二叉树中至少有一个节点。

示例 1:
输入: root = [2,1,3]
输出: 1

示例 2:
输入: [1,2,3,4,null,5,6,null,null,7]
输出: 7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-bottom-left-tree-value
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//层序遍历                      2021/10/11
int question_513(TreeNode *root) {
    vector<TreeNode *> pre{root};
    int left = 0;
    while (!pre.empty()) {
        left = pre[0]->val;
        vector<TreeNode *> next;
        for (auto note : pre) {
            if (note->left)
                next.push_back(note->left);
            if (note->right)
                next.push_back(note->right);
        }
        pre = next;
    }
    return left;
}
