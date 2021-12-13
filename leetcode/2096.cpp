/* 从二叉树一个节点到另一个节点每一步的方向
给你一棵 二叉树 的根节点 root ，这棵二叉树总共有 n 个节点。每个节点的值为 1 到 n 中的一个整数，且互不相同。给你一个整数 startValue ，
表示起点节点 s 的值，和另一个不同的整数 destValue ，表示终点节点 t 的值。
请找到从节点 s 到节点 t 的 最短路径 ，并以字符串的形式返回每一步的方向。每一步用 大写 字母 'L' ，'R' 和 'U' 分别表示一种方向：
'L' 表示从一个节点前往它的 左孩子 节点。
'R' 表示从一个节点前往它的 右孩子 节点。
'U' 表示从一个节点前往它的 父 节点。
请你返回从 s 到 t 最短路径 每一步的方向。

示例 1：
输入：root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
输出："UURL"
解释：最短路径为：3 → 1 → 5 → 2 → 6 。

示例 2：
输入：root = [2,1], startValue = 2, destValue = 1
输出："L"
解释：最短路径为：2 → 1 。
*/

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

void find_value (TreeNode* root, int Value, string &road ,bool &find_road) {
    if (!root)
        return;
    if (root->val == Value) {
        find_road = true;
        return;
    }
    road += 'L';
    find_value(root->left, Value, road, find_road);
    if (find_road)
        return;
    road[road.size() - 1] = 'R';
    find_value(root->right, Value, road, find_road);
    if (find_road)
        return;
    road.erase(road.size() - 1);
}

//                                              2021/12/6
string getDirections(TreeNode* root, int startValue, int destValue) {
    string to_start;
    string to_dest;
    bool sign;
    find_value(root, startValue, to_start, sign);
    sign = false;
    find_value(root, destValue, to_dest, sign);

    int ptr = 0;
    while (to_start[ptr] == to_dest[ptr]){++ptr;}
    string result(to_start.size() - ptr, 'U');
    result += string(to_dest.begin() + ptr, to_dest.end());
    return result;
}
