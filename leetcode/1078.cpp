/* Bigram 分词
给出第一个词 first 和第二个词 second，考虑在某些文本 text 中可能以 "first second third" 形式出现的情况，其中 second 紧随 first 出现，third 紧随 second 出现。
对于每种这样的情况，将第三个词 "third" 添加到答案中，并返回答案。

示例 1：
输入：text = "alice is a good girl she is a good student", first = "a", second = "good"
输出：["girl","student"]

示例 2：
输入：text = "we will we will rock you", first = "we", second = "will"
输出：["we","rock"]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/occurrences-after-bigram
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>

using namespace std;

//                                      2021/12/26
vector<string> question_1078(string text, string first, string second) {
    int sz = text.size();
    vector<string> s;
    int cnt = 0;
    string temp;
    for (int i = 0; i < sz; ++i) {
        if (text[i] == ' '){
            s.push_back(temp);
            ++cnt;
            temp.clear();
        }
        else
            temp += text[i];
    }
    s.push_back(temp);
    vector<string> result;
    for (int i = 0; i < cnt - 1; ++i) {
        if (s[i] == first && s[i + 1] == second)
            result.push_back(s[i + 2]);
    }
    return result;
}
