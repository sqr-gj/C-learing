/* 电话号码的字母组合
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

示例 1：
输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]

示例 2：
输入：digits = ""
输出：[]

示例 3：
输入：digits = "2"
输出：["a","b","c"]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//题解: https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/solution/di-gui-hui-su-by-cao-mu-hui-d-lzj9/
#include <vector>
#include <string>

using namespace std;

vector<string> num_char = {{}, {}, {"abc"}, {"def"}, {"ghi"}, {"jkl"}, {"mno"}, {"pqrs"}, {"tuv"}, {"wxyz"}};

////将num对应字符加到string上
//void add_string(vector<string> &result, int num) {
//    string s = num_char[num];
//    int sz1 = s.size();
//    int sz2 = result.size();
//    if (sz2 == 0) {             //第一个数
//        for (int j = 0; j < sz1; ++j) {
//            string str;
//            str += num_char[num][j];
//            result.push_back(str);
//        }
//        return;
//    }
//    for (int i = 0; i < sz2; ++i) {
//        string str = result[i];
//        for (int j = 0; j < sz1; ++j) {
//            str += num_char[num][j];
//            result.push_back(str);
//            str.pop_back();
//        }
//    }
//    result.erase(result.begin(), result.begin() + sz2);     //删除前n个字符串
//}

////                                  2021/10/19
//vector<string> question_17(string digits) {
//    int sz = digits.size();
//    vector<string> result;
//    if (sz == 0)
//        return result;

//    for (int i = 0; i < sz; ++i) {
//        string c = "0";
//        c[0] = digits[i];
//        int num = stoi(c);
//        add_string(result, num);
//    }
//    return result;
//}

//  k表示当前应该组合 digits 中的第 k 个字符
void combine (string &digits, vector<string> &result, string &one_con, size_t k) {
    if (k == digits.size()){                        //sz个字符全部组合完毕
        result.push_back(one_con);
        return;
    }

    string now_num = num_char[digits[k] - '0'];     //当前数字字符对应的字母
    int sz = now_num.size();
    for (int i = 0; i < sz; ++i) {
        one_con[k] = now_num[i];                    //更新当前位置的字符
        combine(digits, result, one_con, k + 1);
    }
}

//                                              2021/12/13
vector<string> question_17(string digits) {
    int sz = digits.size();
    vector<string> result;
    if (sz == 0)
        return result;
    string one_con(sz, ' ');                        //表示一种组合方式
    combine(digits, result, one_con, 0);
    return result;
}
