/* 买卖股票的最佳时间Ⅱ
给定一个数组 prices ，其中 prices[i] 是一支给定股票第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:
输入: prices = [7,1,5,3,6,4]
输出: 7
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。

示例 2:
输入: prices = [1,2,3,4,5]
输出: 4
解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。

示例 3:
输入: prices = [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

//                              2021/11/2
int question_122(vector<int>& prices) {
    int cnt = 0;
    int sz = prices.size();
    int pre = prices[0];

    for (int i = 1; i < sz;) {
        while (i < sz && prices[i] < pre) {         //找到比持有股票价高的一天，若低于  则相当于以前没买  买的当前低价股票
            pre = prices[i];
            ++i;
        }
        if (i == sz)
            return cnt;
        int next = prices[i];
        ++i;
        while (i < sz && prices[i] > next) {        //若next后股票价继续涨 则不卖
            next = prices[i];
            ++i;
        }
        cnt += next - pre;
        if (i == sz)
            return cnt;
        pre = prices[i];
        ++i;
    }

    return cnt;

    //dp                        2021/12/4
//    int sz = prices.size();
//    vector<int> dp(sz);
//    dp[0] = 0;
//    int now = prices[0];
//    for (int i = 1; i < sz; ++i) {
//        if (now < prices[i])
//            dp[i] = dp[i - 1] + prices[i] - now;
//        else
//            dp[i] = dp[i - 1];
//        now = prices[i];
//    }
//    return dp[sz - 1];
}
