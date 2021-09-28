/* 删除字符串中所有相邻重复项
给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
在 S 上反复执行重复项删除操作，直到无法继续删除。
在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。

示例：
输入："abbaca"
输出："ca"
解释：
例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。之后我们得到字符串 "aaca"，
其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <stack>
#include <algorithm>

using namespace std;

//                      2021/9/23
string question_1047(string s) {
    stack<char> s_del;
    for (auto c : s) {
        if (!s_del.empty()) {
            if (s_del.top() == c) {
                s_del.pop();
                continue;
            }
            s_del.push(c);
        }
        else
            s_del.push(c);
    }
    string result;
    while (!s_del.empty()) {
        result += s_del.top();
        s_del.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}
