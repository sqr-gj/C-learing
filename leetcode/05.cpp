/* 替换空格
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

示例 1：
输入：s = "We are happy."
输出："We%20are%20happy."

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>

using namespace std;

//                          2021/9/13
string question_05(string s) {
    int sz_ori = s.size();
    int cnt_ = 0;
    for (auto c : s)
        if (c == ' ')
            ++cnt_;
    int sz_now = sz_ori + 2 * cnt_;
    s += string(2 * cnt_, ' ');
    int right = sz_now - 1;
    for(int left = sz_ori - 1; left >= 0; --left) {
        if (s[left] == ' ') {
            s[right] = '0';
            s[right - 1] = '2';
            s[right - 2] = '%';
            right -= 3;
        }
        else {
            s[right] = s[left];
            --right;
        }
    }
    return s;
}
