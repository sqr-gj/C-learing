/* 最长回文子序列
给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。
子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。

示例 1：
输入：s = "bbbab"
输出：4
解释：一个可能的最长回文子序列为 "bbbb" 。

示例 2：
输入：s = "cbbd"
输出：2
解释：一个可能的最长回文子序列为 "bb" 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>

using namespace std;

// 题解: https://leetcode-cn.com/problems/longest-palindromic-subsequence/solution/dong-gui-by-cao-mu-hui-d-l5r0/

//                                          2021/12/18
int question_516(string s) {
    int sz = s.size();
    vector<vector<int>> dp(sz, vector<int>(sz));
//    for (int i = 0; i < sz; ++i)
//        dp[i][i] = 1;

    for (int i = sz - 1; i >= 0; --i) {
        dp[i][i] = 1;
        for (int j = i + 1; j < sz; ++j) {
            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
        }
    }
    return dp[0][sz - 1];
}
