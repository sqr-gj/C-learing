/* 统计特殊四元组
给你一个 下标从 0 开始 的整数数组 nums ，返回满足下述条件的 不同 四元组 (a, b, c, d) 的 数目 ：
nums[a] + nums[b] + nums[c] == nums[d] ，且
a < b < c < d

示例 1：
输入：nums = [1,2,3,6]
输出：1
解释：满足要求的唯一一个四元组是 (0, 1, 2, 3) 因为 1 + 2 + 3 == 6 。

示例 2：
输入：nums = [3,3,6,4,5]
输出：0
解释：[3,3,6,4,5] 中不存在满足要求的四元组。

示例 3：
输入：nums = [1,1,1,3,5]
输出：4
解释：满足要求的 4 个四元组如下：
- (0, 1, 2, 3): 1 + 1 + 1 == 3
- (0, 1, 3, 4): 1 + 1 + 3 == 5
- (0, 2, 3, 4): 1 + 1 + 3 == 5
- (1, 2, 3, 4): 1 + 1 + 3 == 5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-special-quadruplets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//             2021/12/29
int countQuadruplets(vector<int>& nums) {
//    sort(nums.begin(), nums.end());
    int cnt = 0;
    int sz = nums.size();
    //不满足a<b<c<d(不能排序)
//    for (int i = 3; i < sz; ++i) {
//        for (int j = 0; j < i - 2; ++j) {
//            int target = nums[i] - nums[j];
//            int left = j + 1;
//            int right = i - 1;
//            while (left < right) {
//                if (nums[left] + nums[right] < target)
//                    ++left;
//                else if (nums[left] + nums[right] > target)
//                    --right;
//                else {
//                    ++cnt;
//                    while (left < right - 1 && nums[left] == nums[left + 1]) {
//                        ++left;
//                        ++cnt;
//                    }
//                    while (right > left + 1 && nums[right] == nums[right - 1]) {
//                        --right;
//                        ++cnt;
//                    }
//                    ++left;
//                    --right;
//                }
//            }
//        }
//    }
//    return cnt;
    unordered_map<int, int> sum_n;
    for (int i = 3; i < sz; ++i) {
        for (int j = 0; j < i - 2; ++j) {
            for (int k = j + 1; k < i - 1; ++k)
                ++sum_n[nums[j] + nums[k] + nums[i - 1]];
        }
        if (sum_n.count(nums[i]))
            cnt += sum_n[nums[i]];
    }
    return ++cnt;
}
