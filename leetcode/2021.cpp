/* 数组美丽值求和
给你一个下标从 0 开始的整数数组 nums 。对于每个下标 i（1 <= i <= nums.length - 2），nums[i] 的 美丽值 等于：
2，对于所有 0 <= j < i 且 i < k <= nums.length - 1 ，满足 nums[j] < nums[i] < nums[k]
1，如果满足 nums[i - 1] < nums[i] < nums[i + 1] ，且不满足前面的条件
0，如果上述条件全部不满足
返回符合 1 <= i <= nums.length - 2 的所有 nums[i] 的 美丽值的总和 。

示例 1：
输入：nums = [1,2,3]
输出：2
解释：对于每个符合范围 1 <= i <= 1 的下标 i :
- nums[1] 的美丽值等于 2

示例 2：
输入：nums = [2,4,6,4]
输出：1
解释：对于每个符合范围 1 <= i <= 2 的下标 i :
- nums[1] 的美丽值等于 1
- nums[2] 的美丽值等于 0

示例 3：
输入：nums = [3,2,1]
输出：0
解释：对于每个符合范围 1 <= i <= 1 的下标 i :
- nums[1] 的美丽值等于 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-beauty-in-the-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

//                                  2021/12/9
int question_2021(vector<int>& nums) {
    int sz = nums.size();
    int sum = 0;
    vector<int> n1(sz);
    vector<int> n2(sz);
    n1[0] = nums[0];
    n2[sz - 1] = nums[sz - 1];

    for (int i = 1; i < sz; ++i) {
        n1[i] = max(nums[i], n1[i - 1]);
    }
    for (int i = sz - 2; i > 0; --i) {
        n2[i] = min(nums[i], n2[i + 1]);
        //两次遍历足够了
        if (nums[i] > n1[i - 1] && nums[i] < n2[i + 1])
            sum += 2;
        else if (nums[i] > nums[i - 1] && nums[i] < nums[i + 1])
            sum += 1;
    }

//    for (int i = 1; i < sz - 1; ++i) {
//        if (nums[i] > n1[i - 1] && nums[i] < n2[i + 1])
//            sum += 2;
//        else if (nums[i] > nums[i - 1] && nums[i] < nums[i + 1])
//            sum += 1;
//    }

    return sum;
}
