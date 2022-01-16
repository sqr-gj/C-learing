/* 连接词
给你一个 不含重复 单词的字符串数组 words ，请你找出并返回 words 中的所有 连接词 。
连接词 定义为：一个完全由给定数组中的至少两个较短单词组成的字符串。

示例 1：
输入：words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
输出：["catsdogcats","dogcatsdog","ratcatdogcat"]
解释："catsdogcats" 由 "cats", "dog" 和 "cats" 组成;
     "dogcatsdog" 由 "dog", "cats" 和 "dog" 组成;
     "ratcatdogcat" 由 "rat", "cat", "dog" 和 "cat" 组成。

示例 2：
输入：words = ["cat","dog","catdog"]
输出：["catdog"]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/concatenated-words
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Tree {
public:
    Tree() {
        this->is_end = false;
        this->child = vector<Tree *>(26, nullptr);
    }
    void push_string(string s) {
        Tree *node = this;
        for (int i = 0; i < s.size(); ++i) {
            if (node->child[s[i] - 'a'] == nullptr) {
                node->child[s[i] - 'a'] = new Tree();
            }
            node = node->child[s[i] - 'a'];
        }
        node->is_end = true;
    }
    bool is_end = false;
    vector<Tree *> child = vector<Tree *>(26, nullptr);
};

//未通过                                       2021/12/28
vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    sort(words.begin(), words.end(), [](string &a, string &b) {return a.size() < b.size();});
    vector<string> result;
    Tree *head = new Tree();
    int sz = words.size();
    for (int i = 0; i < sz; ++i) {
        Tree *node = head;
        string &s = words[i];
        if (s.size() == 0)
            continue;
        int begin_ = 0;
        for (int j = 0; j < s.size(); ++j) {
            if (node->child[s[j] - 'a'] == nullptr)
                break;
            node = node->child[s[j] - 'a'];
            if (node->is_end) {
                begin_ = j + 1;
                node = head;
            }
        }
        if (begin_ == s.size())
            result.push_back(s);
        head->push_string(string(s.begin() + begin_, s.end()));
    }
    return result;
}
