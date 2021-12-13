/* 打家劫舍Ⅱ
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。
同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。

示例 1：
输入：nums = [2,3,2]
输出：3
解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。

示例 2：
输入：nums = [1,2,3,1]
输出：4
解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
     偷窃到的最高金额 = 1 + 3 = 4 。

示例 3：
输入：nums = [0]
输出：0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

//                          2021/12/2
int question_213(vector<int>& nums) {
    int sz = nums.size();
    int temp = nums[sz - 1];
    if (sz == 1)
        return nums[0];
    if (sz == 2)
        return max(nums[0], nums[1]);
    if (sz == 3)
        return max(max(nums[0], nums[1]), nums[2]);
    vector<int> nums_0(sz);
    nums_0[1] = nums[1];
    nums_0[2] = max(nums[2], nums[1]);
    nums[1] = nums[0];
    nums[2] += nums[0];
    for (int i = 3; i < sz; ++i) {
        nums_0[i] = nums[i] + max(nums_0[i - 3], nums_0[i - 2]);
        nums[i] += max(nums[i - 3], nums[i - 2]);
    }
    nums[sz - 1] -= min(nums[0], temp);
    return max(max(nums_0[sz - 1], nums_0[sz - 2]), max(nums[sz - 1], nums[sz - 2]));
}
