/* 买卖股票的最佳时机 IV
给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1：
输入：k = 2, prices = [2,4,1]
输出：2
解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。

示例 2：
输入：k = 2, prices = [3,2,6,5,0,3]
输出：7
解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

//                                  2021/12/7
int question_123(int k, vector<int>& prices) {
    int sz = prices.size();
    if (sz < 2 || k < 1)
        return 0;
    vector<vector<int>> dp(sz, vector<int>(2 * k));
    for (int i = 0; i < k; ++i)
        dp[0][2 * i] = -prices[0];

    for (int day = 1; day < sz; ++day) {
        for (int i = 0; i < k; ++i) {
            if (i == 0)
                dp[day][2 * i] = max(dp[day - 1][2 * i], -prices[day]);
            else
                dp[day][2 * i] = max(dp[day - 1][2 * i], dp[day - 1][2 * i - 1] - prices[day]);
            dp[day][2 * i + 1] = max(dp[day - 1][2 * i + 1], prices[day] + dp[day - 1][2 * i]);
        }
    }
    return dp[sz - 1][2 * k - 1];
}
