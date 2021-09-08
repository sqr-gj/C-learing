/*反转字符串中的单词Ⅲ
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例：
输入："Let's take LeetCode contest"
输出："s'teL ekat edoCteeL tsetnoc"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-words-in-a-string-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>
#include <sstream>

using namespace std;

//读取每个单词进行操作                          2021/7/25
//string question_557(string s) {
//    istringstream read(s);
//    string word;
//    string reverse_s;

//    while (read >> word) {
//        int left = 0;
//        int right = word.size() - 1;
//        while (left < right) {
//            swap(word[left++], word[right--]);
//        }
//        reverse_s += word + " ";
//    }
//    reverse_s.erase(reverse_s.size() - 1);
//    return reverse_s;
//}

//识别空格，在字符串上进行反转            2021/7/25
string question_557(string s){
    int left = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == ' '){
            int right = i - 1;
            while (left < right) {
                swap(s[left++], s[right--]);
            }
            left = i + 1;
        }
    }

    int right = s.size() - 1;
    while (left < right) {
        swap(s[left++], s[right--]);
    }

    return s;
}
