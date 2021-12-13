/* 从数组中移除最大值和最小值
给你一个下标从 0 开始的数组 nums ，数组由若干 互不相同 的整数组成。
nums 中有一个值最小的元素和一个值最大的元素。分别称为 最小值 和 最大值 。你的目标是从数组中移除这两个元素。
一次 删除 操作定义为从数组的 前面 移除一个元素或从数组的 后面 移除一个元素。
返回将数组中最小值和最大值 都 移除需要的最小删除次数。

示例 1：
输入：nums = [2,10,7,5,4,1,8,6]
输出：5
解释：
数组中的最小元素是 nums[5] ，值为 1 。
数组中的最大元素是 nums[1] ，值为 10 。
将最大值和最小值都移除需要从数组前面移除 2 个元素，从数组后面移除 3 个元素。
结果是 2 + 3 = 5 ，这是所有可能情况中的最小删除次数。

示例 2：
输入：nums = [0,-4,19,1,8,-2,-3,5]
输出：3
解释：
数组中的最小元素是 nums[1] ，值为 -4 。
数组中的最大元素是 nums[2] ，值为 19 。
将最大值和最小值都移除需要从数组前面移除 3 个元素。
结果是 3 ，这是所有可能情况中的最小删除次数。

示例 3：
输入：nums = [101]
输出：1
解释：
数组中只有这一个元素，那么它既是数组中的最小值又是数组中的最大值。
移除它只需要 1 次删除操作。
*/

#include <vector>
#include <algorithm>

using namespace std;

//                              2021/11/28
int question_5940(vector<int>& nums) {
    vector<int> c_nums = nums;
    sort(nums.begin(), nums.end());
    int sz = nums.size();
    if (sz == 1 || sz == 2)
        return sz;
    int min_num = nums[0];
    int max_num = nums[sz - 1];
    int min_p;
    int max_p;
    for (int i = 0; i < sz; ++i) {
        if (c_nums[i] == min_num)
            min_p = i;
        else if (c_nums[i] == max_num)
            max_p = i;
    }
    if (max_p < min_p)
        swap(min_p, max_p);
    return min(min(max_p + 1, sz - min_p), min_p + 1 + sz - max_p);
}
