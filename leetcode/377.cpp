/* 组合总和Ⅳ
给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。
题目数据保证答案符合 32 位整数范围。

示例 1：
输入：nums = [1,2,3], target = 4
输出：7
解释：
所有可能的组合为：
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
请注意，顺序不同的序列被视作不同的组合。

示例 2：
输入：nums = [9], target = 3
输出：0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum-iv
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <limits.h>             //INT_MAX

using namespace std;

//                                      2021/11/30
int question_377(vector<int>& nums, int target) {
    vector<int> dp(target + 1);
    int sz = nums.size();
    dp[0] = 1;
    //遍历顺序
    for (int i = 1; i <= target; ++i) {
        for (int j = 0; j < sz; ++j) {
            if (i >= nums[j] && dp[i] < INT_MAX - dp[i - nums[j]])
                dp[i] += dp[i - nums[j]];
        }
    }
    return dp[target];
}
