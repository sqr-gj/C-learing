/* 前k个高频元素
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

示例 1:
输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]

示例 2:
输入: nums = [1], k = 1
输出: [1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/top-k-frequent-elements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//                          2021/9/24
vector<int> question_347(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    vector<int> nums_single{nums[0]};
    unordered_map<int, int> nums_fre;
    for (auto num : nums) {
        ++nums_fre[num];
        if (num != nums_single.back())
            nums_single.push_back(num);
    }

    vector<int> result;
    for (auto num : nums_single) {
        int frequency = nums_fre[num];
        int sz = result.size();
        result.push_back(num);
        while (sz > 0 && frequency > nums_fre[result[sz - 1]]) {
            swap(result[sz], result[sz - 1]);
            --sz;
        }
    }
    return {result.begin(), result.begin() + k};
}
