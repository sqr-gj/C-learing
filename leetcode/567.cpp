/*字符串的排列
给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的排列。
换句话说，s1 的排列之一是 s2 的 子串 。

示例 1：
输入：s1 = "ab" s2 = "eidbaooo"
输出：true
解释：s2 包含 s1 的排列之一 ("ba").

示例 2：
输入：s1= "ab" s2 = "eidboaoo"
输出：false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutation-in-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <unordered_map>

using namespace std;

//滑动窗口                  2021/8/18
bool question_567(string s1, string s2){
    unordered_map<char, size_t> s1_map;
    for(auto s : s1)
        ++s1_map[s];

    unordered_map<char, size_t> s2_map;
    int sz = s1.size();
    int left = 0;
    int right = sz - 1;
    for(int i = 0; i <= s2.size(); ++i){
        if(i < sz){
            ++s2_map[s2[i]];
        }
        else {
            int j = 0;
            for(int cp = left; cp <= left + sz; ++cp){
                if(cp == left + sz)
                    return true;
                if(s2_map.count(s1[j]) && s2_map[s1[j]] == s1_map[s1[j]]){
                    ++j;
                    continue;
                }
                else
                    break;
            }
            if(i == s2.size())
                return false;
            --s2_map[s2[left++]];
            ++s2_map[s2[i]];
            ++right;
        }
    }
    return false;
}
