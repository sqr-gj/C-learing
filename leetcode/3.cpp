/*无重复字符的最长子串
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:
输入: s = "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:
输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

示例 4:
输入: s = ""
输出: 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

//滑动窗口                  2021/8/18
int question_3(string s) {
    int left = 0;
    int len = 0;
    bool sign = false;   //判断是否出现重复字符

    unordered_map<char, int> str;
    for(int right = 0; right < s.size(); ++right){
        if(str.count(s[right])){
            sign = true;
            len = ((right - left) > len) ? (right - left) : len;
            int k = str[s[right]];
            for(int i = left; i <= k; ++i){
                str.erase(s[i]);
            }
            left = k + 1;
            str.insert({s[right], right});
        }
        else {
            str.insert({s[right], right});
        }
    }
    len = (str.size() > len) ? str.size() : len;
    return sign ? len : s.size();
}
