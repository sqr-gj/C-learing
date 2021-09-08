/*三数之和
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
注意：答案中不可以包含重复的三元组。

示例 1：
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]

示例 2：
输入：nums = []
输出：[]

示例 3：
输入：nums = [0]
输出：[]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <algorithm>

using namespace std;

//                                  2021/8/31
vector<vector<int>> question_15(vector<int>& nums) {
    vector<vector<int>> re;
    sort(nums.begin(), nums.end());
    int sz = nums.size();
    for(int i = 0; i < sz - 2; ++i){
        if(i > 0 && nums[i] == nums[i - 1])
            continue;
        int k = sz - 1;
        int target = -nums[i];
        for(int j = i + 1; j < sz - 1; ++j){
            if(j > i + 1 && nums[j] == nums[j - 1])
                continue;
            while (j < k && nums[j] + nums[k] > target) {
                --k;
            }
            if(j == k)
                break;
            if(nums[j] + nums[k] == target)
                re.push_back({nums[i], nums[j], nums[k]});
        }
    }
    return re;
}
