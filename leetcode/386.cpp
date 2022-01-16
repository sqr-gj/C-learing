/* 字典序排数
给你一个整数 n ，按字典序返回范围 [1, n] 内所有整数。

你必须设计一个时间复杂度为 O(n) 且使用 O(1) 额外空间的算法。

示例 1：
输入：n = 13
输出：[1,10,11,12,13,2,3,4,5,6,7,8,9]

示例 2：
输入：n = 2
输出：[1,2]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lexicographical-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//                              2021/12/22
vector<int> question_386(int n) {
    vector<int> result;
    for (int i = 0; i < n; ++i) {
        result.push_back(i + 1);
    }
    sort(result.begin(), result.end(), [](int &a, int &b) {return to_string(a) < to_string(b);});
    return result;

    //
//    vector<int> result;
//    int num = 1;
//    while (result.size() != n) {
//        while (num <= n) {
//            result.push_back(num);
//            num *= 10;
//        }
//        while (num > n || num % 10 == 9) {
//            num /= 10;
//        }
//        ++num;
//    }
//    return result;
}
