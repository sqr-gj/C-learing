/* 统计按位或能得到最大值的子集数目
给你一个整数数组 nums ，请你找出 nums 子集 按位或 可能得到的 最大值 ，并返回按位或能得到最大值的 不同非空子集的数目 。
如果数组 a 可以由数组 b 删除一些元素（或不删除）得到，则认为数组 a 是数组 b 的一个 子集 。如果选中的元素下标位置不一样，则认为两个子集 不同 。
对数组 a 执行 按位或 ，结果等于 a[0] OR a[1] OR ... OR a[a.length - 1]（下标从 0 开始）。

示例 1：
输入：nums = [3,1]
输出：2
解释：子集按位或能得到的最大值是 3 。有 2 个子集按位或可以得到 3 ：
- [3]
- [3,1]

示例 2：
输入：nums = [2,2,2]
输出：7
解释：[2,2,2] 的所有非空子集的按位或都可以得到 2 。总共有 23 - 1 = 7 个子集。

示例 3：
输入：nums = [3,2,1,5]
输出：6
解释：子集按位或可能的最大值是 7 。有 6 个子集按位或可以得到 7 ：
- [3,5]
- [3,1,5]
- [3,2,5]
- [3,2,1,5]
- [2,5]
- [2,1,5]
*/

#include <vector>

using namespace std;

//找出所有子集
void find_subsets (vector<vector<int>> &all_subsets, vector<int> pre_nums, vector<int> res_nums) {
    all_subsets.push_back(pre_nums);
    int res_sz = res_nums.size();
    for (int i = 0; i < res_sz; ++i) {
        pre_nums.push_back(res_nums[i]);
        find_subsets(all_subsets, pre_nums, vector<int>(res_nums.begin() + i + 1, res_nums.end()));
        pre_nums.pop_back();
    }

}

//计算单个子集的位或值
int subset_BO (vector<int> subset) {
    int sz_subset = subset.size();
    int result = subset[0];
    for (int i = 1; i < sz_subset; ++i) {
        result |= subset[i];
    }
    return result;
}

//263周赛                             2021/10/23
int question_2044(vector<int>& nums) {
    vector<vector<int>> all_subsets;
    vector<int> pre_nums;

    find_subsets(all_subsets, pre_nums, nums);

    int max_BO = 0;
    int max_subsets = 1;
    int sz_all_subsets = all_subsets.size();
    for (int i = 1; i < sz_all_subsets; ++i) {
        int BO = subset_BO(all_subsets[i]);

        if (BO > max_BO) {                      //有更大位或值时更新
            max_BO = BO;
            max_subsets = 1;
        }
        else if (BO == max_BO) {                //相等加一
            ++max_subsets;
        }
    }
    return max_subsets;
}
