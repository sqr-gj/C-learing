/* 找出数组排序后的目标下标 显示英文描述
User Accepted:0
User Tried:0
Total Accepted:0
Total Submissions:0
Difficulty:Easy
给你一个下标从 0 开始的整数数组 nums 以及一个目标元素 target 。
目标下标 是一个满足 nums[i] == target 的下标 i 。
将 nums 按 非递减 顺序排序后，返回由 nums 中目标下标组成的列表。如果不存在目标下标，返回一个 空 列表。返回的列表必须按 递增 顺序排列。

示例 1：
输入：nums = [1,2,5,2,3], target = 2
输出：[1,2]
解释：排序后，nums 变为 [1,2,2,3,5] 。
满足 nums[i] == 2 的下标是 1 和 2 。

示例 2：
输入：nums = [1,2,5,2,3], target = 3
输出：[3]
解释：排序后，nums 变为 [1,2,2,3,5] 。
满足 nums[i] == 3 的下标是 3 。

示例 3：
输入：nums = [1,2,5,2,3], target = 5
输出：[4]
解释：排序后，nums 变为 [1,2,2,3,5] 。
满足 nums[i] == 5 的下标是 4 。

示例 4：
输入：nums = [1,2,5,2,3], target = 4
输出：[]
解释：nums 中不含值为 4 的元素。
*/

#include <vector>
#include <algorithm>

using namespace std;

//                              2021/11/28
vector<int> question_5938(vector<int>& nums, int target) {
      sort(nums.begin(), nums.end());
      int first = 0;
      vector<int> result;
      int sz = nums.size();
      for (int i = 0; i < sz; ++i) {
          if (nums[i] == target) {
              result.push_back(i);
              first = i;
              break;
          }
          else if (nums[i] > target)
              return vector<int>();
      }
      int second = first + 1;
      for (; second < sz; ++second) {
          if (nums[second] == target)
              result.push_back(second);
          else
              break;
      }
      return result;
}
