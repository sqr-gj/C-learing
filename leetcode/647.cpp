/* 回文子串
给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
回文字符串 是正着读和倒过来读一样的字符串。
子字符串 是字符串中的由连续字符组成的一个序列。
具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

示例 1：
输入：s = "abc"
输出：3
解释：三个回文子串: "a", "b", "c"

示例 2：
输入：s = "aaa"
输出：6
解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindromic-substrings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>

using namespace std;

//题解:https://leetcode-cn.com/problems/palindromic-substrings/solution/bao-li-by-cao-mu-hui-d-uorm/

//                          2021/12/16
int question_647(string s) {
    int sz = s.size();
    int cnt = 0;
    for (int i = 0; i < sz; ++i) {
        ++cnt;
        for (int j = 0; j < i; ++j) {
            if (s[j] != s[i])       //改进1: 只有头尾字母相同才可能为回文串
                continue;
            // string temp_s(s.begin() + j, s.begin() + i + 1);     //改进2: 不需要重建字符串  原地操作即可
            // int left = 0;
            // int right = temp_s;
            int left = j;
            int right = i;
            while (left <= right) {
                if (s[left] != s[right])
                    break;
                ++left;
                --right;
            }
            if (left > right)
                ++cnt;
        }
    }
    return cnt;
}
