/* 单词拆分
给你一个字符串 s 和一个字符串列表 wordDict 作为字典，判定 s 是否可以由空格拆分为一个或多个在字典中出现的单词。

说明：拆分时可以重复使用字典中的单词。



示例 1：

输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
示例 2：

输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
     注意你可以重复使用字典中的单词。
示例 3：

输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-break
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//                                  2021/12/1
bool question_139(string s, vector<string>& wordDict) {
    sort(wordDict.begin(), wordDict.end(), [](string &s1, string &s2) {return s1.size() < s2.size();});
    int sz = s.size();
    int sz_s = wordDict.size();
    vector<bool> dp(sz + 1);
    dp[0] = true;
    for (int i = 1; i <= sz; ++i) {
        for (int j = 0; j < sz_s; ++j) {
            if (i < wordDict[j].size())
                break;
            string temp_s(s.begin() + i - wordDict[j].size(), s.begin() + i);
            if (temp_s == wordDict[j] && dp[i - wordDict[j].size()])
                dp[i] = true;
        }
    }
    return dp[sz];
}
