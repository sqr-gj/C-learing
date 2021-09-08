/*单词规律
给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。

示例1:
输入: pattern = "abba", str = "dog cat cat dog"
输出: true

示例 2:
输入:pattern = "abba", str = "dog cat cat fish"
输出: false

示例 3:
输入: pattern = "aaaa", str = "dog cat cat dog"
输出: false

示例 4:
输入: pattern = "abba", str = "dog dog dog dog"
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-pattern
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <unordered_map>
#include <sstream>
#include <vector>

using namespace std;

//                                  2021/9/2
bool question_290(string pattern, string s) {
    unordered_map<string, string> pat;
    string word;
    vector<string> ss;
    istringstream read(s);
    while (read >> word) {
        ss.push_back(word);
    }
    int sz = pattern.size();
    if(sz != ss.size())
        return false;
    for(int i = 0; i < sz; ++i){
        string a = to_string(pattern[i]);
        if(pat.count(a)){
            if(ss[i] != pat[a])
                return false;
        }
        else {
            pat[a] = ss[i];
        }
    }
    pat.clear();
    for(int i = 0; i < sz; ++i){
        string a = ss[i];
        if(pat.count(a)){
            if(to_string(pattern[i]) != pat[a])
                return false;
        }
        else {
            pat[a] = to_string(pattern[i]);
        }
    }
    return true;
}
