/* 统计出现过一次的公共字符串
给你两个字符串数组 words1 和 words2 ，请你返回在两个字符串数组中 都恰好出现一次 的字符串的数目。

示例 1：
输入：words1 = ["leetcode","is","amazing","as","is"], words2 = ["amazing","leetcode","is"]
输出：2
解释：
- "leetcode" 在两个数组中都恰好出现一次，计入答案。
- "amazing" 在两个数组中都恰好出现一次，计入答案。
- "is" 在两个数组中都出现过，但在 words1 中出现了 2 次，不计入答案。
- "as" 在 words1 中出现了一次，但是在 words2 中没有出现过，不计入答案。
所以，有 2 个字符串在两个数组中都恰好出现了一次。

示例 2：
输入：words1 = ["b","bb","bbb"], words2 = ["a","aa","aaa"]
输出：0
解释：没有字符串在两个数组中都恰好出现一次。

示例 3：
输入：words1 = ["a","ab"], words2 = ["a","a","a","ab"]
输出：1
解释：唯一在两个数组中都出现一次的字符串是 "ab" 。
*/

#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

//                                              2021/11/28
int question_5922(vector<string>& words1, vector<string>& words2) {
    sort(words1.begin(), words1.end());
    sort(words2.begin(), words2.end());
    int sz1 = words1.size();
    int sz2 = words2.size();
    int ptr1 = 0;
    int ptr2 = 0;
    int cnt = 0;
    while (ptr1 < sz1 && ptr2 < sz2) {
        //去重
        if (ptr1 < sz1 - 1 && words1[ptr1] == words1[ptr1 + 1]) {
            //双重去重
            while (ptr1 < sz1 - 1 && words1[ptr1] == words1[ptr1 + 1]){
                while (ptr1 < sz1 - 1 && words1[ptr1] == words1[ptr1 + 1])
                    ++ptr1;
                ++ptr1;
            }
        }
        if (ptr2 < sz2 - 1 && words2[ptr2] == words2[ptr2 + 1]) {
            while (ptr2 < sz2 - 1 && words2[ptr2] == words2[ptr2 + 1]){
                while (ptr2 < sz2 - 1 && words2[ptr2] == words2[ptr2 + 1])
                    ++ptr2;
                ++ptr2;
            }
        }
        if (ptr1 == sz1 || ptr2 == sz2)
            break;
        if (words1[ptr1] == words2[ptr2]){
            ++cnt;
            ++ptr1;
            ++ptr2;
        }
        else if (words1[ptr1] < words2[ptr2])
            ++ptr1;
        else
            ++ptr2;
    }
    return cnt;
}
