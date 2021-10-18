/* 二叉树的所有路径
给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。
叶子节点 是指没有子节点的节点。

示例 1：
输入：root = [1,2,3,null,5]
输出：["1->2->5","1->3"]

示例 2：
输入：root = [1]
输出：["1"]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-paths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>

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
void get_Paths(TreeNode *root, string s, vector<string> &Paths) {
    if (root->left == nullptr && root->right == nullptr) {          //判断为叶子节点时加入并返回
        s += to_string(root->val);
        Paths.push_back(s);
        return;
    }

    s += to_string(root->val);
    s += "->";
    if (root->left)
    get_Paths(root->left, s, Paths);        //左子树路径
    if (root->right)
    get_Paths(root->right, s, Paths);       //右子树路径
}

//                          2021/9/30
vector<string> question_257(TreeNode* root) {
    vector<string> Paths;
    string s;
    if (!root)
        return Paths;
    get_Paths(root, s, Paths);
    return Paths;
}
