/* 左旋转字符串
字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，
该函数将返回左旋转两位得到的结果"cdefgab"。

示例 1：
输入: s = "abcdefg", k = 2
输出: "cdefgab"

示例 2：
输入: s = "lrloseumgh", k = 6
输出: "umghlrlose"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <algorithm>

using namespace std;

//左旋右旋见189->旋转数组            2021/9/14
string question_58(string s, int n) {
    int sz = s.size();
    int cnt = 0;            //计数    标记已经遍历的数据
    int start = 0;
//    n = sz - n;             //右旋变左旋
//    while (cnt < sz) {
//        int next = (start + n) % sz;
//        while (start != next) {
//            swap(s[start], s[next]);
//            ++cnt;
//            next = (next + n) % sz;
//        }
//        ++cnt;
//        ++start;
//    }
    while (cnt < sz) {
        int next = (start + n) % sz;
        int pre = start;
        while (start != next) {
            swap(s[pre], s[next]);
            ++cnt;
            pre = next;
            next = (next + n) % sz;
        }
        ++cnt;
        ++start;
    }
    return s;
}
