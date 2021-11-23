/* 复原ip地址
给定一个只包含数字的字符串，用以表示一个 IP 地址，返回所有可能从 s 获得的 有效 IP 地址 。你可以按任何顺序返回答案。
有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。

示例 1：
输入：s = "25525511135"
输出：["255.255.11.135","255.255.111.35"]

示例 2：
输入：s = "0000"
输出：["0.0.0.0"]

示例 3：
输入：s = "1111"
输出：["1.1.1.1"]

示例 4：
输入：s = "010010"
输出：["0.10.0.10","0.100.1.0"]

示例 5：
输入：s = "101023"
输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/restore-ip-addresses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>

using namespace std;

////判断字符串是否合法0<= s <256   默认不会选择size超过3的字符串
//bool is_legal (string s) {
//    //以0为前导
//    if (s.size() > 1 && s[0] == '0')
//        return false;

//    int num = stoi(s);
//    return num >= 0 && num < 256;
//}

////分割字符串s  i为剩余分割数量
//void legal_ip(vector<string> &result, string s, string str, int i) {
//    int sz = s.size();
//    //s刚好分割完
//    if (i == 0 && sz == 0) {
//        str.pop_back();     //弹出"."
//        result.push_back(str);
//        return;
//    }

//    string temp_s;
//    //字符串过长过短直接返回
//    if (sz > 3 * i || sz < i)
//        return;

//    //长度不足3时及时判断分割  以免循环长度len需求超过3时出错
//    if (sz < 3) {
//        if (i == 1) {
//            if (is_legal(s)) {          //可能出现"ab", a为0时不合法
//                str += s;
//                result.push_back(str);
//            }
//            return;
//        }
//        else if (i == 2) {      //只会出现"a.a",不用判断合法
//            s += ".";
//            swap(s[1], s[2]);
//            str += s;
//            result.push_back(str);
//            return;
//        }
//    }

//    //取s以len长度开头的分割方案
//    for (int len = 1; len < 4; ++len) {
//        temp_s = string(s.begin(), s.begin() + len);
//        if (is_legal(temp_s)) {
//            temp_s += ".";
//            legal_ip(result, string(s.begin() + len, s.end()), str + temp_s, i - 1);    //传值且下步循环重新赋值不需pop
//        }
//    }
//}

////                                  2021/10/22
//vector<string> question_93(string s) {
//    if (s.size() < 4 || s.size() > 12)
//        return vector<string>();

//    vector<string> result;
//    string str;
//    legal_ip(result, s, str, 4);
//    return result;
//}
