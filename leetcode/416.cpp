/* 分割等和子集
给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

示例 1：
输入：nums = [1,5,11,5]
输出：true
解释：数组可以分割成 [1, 5, 5] 和 [11] 。

示例 2：
输入：nums = [1,2,3,5]
输出：false
解释：数组不能分割成两个元素和相等的子集。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-equal-subset-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//递归超时
bool combine(vector<int> nums, int sum_nums, int sum_now) {
    int sz = nums.size();
    for (int i = 0; i < sz; ++i) {
        sum_now += nums[i];
        if (2 * sum_now == sum_nums)
            return true;
        else if (2 * sum_now < sum_nums){
            if (combine(vector<int> (nums.begin() + i + 1, nums.end()), sum_nums, sum_now))
                return true;
        }
        else
            return false;
        sum_now -= nums[i];
    }
    return false;
}
bool canPartition(vector<int>& nums) {
//    sort(nums.begin(), nums.end());
//    return combine(nums, accumulate(nums.begin(), nums.end(), 0), 0);

}
