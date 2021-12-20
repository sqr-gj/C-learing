/* 单调递增的数字
给定一个非负整数 N，找出小于或等于 N 的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增。

（当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。）

示例 1:
输入: N = 10
输出: 9

示例 2:
输入: N = 1234
输出: 1234

示例 3:
输入: N = 332
输出: 299

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/monotone-increasing-digits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>

using namespace std;

//      2021/12/14
//题解:https://leetcode-cn.com/problems/monotone-increasing-digits/solution/shi-tan-xin-ma-by-cao-mu-hui-d-uf21/

//                          2021/11/10
int question_738(int n) {
    string n_s = to_string(n);
    int sz = n_s.size();
    vector<char> all_num = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int i = 0;
    for (; i < sz - 1; ++i) {
        if (n_s[i] > n_s[i + 1]) {
            break;
        }
    }
    if (i == sz - 1)        //全递增
        return n;

    int j = i;
    for (; j > 0; --j) {
        if (n_s[j] > n_s[j - 1])
            break;
    }

    n_s[j] = all_num[n_s[j] - '1'];
    for (int k = j + 1; k < sz; ++k)
        n_s[k] = '9';
    return stoi(n_s);
}
