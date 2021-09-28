/* 有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。

示例 1：
输入：s = "()"
输出：true

示例 2：
输入：s = "()[]{}"
输出：true

示例 3：
输入：s = "(]"
输出：false

示例 4：
输入：s = "([)]"
输出：false

示例 5：
输入：s = "{[]}"
输出：true

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stack>
#include <string>

using namespace std;

//                                  2021/9/22
bool question_20(string s) {
    stack<char> parent;
    for (auto c : s) {
        switch (c) {
            case ')':
                if (parent.empty() || parent.top() != '(')
                    return false;
                parent.pop();
                break;
            case ']':
                if (parent.empty() || parent.top() != '[')
                    return false;
                parent.pop();
                break;
            case '}':
                if (parent.empty() || parent.top() != '{')
                    return false;
                parent.pop();
                break;
            default:
                parent.push(c);
        }
    }
    return parent.empty();
}