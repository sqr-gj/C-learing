/* 至少是其他数字两倍的最大数
给你一个整数数组 nums ，其中总是存在 唯一的 一个最大整数 。
请你找出数组中的最大元素并检查它是否 至少是数组中每个其他数字的两倍 。如果是，则返回 最大元素的下标 ，否则返回 -1 。

示例 1：
输入：nums = [3,6,1,0]
输出：1
解释：6 是最大的整数，对于数组中的其他整数，6 大于数组中其他元素的两倍。6 的下标是 1 ，所以返回 1 。

示例 2：
输入：nums = [1,2,3,4]
输出：-1
解释：4 没有超过 3 的两倍大，所以返回 -1 。

示例 3：
输入：nums = [1]
输出：0
解释：因为不存在其他数字，所以认为现有数字 1 至少是其他数字的两倍。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-number-at-least-twice-of-others
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

//                                      2022/1/13
int question_747(vector<int>& nums) {
    int max = 0;
    int result = -1;
    int sz = nums.size();
    for (int i = 0; i < sz; ++i) {
        if (nums[i] > max) {
            result = nums[i] >= 2 * max ? i : -1;
            max = nums[i];
        }
        else {
            if (max < 2 * nums[i])
                result = -1;
        }
    }
    return result;
}
