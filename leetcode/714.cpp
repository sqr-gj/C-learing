/* 买卖股票的最佳时机含手续费
给定一个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；整数 fee 代表了交易股票的手续费用。
你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。
返回获得利润的最大值。
注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。

示例 1：
输入：prices = [1, 3, 2, 8, 4, 9], fee = 2
输出：8
解释：能够达到的最大利润:
在此处买入 prices[0] = 1
在此处卖出 prices[3] = 8
在此处买入 prices[4] = 4
在此处卖出 prices[5] = 9
总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8

示例 2：
输入：prices = [1,3,7,5,10,3], fee = 3
输出：6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

//                          2021/11/10
int question_714(vector<int>& prices, int fee) {
    int now = prices[0];
    int cnt = 0;
    int next_max = now;
    int sz = prices.size();
    for (int i = 1; i < sz; ++i) {
        if (prices[i] < next_max) {
            if ((next_max - now - fee > 0 && next_max - prices[i] - fee > 0)) {
                cnt += next_max - now - fee;
                now = prices[i];
                next_max = now;
            }
            else {
                if (now > prices[i]){
                    now = prices[i];
                    next_max = now;
                }
            }
        }
        else {
            next_max = prices[i];
        }
    }

    if (next_max - now - fee > 0)
        cnt += next_max - now - fee;
    return cnt;
    //dp                        2021/12/9
//    int sz = prices.size();
//    vector<vector<int>> dp(sz, vector<int>(2));
//    dp[0][0] = -prices[0];
//    for (int i = 1; i < sz; ++i) {
//        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
//        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
//    }

//    return dp[sz - 1][1];
}
