/* 整数拆分
给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。

示例 1:

输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1。
示例 2:

输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/integer-break
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

//                              2021/11/17
int question_343(int n) {
    if (n == 2 || n == 3)
        return n - 1;
    vector<int> dp(n + 1);
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4; i < n + 1; ++i) {
        int k = i / 2 + 1;
        for (int j = 2; j < k; ++j)
            dp[i] = dp[i] > (dp[i - j] * dp[j]) ? dp[i] : (dp[i - j] * dp[j]);      //dp[i] = max(dp[i-j] * dp[j])
    }
    return dp[n];
}
