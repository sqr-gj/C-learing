/* 一手顺子
Alice 手中有一把牌，她想要重新排列这些牌，分成若干组，使每一组的牌数都是 groupSize ，并且由 groupSize 张连续的牌组成。
给你一个整数数组 hand 其中 hand[i] 是写在第 i 张牌，和一个整数 groupSize 。如果她可能重新排列这些牌，返回 true ；否则，返回 false 。

示例 1：
输入：hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
输出：true
解释：Alice 手中的牌可以被重新排列为 [1,2,3]，[2,3,4]，[6,7,8]。

示例 2：
输入：hand = [1,2,3,4,5], groupSize = 4
输出：false
解释：Alice 手中的牌无法被重新排列成几个大小为 4 的组。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/hand-of-straights
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//                                  2021/12/30
bool question_846(vector<int>& hand, int groupSize) {
    int sz = hand.size();
    if (sz % groupSize != 0)
        return false;
    sort (hand.begin(), hand.end());
    unordered_map<int, int> hand_num;
    for (int i = 0; i < sz; ++i)
        ++hand_num[hand[i]];
    for (int i = 0; i < sz; ++i) {
        if (hand_num.count(hand[i]) && hand_num[hand[i]] > 0) {
            for (int j = hand[i]; j < hand[i] + groupSize; ++j) {
                if (hand_num.count(j) && hand_num[j] > 0)
                    --hand_num[j];
                else
                    return false;
            }
        }
    }
    return true;
}
