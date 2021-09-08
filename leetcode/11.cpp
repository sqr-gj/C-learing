/*盛最多水的容器
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0) 。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
说明：你不能倾斜容器。

示例 1：
输入：[1,8,6,2,5,4,8,3,7]
输出：49
解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

示例 2：
输入：height = [1,1]
输出：1

示例 3：
输入：height = [4,3,2,1,4]
输出：16

示例 4：
输入：height = [1,2,1]
输出：2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/container-with-most-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

//-> 超时
//int question_11(vector<int>& height) {
//    int max = 0;
//    int sz = height.size();
//    for(int i = 0; i < sz - 1; ++i){
//        for(int j = i + 1; j < sz; ++j){
//            int h = (height[i] > height[j]) ? height[j] : height[i];
//            max = (max > h * (j - i)) ? max : h * (j - i);
//        }
//    }
//    return max;
//}

//双指针                       2021/9/1
int question_11(vector<int>& height) {
    int max = 0;
    int sz = height.size();
    int left = 0;
    int right = sz - 1;
    while (left < right) {
        int h = (height[left] > height[right]) ? height[right] : height[left];
        max = (max > h * (right - left)) ? max : h * (right - left);
        if(height[left] > height[right])
            --right;
        else
            ++left;
    }
    return max;
}
