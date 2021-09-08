/*有序数组的平方
给你一个按非递减顺序排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按非递减顺序排序。

示例 1：
输入：nums = [-4,-1,0,3,10]
输出：[0,1,9,16,100]
解释：平方后，数组变为 [16,1,0,9,100]
排序后，数组变为 [0,1,9,16,100]

示例 2：
输入：nums = [-7,-3,2,3,11]
输出：[4,9,9,49,121]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/squares-of-a-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//                          2021/7/23
//vector<int> question_977(vector<int>& nums) {
//    for(auto &num : nums){
//        num *= num;
//    }
//    sort(nums.begin(), nums.end());
//    return nums;
//}

//双指针：找出第一个正数位置             2021/7/23
//vector<int> question_977(vector<int> &nums){
//    //无负数
//    if(nums[0] >= 0){
//        for(auto &num : nums)
//            num *= num;
//        return nums;
//    }

//    //无正数
//    if(nums[nums.size() - 1] <= 0){
//        vector<int> result;
//        for(auto iter = nums.rbegin(); iter != nums.rend(); ++iter)
//            result.push_back(*iter * *iter);
//        return result;
//    }

//    int left = 0;
//    int right = nums.size() - 1;
//    while (left < right) {
//        int mid = left + (right - left) / 2 + 1;
//        if(nums[mid] < 0){
//            left = mid;
//        }
//        else if(nums[mid] > 0){
//            right = mid - 1;
//        }
//        else {
//            right = mid;
//            break;
//        }
//    }               //left为最后一个负数位置

//    vector<int> result;
//    right = left + 1;
//    while(left >= 0 || right < nums.size()){
//        if(left < 0){
//            result.push_back(nums[right] * nums[right]);
//            ++right;
//        }
//        else if(right == nums.size()){
//            result.push_back(nums[left] * nums[left]);
//            --left;
//        }
//        else if(nums[right] < abs(nums[left]) ){
//            result.push_back(nums[right] * nums[right]);
//            ++right;
//        }
//        else{
//            result.push_back(nums[left] * nums[left]);
//            --left;
//        }
//    }
//    return  result;
//}

//双指针:直接从末尾排            2021/7/23
vector<int> question_977(vector<int> &nums){
    int sz = nums.size();
    int left = 0;
    int right = sz - 1;
    vector<int> result(sz);
    while (left < right) {
        if(abs(nums[left]) > abs(nums[right])){
            result[sz - 1] = nums[left] * nums[left];
            ++left;
            --sz;
        }
        else{
            result[sz - 1] = nums[right] * nums[right];
            --right;
            --sz;
        }
    }
    return result;
}
