/* 滑动窗口最大值
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。
滑动窗口每次只向右移动一位。
返回滑动窗口中的最大值。

示例 1：
输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

示例 2：
输入：nums = [1], k = 1
输出：[1]

示例 3：
输入：nums = [1,-1], k = 1
输出：[1,-1]

示例 4：
输入：nums = [9,11], k = 2
输出：[11]

示例 5：
输入：nums = [4,-2], k = 2
输出：[4]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sliding-window-maximum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <deque>

using namespace std;

//超时
//vector<int> question_239(vector<int>& nums, int k) {
//    int max = -10000;
//    vector<int> result;
//    int left = 0;
//    int right = 0;

//    //初始化
//    while (right < k) {
//        max = (max > nums[right]) ? max : nums[right];
//        ++right;
//    }
//    result.push_back(max);

//    int sz = nums.size();
//    for (; right < sz; ++right, ++left) {
//        if (nums[left] == max) {
//            if (nums[right] >= max) {
//                max = nums[right];
//                result.push_back(max);
//            }
//            else {
//                max = -10000;
//                for (int i = left + 1; i <= right; ++i)
//                    max = (max > nums[i]) ? max : nums[i];
//                result.push_back(max);
//            }
//        }
//        else {
//            if (nums[right] >= max) {
//                max = nums[right];
//                result.push_back(max);
//            }
//            else {
//                result.push_back(max);
//            }
//        }
//    }
//    return result;
//}

//                          2021/9/24
vector<int> question_239(vector<int>& nums, int k) {
    vector<int> result;
    int left = 0;
    int right = 1;
    deque<int> big_nums{nums[0]};

    //初始化
    while (right < k) {
        //确保后面加进来的数以从大到小顺序排在队列中（小于最后插进来的数可以忽略即pop
        int value = nums[right];
        while (!big_nums.empty() && value > big_nums.back())
            big_nums.pop_back();
        big_nums.push_back(value);
        ++right;
    }
    result.push_back(big_nums.front());

    int sz = nums.size();
    for (; right < sz; ++right, ++left) {
        if (nums[left] == big_nums.front())
            big_nums.pop_front();

        int value = nums[right];
        while (!big_nums.empty() && value > big_nums.back())
            big_nums.pop_back();
        big_nums.push_back(value);
        result.push_back(big_nums.front());
    }
    return result;
}
