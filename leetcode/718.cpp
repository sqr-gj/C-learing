/* 最长重复子数组
给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。

示例：
输入：
A: [1,2,3,2,1]
B: [3,2,1,4,7]
输出：3
解释：
长度最长的公共子数组是 [3, 2, 1] 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

//
int question_718(vector<int>& nums1, vector<int>& nums2) {
    //超时
//    int sz1 = nums1.size();
//    int sz2 = nums2.size();
//    int p1,p2;
//    int result = 0;
//    for (int i = 0; i < sz1; ++i) {
//        for (int j = 0; j < sz2; ++j) {
//            if (nums2[j] == nums1[i]) {
//                p1 = i + 1;
//                p2 = j + 1;
//                while (p1 < sz1 && p2 < sz2 && nums1[p1] == nums2[p2]) {
//                    ++p1;
//                    ++p2;
//                }
//                result = max(result, p2 - j);
//            }
//        }
//    }
//    return result;

    //                                      2021/12/10
    int sz1 = nums1.size();
    int sz2 = nums2.size();
    vector<vector<int>> dp(sz1, vector<int>(sz2));
    int result = 0;
    for (int i = 0; i < sz1; ++i) {
        for (int j = 0; j < sz2; ++j) {
            if (nums1[i] == nums2[j]) {
                if (i == 0 || j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            result = result > dp[i][j] ? result : dp[i][j];
        }
    }
    return result;
}
