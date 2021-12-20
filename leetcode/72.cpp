/* 编辑距离
给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
你可以对一个单词进行如下三种操作：
插入一个字符
删除一个字符
替换一个字符

示例 1：
输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')

示例 2：
输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/edit-distance
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>

using namespace std;

//题解:https://leetcode-cn.com/problems/edit-distance/solution/dong-gui-by-cao-mu-hui-d-snzv/

//                                  2021/12/15
int question_72(string word1, string word2) {
    int sz1 = word1.size();
    int sz2 = word2.size();
    vector<vector<int>> dp(sz1 + 1, vector<int>(sz2 + 1));
    for (int i = 1; i <= sz1; ++i)
        dp[i][0] = i;
    for (int j = 1; j <= sz2; ++j)
        dp[0][j] = j;

    for (int i = 1; i < sz1 + 1; ++i) {
        for (int j = 1; j < sz2 + 1; ++j) {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]) + 1, dp[i - 1][j - 1] + 1);
        }
    }
    return dp[sz1][sz2];
}
