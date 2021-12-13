/* 不同的子序列
给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。
字符串的一个 子序列 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。
（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）
题目数据保证答案符合 32 位带符号整数范围。

示例 1：
输入：s = "rabbbit", t = "rabbit"
输出：3
解释：
如下图所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
rabbbit
rabbbit
rabbbit

示例 2：
输入：s = "babgbag", t = "bag"
输出：5
解释：
如下图所示, 有 5 种可以从 s 中得到 "bag" 的方案。
babgbag
babgbag
babgbag
babgbag
babgbag

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/distinct-subsequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>

using namespace std;

//                                          2021/12/13
int question_115(string s, string t) {
    int sz1 = s.size();
    int sz2 = t.size();

    //dp[i][j]表示 [0,i - 1] t 在 [0,j - 1] s中有dp[i][j]种 (排列方式?)
    // vector<vector<uint64_t>> dp(sz2 + 1, vector<uint64_t>(sz1 + 1));     //非得要uint64_t
    // for (int i = 0; i < sz1 + 1; ++i) {
    //     dp[0][i] = 1;
    // }

    // for (int i = 1; i < sz2 + 1; ++i) {
    //     for (int j = i; j < sz1 + 1; ++j) {
    //         dp[i][j] = dp[i][j - 1];
    //         if (s[j - 1] == t[i - 1])
    //             dp[i][j] += dp[i - 1][j - 1];
    //     }
    // }
    // return dp[sz2][sz1];

    //dp[i][j]表示 [0,i - 1] s 包含了 dp[i][j]个 [0,j - 1] t
    vector<vector<uint64_t>> dp(sz1 + 1, vector<uint64_t>(sz2 + 1));
    for (int i = 0; i < sz1 + 1; ++i) {
        dp[i][0] = 1;
    }

    for (int i = 1; i < sz1 + 1; ++i) {
        for (int j = 1; j < i + 1; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (s[i - 1] == t[j - 1])
                dp[i][j] += dp[i - 1][j - 1];
        }
    }
    return dp[sz1][sz2];
}
