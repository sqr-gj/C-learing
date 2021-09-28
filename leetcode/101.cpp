/* 对称二叉树
给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3

但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/symmetric-tree
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

//层序遍历                      2021/9/28
bool question_101(TreeNode* root) {
    if (!root)
        return true;
    vector<TreeNode *> tree_pre{root};
    vector<TreeNode *> tree_next;
    while (!tree_pre.empty()) {
        //遍历下一层元素
        tree_next.clear();
        for (auto Node : tree_pre) {
            tree_next.push_back(Node->left);
            tree_next.push_back(Node->right);
        }

        //判断是否对称
        int left = 0;
        int right = tree_next.size() - 1;
        while (left < right) {
            if (tree_next[left] == nullptr) {
                //均为空指针
                if (tree_next[right] == nullptr){
                    ++left;
                    --right;
                    continue;
                }
                //左为空  右非空
                else {
                    return false;
                }
            }
            else {
                //左非空  右为空
                if (tree_next[right] == nullptr){
                    return false;
                }
                //均不为空
                else {
                    if (tree_next[left]->val == tree_next[right]->val) {
                        ++left;
                        --right;
                        continue;
                    }
                    else {
                        return false;
                    }
                }
            }
        }

        //更新pre
        tree_pre.clear();
        for (auto Node : tree_next) {
            if (Node)
                tree_pre.push_back(Node);
        }
    }
    return true;
}
