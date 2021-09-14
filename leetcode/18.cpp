/* 四数之和
给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。
请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] ：

0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按 任意顺序 返回答案 。

示例 1：
输入：nums = [1,0,-1,0,-2,2], target = 0
输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

示例 2：
输入：nums = [2,2,2,2,2], target = 8
输出：[[2,2,2,2]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/4sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <algorithm>

using namespace std;

//
vector<vector<int>> question_18(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    int sz = nums.size();
    for (int i = 0; i < sz - 3; ++i) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < sz - 2; ++j) {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            int res = target - nums[i] - nums[j];
            int right = sz - 1;
            int left = j + 1;
            while (left< right) {
                if (nums[left] + nums[right] > res)
                    --right;
                else if (nums[left] + nums[right] < res)
                    ++left;
                else {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    while (right > left && nums[right] == nums[right - 1])
                        right--;
                    while (right > left && nums[left] == nums[left + 1])
                        left++;

                   // 找到答案时，双指针同时收缩
                    right--;
                    left++;
                }
            }
        }
    }
    return result;
}
