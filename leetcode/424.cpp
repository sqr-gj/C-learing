/*替换后的最长重复字符
给你一个仅由大写英文字母组成的字符串，你可以将任意位置上的字符替换成另外的字符，总共可最多替换 k 次。
在执行上述操作后，找到包含重复字母的最长子串的长度。
注意：字符串长度 和 k 不会超过 10^4。

示例 1：
输入：s = "ABAB", k = 2
输出：4
解释：用两个'A'替换为两个'B',反之亦然。

示例 2：
输入：s = "AABABBA", k = 1
输出：4
解释：
将中间的一个'A'替换为'B',字符串变为 "AABBBBA"。
子串 "BBBB" 有最长重复字母, 答案为 4。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-repeating-character-replacement
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <map>

using namespace std;

//最长子字符串中，与最大重复字符不同的字符数即为要求替换次数t，t<k即满足要求           2021/7/20
int question_424(string s, int k){
    map<char, size_t> s_map;
    int max_repeat = 0;             //区间内最大重复元素的个数
    size_t left = 0;

    for(size_t right = 0; right < s.size(); ++right){
        ++s_map[s[right]];
        max_repeat = (max_repeat > s_map[s[right]]) ? max_repeat : s_map[s[right]];
        if((right - left + 1 - max_repeat) > k){        //right - left + 1 - max_repeat 表示区间内与最大重复字符不同的字符数
            --s_map[s[left]];
            ++left;
        }
    }
    return s.size() - 1 - left;
}
