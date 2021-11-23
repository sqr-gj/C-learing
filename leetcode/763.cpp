/* 划分字母区间
字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。返回一个表示每个字符串片段的长度的列表。

示例：
输入：S = "ababcbacadefegdehijhklij"
输出：[9,7,8]
解释：
划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-labels
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <numeric>

using namespace std;

//                              2021/11/9
vector<int> question_763(string s) {
   vector<bool> lett(26);
   vector<int> result;
   deque<char> find_;
   int sz = s.size();
   int max_right = 0;
   int left = 0;
   int sum = 0;
   while (sum < sz) {
       find_.push_back(s[sum]);
       lett[s[sum] - 'a'] = true;

       while (!find_.empty()) {
           int right = sz - 1;
           char c = find_.front();
           find_.pop_front();
           while (s[right] != c) {
              --right;
           }
           if (right > max_right) {
               while (left < right) {
                   if (!lett[s[left] - 'a']) {
                       find_.push_back(s[left]);
                       lett[s[left] - 'a'] = true;
                   }
                   ++left;
               }
               max_right = right;
           }
       }
       result.push_back(max_right - sum + 1);
       sum = accumulate (result.begin(), result.end(), 0);
   }
   return result;
}
