/* 二叉搜索树中的众数
给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。

假定 BST 有如下定义：
结点左子树中所含结点的值小于等于当前结点的值
结点右子树中所含结点的值大于等于当前结点的值
左子树和右子树都是二叉搜索树
例如：
给定 BST [1,null,2,2],

   1
    \
     2
    /
   2
返回[2].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-mode-in-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <map>
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

//遍历
void search(TreeNode *root, map<int, int> &num_ctn) {
    if (!root)
        return;
    ++num_ctn[root->val];
    search(root->left, num_ctn);
    search(root->right, num_ctn);
}

//额外空间  是否利用搜索二叉树性质直接找出         2021/10/14
vector<int> findMode(TreeNode* root) {
    vector<int> result;
    if (!root)
        return result;

    map<int, int> num_ctn;
    search(root,num_ctn);

    int max = 0;    //计出现最多的次数
    for (auto num : num_ctn) {
        if (num.second > max) {
            result.clear();
            result.push_back(num.first);
            max = num.second;
        }
        else if (num.second == max) {
            result.push_back(num.first);
        }
    }
    return result;
}
