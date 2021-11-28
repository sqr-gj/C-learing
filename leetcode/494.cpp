/* 目标和
给你一个整数数组 nums 和一个整数 target 。
向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。

示例 1：
输入：nums = [1,1,1,1,1], target = 3
输出：5
解释：一共有 5 种方法让最终目标和为 3 。
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

示例 2：
输入：nums = [1], target = 1
输出：1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/target-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//01背包                              2021/11/26
int question_494(vector<int>& nums, int target) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum < target || (sum - target) % 2)
        return 0;
    target = (sum - target) / 2;
    int sz = nums.size();
    vector<int> dp(target + 1);     //装满容量为i的背包有dp[i]种方式
    dp[0] = 1;
    for (int i = 0; i < sz; ++i) {
        for (int j = target; j >= 0; --j) {
            if (j >= nums[i])
                dp[j] += dp[j - nums[i]];
        }
    }
    return dp[target];
}
