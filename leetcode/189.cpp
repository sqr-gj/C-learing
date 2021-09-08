/*旋转数组
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

进阶：
尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？

示例 1:
输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]

示例 2:
输入：nums = [-1,-100,3,99], k = 2
输出：[3,99,-1,-100]
解释:
向右旋转 1 步: [99,-1,-100,3]
向右旋转 2 步: [3,99,-1,-100]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

//                          2021/7/23
void question_189(vector<int>& nums, int k) {
    int sz = nums.size();
    k %= sz;
//    while (k > 0) {
//        int t = nums[nums.size() - 1];
//        nums.pop_back();
//        nums.insert(nums.begin(), t);       //超时（vector除尾后位置插入元素均耗时）
//        --k;
//    }
    //右旋变左旋->还是超时
//    k = nums.size() - k;
//    while (k > 0) {
//        int t = nums[0];
//        nums.push_back(t);
//        nums.erase(nums.begin());
//        --k;
//    }

    //第i个元素应该放置于（i+k) % sz位置处
    int cnt = 0;
    int start = 0;
    while (cnt < sz) {
        int next = (start + k) % sz;

        while (next != start) {
            swap(nums[start], nums[next]);
            ++cnt;
            next = (next + k) % sz;
        }
        swap(nums[start], nums[next]);
        ++cnt;
        ++start;
    }
}
