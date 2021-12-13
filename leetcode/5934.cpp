/* 找到和最大的长度为 K 的子序列 显示英文描述
给你一个整数数组 nums 和一个整数 k 。你需要找到 nums 中长度为 k 的 子序列 ，且这个子序列的 和最大 。
请你返回 任意 一个长度为 k 的整数子序列。
子序列 定义为从一个数组里删除一些元素后，不改变剩下元素的顺序得到的数组。

示例 1：
输入：nums = [2,1,3,3], k = 2
输出：[3,3]
解释：
子序列有最大和：3 + 3 = 6 。

示例 2：
输入：nums = [-1,-2,3,4], k = 3
输出：[-1,3,4]
解释：
子序列有最大和：-1 + 3 + 4 = 6 。

示例 3：
输入：nums = [3,4,3,3], k = 2
输出：[3,4]
解释：
子序列有最大和：3 + 4 = 7 。
另一个可行的子序列为 [4, 3] 。
*/

#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//                                  2021/12/11
vector<int> maxSubsequence(vector<int>& nums, int k) {
    int sz = nums.size();
    vector<int> result;
    vector<int> copy_ = nums;
    sort(copy_.begin(), copy_.end());
    unordered_map<int, int> max_nums;
    for (int i = sz - 1; i > sz - k - 1; --i) {
        ++max_nums[copy_[i]];
    }
    for (int i = 0; i < sz; ++i) {
        if (max_nums[nums[i]]){
            result.push_back(nums[i]);
            --max_nums[nums[i]];
            if (result.size() == k)
                break;
        }
    }
    return result;
}
