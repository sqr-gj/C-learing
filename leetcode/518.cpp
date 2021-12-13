/* 零钱兑换Ⅱ
给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。
请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。
假设每一种面额的硬币有无限个。
题目数据保证结果符合 32 位带符号整数。

示例 1：
输入：amount = 5, coins = [1, 2, 5]
输出：4
解释：有四种方式可以凑成总金额：
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

示例 2：
输入：amount = 3, coins = [2]
输出：0
解释：只用面额 2 的硬币不能凑成总金额 3 。

示例 3：
输入：amount = 10, coins = [10]
输出：1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/coin-change-2
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

//                      2021/11/29
int question_518(int amount, vector<int>& coins) {
    int sz = coins.size();
    vector<int> dp(amount + 1);
    dp[0] = 1;
    for (int i = 0; i < sz; ++i) {
        int weight = coins[i];
        for (int j = weight; j <= amount; ++j) {
            dp[j] += dp[j - weight];
        }
    }
    return dp[amount];
}
