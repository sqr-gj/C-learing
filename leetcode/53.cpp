/* 最大子序和
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例 1：
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。

示例 2：
输入：nums = [1]
输出：1

示例 3：
输入：nums = [0]
输出：0

示例 4：
输入：nums = [-1]
输出：-1

示例 5：
输入：nums = [-100000]
输出：-100000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

//                                  2021/11/1
int maxSubArray(vector<int>& nums) {
    int sz = nums.size();
    int max = nums[0];
    int pos = 0;
    while (pos < sz && nums[pos] <= 0) {        //找到第一个正数
        max = max > nums[pos] ? max : nums[pos];
        ++pos;
    }
    if (pos == sz)
        return max;
    max = nums[pos];
    int now = max;
    for (int i = pos + 1; i < sz; ++i) {
        if (nums[i] > 0) {
            now += nums[i];
            max = max > now ? max : now;
        }
        else {
            now = (now + nums[i]) > 0 ? (now + nums[i]) : 0;
        }
    }
    return max;
}
