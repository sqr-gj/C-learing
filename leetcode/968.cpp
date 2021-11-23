/* 监控二叉树
给定一个二叉树，我们在树的节点上安装摄像头。
节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。
计算监控树的所有节点所需的最小摄像头数量。

示例 1：
输入：[0,0,null,0,0]
输出：1
解释：如图所示，一台摄像头足以监控所有节点。

示例 2：
输入：[0,0,null,0,null,0,null,null,0]
输出：2
解释：需要至少两个摄像头来监视树的所有节点。 上图显示了摄像头放置的有效位置之一。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-cameras
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

int set_camera (TreeNode* root, int &cnt) {
    if (!root)
        return 1;
    int left = set_camera(root->left, cnt);
    int right = set_camera(root->right, cnt);

    if (left == 1 && right == 1)        //叶子节点
        return 0;

    if (left == 0 || right == 0) {      //叶子节点父节点
        ++cnt;
        return 2;
    }

    if (left == 2 || right == 2)        //摄像头父节点
        return 1;
    return -1;
}

//                                      2021/11/12
int question_968(TreeNode* root) {
    int cnt = 0;
    if (set_camera(root, cnt) == 0)
        ++cnt;
    return cnt;
}
