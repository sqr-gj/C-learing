/* 全排列Ⅱ
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

示例 1：
输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]

示例 2：
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <algorithm>

using namespace std;

//
void arr_nums(vector<int> nums, vector<int> pre_nums, vector<vector<int>> &result) {
    int sz = nums.size();
    if (sz == 1) {
        pre_nums.push_back(nums[0]);
        result.push_back(pre_nums);
        return;
    }

    for (int i = 0; i < sz; ++i) {
        if (i > 0 && nums[i] == nums[i - 1])    //去重
            continue;
        pre_nums.push_back(nums[i]);
        vector<int> next_nums = nums;
        next_nums.erase(nums.begin() + i);
        arr_nums(vector<int> (nums.begin() + 1, nums.end()), pre_nums, result);
        pre_nums.pop_back();
    }
}

//                              2021/10/26
vector<vector<int>> question_47(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> pre;
    arr_nums(nums, pre, result);
    return result;
}
