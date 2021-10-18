/* 二叉树的最近公共祖先
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：
“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

示例 1：
输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出：3
解释：节点 5 和节点 1 的最近公共祖先是节点 3 。

示例 2：
输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出：5
解释：节点 5 和节点 4 的最近公共祖先是节点 5 。因为根据定义最近公共祖先节点可以为节点本身。

示例 3：
输入：root = [1,2], p = 1, q = 2
输出：1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree
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

//查找出从根节点到目标节点的路径
void search_tri (TreeNode *root, int target, vector<TreeNode *> &tri, bool &not_find) {
    if (!root)
        return;
    tri.push_back(root);
    if (root->val == target) {
        not_find = false;
        return;
    }

    if (not_find)
        search_tri (root->left, target,tri,not_find);
    if (not_find)
        search_tri (root->right, target,tri,not_find);
    if (not_find)
        tri.pop_back();
}

//                                      2021/10/14
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //p,q在树中的路径
    vector<TreeNode *> tri_p;
    vector<TreeNode *> tri_q;

    bool not_find_p = true;
    bool not_find_q = true;
    search_tri(root, p->val, tri_p, not_find_p);
    search_tri(root, q->val, tri_q, not_find_q);

    //查找最近公共祖先
    int sz = tri_p.size() > tri_q.size() ? tri_q.size() : tri_p.size();
    for (int i = 0; i < sz; ++i) {
        if (tri_p[i]->val != tri_q[i]->val) {
            return tri_p[i - 1];
        }
        if (i == sz - 1 && tri_p[i]->val == tri_q[i]->val)
            return tri_p[sz - 1];
    }
    return nullptr;
}
