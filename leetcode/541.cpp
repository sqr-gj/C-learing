/* 反转字符串Ⅱ
给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。

如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

示例 1：
输入：s = "abcdefg", k = 2
输出："bacdfeg"

示例 2：
输入：s = "abcd", k = 2
输出："bacd"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-string-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <algorithm>

using namespace std;

//                          2021/9/13
string question_541(string s, int k) {
    int coor_now = 0;
    int sz = s.size();
    while (sz - coor_now >= 2 * k) {
        int left = coor_now;
        int right = coor_now + k - 1;
        while (left < right) {
            swap(s[left++], s[right--]);
        }
        coor_now += 2 * k;
    }

    if (sz - coor_now >= k) {
        int left = coor_now;
        int right = coor_now + k - 1;
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }
    else {
        int left = coor_now;
        int right = sz - 1;
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }
    return s;
}
