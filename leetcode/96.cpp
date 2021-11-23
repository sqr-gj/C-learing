/* 不同的二叉搜索树
给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。

示例 1：
输入：n = 3
输出：5

示例 2：
输入：n = 1
输出：1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-binary-search-trees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

//                          2021/11/18
int question_96(int n) {
    vector<int> dp(n + 2);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < n + 2; ++i) {
        for (int j = 1; j < i; ++j) {
            dp[i] += dp[i - j] * dp[j];
        }
    }
    return dp[n + 1];
}
