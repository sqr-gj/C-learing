/* 赎金信
给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串 ransom 能不能由第二个字符串 magazines 里面的字符构成。
如果可以构成，返回 true ；否则返回 false。
(题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。杂志字符串中的每个字符只能在赎金信字符串中使用一次。)

示例 1：
输入：ransomNote = "a", magazine = "b"
输出：false

示例 2：
输入：ransomNote = "aa", magazine = "ab"
输出：false

示例 3：
输入：ransomNote = "aa", magazine = "aab"
输出：true

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ransom-note
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <unordered_map>
#include <string>

using namespace std;

//                      2021/9/12
bool question_383(string ransomNote, string magazine) {
    if (magazine.size() < ransomNote.size())
        return false;
    unordered_map<char, int> char_B;
    for (auto c_B : magazine)
        ++char_B[c_B];

    for (auto c_A : ransomNote) {
        if(!char_B.count(c_A))
            return false;
        if(char_B[c_A] == 0)
            return false;
        --char_B[c_A];
    }
    return true;
}
