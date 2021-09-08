/*长度最小的子数组
给定一个含有 n 个正整数的数组和一个正整数 target 。
找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，
返回 0 。

示例 1：
输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。

示例 2：
输入：target = 4, nums = [1,4,4]
输出：1

示例 3：
输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-size-subarray-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

//双指针                                   2021/9/6
int question_209(int target, vector<int>& nums) {
    int sum = 0;
    int min = 100000;
    int left = 0;
    int sz = nums.size();
    for(int right = 0; right < sz; ++right) {
        sum += nums[right];
        while (sum >= target) {
            min = (min < (right - left + 1)) ? min : (right - left + 1);
            if(min == 1)                //可丢
                return 1;
            sum -= nums[left];
            ++left;
        }
    }
    return (min == 100000) ? 0 : min;
}
