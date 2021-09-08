/*最高频元素的频数
元素的 频数 是该元素在一个数组中出现的次数。
给你一个整数数组 nums 和一个整数 k 。在一步操作中，你可以选择 nums 的一个下标，并将该下标对应元素的值增加 1 。
执行最多 k 次操作后，返回数组中最高频元素的 最大可能频数 。

——>k 为总操作次数

示例 1：
输入：nums = [1,2,4], k = 5
输出：3
解释：对第一个元素执行 3 次递增操作，对第二个元素执 2 次递增操作，此时 nums = [4,4,4] 。
4 是数组中最高频元素，频数是 3 。

示例 2：
输入：nums = [1,4,8,13], k = 5
输出：2
解释：存在多种最优解决方案：
- 对第一个元素执行 3 次递增操作，此时 nums = [4,4,8,13] 。4 是数组中最高频元素，频数是 2 。
- 对第二个元素执行 4 次递增操作，此时 nums = [1,8,8,13] 。8 是数组中最高频元素，频数是 2 。
- 对第三个元素执行 5 次递增操作，此时 nums = [1,4,13,13] 。13 是数组中最高频元素，频数是 2 。

示例 3：
输入：nums = [3,9,6], k = 2
输出：1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/frequency-of-the-most-frequent-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

//                  2021/7/19
int question_1838(vector<int>& nums, int k) {
    //当k为每个元素可进行的操作数
//    unordered_map<int, size_t> nums_map;
//    int min = 100000, max = 0;
//    for(auto num : nums){
//        ++nums_map[num];
//        min = (num < min) ? num : min;
//        max = (num > max) ? num : max;
//    }

//    int max_cnt = 0;            //最大频数
//    for(min; min <= max; ++min){
//        int cnt = 0;
//        for(int i = 0; i <= k; ++i){
//            if(nums_map.count(min + i))
//                cnt += nums_map[min + i];
//        }
//        max_cnt = (cnt > max_cnt) ? cnt : max_cnt;
//    }

//    return max_cnt;

    //当k为总操作数
    sort(nums.begin(), nums.end());
    int max_cnt = 1;
    int total = 0;
    size_t left = 0;
    for(size_t right = 1; right < nums.size(); ++right){
        total += (nums[right] - nums[right - 1]) * (right - left);
        if(total > k){
            total -= (nums[right] - nums[left]);
            ++left;
        }
        max_cnt = (max_cnt > int((right - left +1))) ? max_cnt : (right - left +1);
    }

    return max_cnt;
}
