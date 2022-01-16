/* 最长字符串链
给出一个单词列表，其中每个单词都由小写英文字母组成。
如果我们可以在 word1 的任何地方添加一个字母使其变成 word2，那么我们认为 word1 是 word2 的前身。例如，"abc" 是 "abac" 的前身。
词链是单词 [word_1, word_2, ..., word_k] 组成的序列，k >= 1，其中 word_1 是 word_2 的前身，word_2 是 word_3 的前身，依此类推。
从给定单词列表 words 中选择单词组成词链，返回词链的最长可能长度。

示例：
输入：["a","b","ba","bca","bda","bdca"]
输出：4
解释：最长单词链之一为 "a","ba","bda","bdca"。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-string-chain
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//
bool a_begin_b(string &a, string &b) {
    if (b.size() - a.size() != 1)
        return false;
    int sz = a.size();
    int i = 0;
    int j = 0;
    while (i < sz && j < sz + 1) {
        if (a[i] == b[j]) {
            ++i;
            ++j;
        }
        else {
            ++j;
        }
        if (j - i > 1)
         break;
    }
    return i == sz;
}

//                          2021/12/23
int question_1048(vector<string>& words) {
    int sz = words.size();
    vector<int> dp(sz, 1);
    sort(words.begin(), words.end(), [](string &a, string &b) {return a.size() < b.size();});
    int max_ = 1;
    for (int i = 1; i < sz; ++i){
        for (int j = 0; j < i; ++j) {
            if (words[i].size() - words[j].size() > 1)
                break;
            if (a_begin_b(words[i], words[j]))
                dp[i] = max(dp[i], dp[j] + 1);
        }
        max_ = max(dp[i], max_);
    }
    return max_;
}
