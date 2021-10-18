/* 从中序和后序遍历序列构造二叉树
根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出
中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
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

//                              2021/10/11
TreeNode * question_106(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.empty())
        return nullptr;
    int root_val = postorder[postorder.size() - 1];         //leetcode咋需要把这提到前面来  不然出错
    TreeNode *root = new TreeNode(root_val);
    if (inorder.size() == 1) {
        return root;
    }
    int i = 0;
    int size_in = inorder.size();
    for (; i < size_in; ++i) {              //找到根节点并区分左子树元素及右子树元素
        if (inorder[i] == root_val)
            break;
    }

    vector<int> inorder_left {inorder.begin(), inorder.begin() + i};
    vector<int> inorder_right {inorder.begin() + i + 1, inorder.end()};
    vector<int> postorder_left {postorder.begin(), postorder.begin() + i};
    vector<int> postorder_right {postorder.begin() + i, postorder.end() - 1};

    root->left = question_106(inorder_left, postorder_left);            //左子树
    root->right = question_106(inorder_right, postorder_right);            //右子树
    return root;
}
