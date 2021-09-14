/*有效的字母异位词
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

示例 1:
输入: s = "anagram", t = "nagaram"
输出: true

示例 2:
输入: s = "rat", t = "car"
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-anagram
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <unordered_map>
#include <string>

using namespace std;

//                              2021/9/10
bool question_242(string s, string t) {
    if(s.size() != t.size())
        return false;

    unordered_map<char, size_t> char_s;
    unordered_map<char, size_t> char_t;
    int sz = s.size();
    for(int i = 0; i < sz; ++i) {
        ++char_s[s[i]];
        ++char_t[t[i]];
    }
    for(int i = 0; i < sz; ++i) {
        char c = s[i];
        if(!char_t.count(c) || char_s[c] != char_t[c])
            return false;
    }
    return true;
}
