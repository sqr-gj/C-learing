/* 一和零
给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。
如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。

示例 1：
输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
输出：4
解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。
其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满足题意，因为它含 4 个 1 ，大于 n 的值 3 。

示例 2：
输入：strs = ["10", "0", "1"], m = 1, n = 1
输出：2
解释：最大的子集是 {"0", "1"} ，所以答案是 2 。
*/

#include <string>
#include <vector>

using namespace std;

//
pair<int, int> cnt_01 (string s) {
    int p = 0;
    int q = 0;
    for (auto &c : s)
        if (c == '1')
            ++q;
        else
            ++p;
    return {p, q};
}

// 自己做出来的第一道背包？                     2021/11/27
int question_474(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    int sz = strs.size();
    for (int k = 0; k < sz; ++k) {
        pair<int, int> cnt = cnt_01(strs[k]);
        for (int i = m; i >= 0; --i)
            for (int j = n; j >= 0; --j) {
                if (i >= cnt.first && j >= cnt.second)
                    dp[i][j] = max (dp[i - cnt.first][j - cnt.second] + 1, dp[i][j]);
            }
    }
    return dp[m][n];
}
