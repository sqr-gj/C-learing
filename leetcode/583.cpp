/* 两个字符串的删除操作
给定两个单词 word1 和 word2，找到使得 word1 和 word2 相同所需的最小步数，每步可以删除任意一个字符串中的一个字符。

示例：
输入: "sea", "eat"
输出: 2
解释: 第一步将"sea"变为"ea"，第二步将"eat"变为"ea"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/delete-operation-for-two-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//题解: https://leetcode-cn.com/problems/delete-operation-for-two-strings/solution/dong-gui-by-cao-mu-hui-d-n9hl/

//                                      2021/12/14
int question_583(string word1, string word2) {
    int sz1 = word1.size();
    int sz2 = word2.size();
    vector<vector<int>> dp(sz1 + 1, vector<int>(sz2 + 1));
    //初始化dp
    for (int i = 1; i <= sz1; ++i)
        dp[i][0] = i;
    for (int j = 1; j <= sz2; ++j)
        dp[0][j] = j;

    for (int i = 1; i < sz1 + 1; ++i) {
        for (int j = 1; j < sz2 + 1; ++j) {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]) + 1, dp[i - 1][j - 1] + 2);
        }
    }
    return dp[sz1][sz2];
}
