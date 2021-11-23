/* 子集
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

示例 1：
输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

示例 2：
输入：nums = [0]
输出：[[],[0]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subsets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

//遍历回溯出所有以i开头的子集
void subsets_ (vector<vector<int>> &result, vector<int> res_nums, vector<int> pre_nums) {
    if (res_nums.empty()) {
        result.push_back(pre_nums);
        return;
    }

    int sz = res_nums.size();
    for (int i = 0; i < sz; ++i) {
        pre_nums.push_back(res_nums[i]);
        subsets_(result, vector<int> (res_nums.begin() + i + 1, res_nums.end()), pre_nums);
        pre_nums.pop_back();
    }
    result.push_back(pre_nums);
}

//                                      2021/10/22
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> pre_nums;

    subsets_(result, nums, pre_nums);

    return result;
}
