/* 逆波兰表达式求值
根据 逆波兰表示法，求表达式的值。
有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

说明：
整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。

示例 1：
输入：tokens = ["2","1","+","3","*"]
输出：9
解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9

示例 2：
输入：tokens = ["4","13","5","/","+"]
输出：6
解释：该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6

示例 3：
输入：tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
输出：22
解释：
该算式转化为常见的中缀算术表达式为：
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/evaluate-reverse-polish-notation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>
#include <cctype>

using namespace std;

//                                  2021/9/24
int question_150(vector<string>& tokens) {
    vector<int> nums;
    for (string &s : tokens) {
        int temp = 0;
        switch (s[0]) {
        case '+':
            temp = nums[nums.size() - 1] + nums[nums.size() - 2];
            goto push;
        case '-':
            if (s.size() != 1) {                    //防止s为负数
                nums.push_back(stoi(s));
                break;
            }
            temp = nums[nums.size() - 2] - nums[nums.size() - 1];
            goto push;
        case '*':
            temp = nums[nums.size() - 1] * nums[nums.size() - 2];
            goto push;
        case '/':
            temp = nums[nums.size() - 2] / nums[nums.size() - 1];
            goto push;
        push :
            nums.pop_back();
            nums.pop_back();
            nums.push_back(temp);
            break;
        default:
            nums.push_back(stoi(s));
        }
    }
    return nums[0];
}
