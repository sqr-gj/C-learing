/*最短公共超序列
给出两个字符串 str1 和 str2，返回同时以 str1 和 str2 作为子序列的最短字符串。如果答案不止一个，则可以返回满足条件的任意一个答案。
（如果从字符串 T 中删除一些字符（也可能不删除，并且选出的这些字符可以位于 T 中的 任意位置），可以得到字符串 S，那么 S 就是 T 的子序列）

示例：
输入：str1 = "abac", str2 = "cab"
输出："cabac"
解释：
str1 = "abac" 是 "cabac" 的一个子串，因为我们可以删去 "cabac" 的第一个 "c"得到 "abac"。
str2 = "cab" 是 "cabac" 的一个子串，因为我们可以删去 "cabac" 末尾的 "ac" 得到 "cab"。
最终我们给出的答案是满足上述属性的最短字符串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-common-supersequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <iostream>
#include <vector>

using namespace std;

//关于子序列定义（下面子序列定义为字符串中一段连续子字符串）->与题中定义有差别           2021/7/21
//string question_1092(string str1, string str2) {
//    if(str1 == str2)        //两相同字符串
//        return str1;

//    if(str1.size() < str2.size())
//        swap(str1, str2);

//    if(str1.find(str2) != string::npos)         //str2为str1的子字符串
//        return str1;

//    string s1;
//    for(int i = 0; i < str2.size(); ){           //str1前部分与str2后部分重合
//        int k = str2.find(str1[0], i);
//        if(k == string::npos)
//            break;
//        int j = 0;
//        for(int m = k; m < str2.size(); ++m){
//            if(str2[m] == str1[j++]){
//                if(m == str2.size() - 1){
//                    string s(str2, 0, k);
//                    s1 = s + str1;
//                }
//                continue;
//            }
//            else
//                break;;
//        }
//        i = k + 1;
//        if(s1 != "")
//            break;
//    }

//    string s2;
//    for(int i = 0; i < str1.size(); ){           //str2前部分与str1后部分重合
//        int k = str1.find(str2[0], i);
//        if(k == string::npos)
//            break;
//        int j = 0;
//        for(int m = k; m < str1.size(); ++m){
//            if(str2[m] == str1[j++]){
//                if(m == str1.size() - 1){
//                    string s(str1, 0, k);
//                    s2 = s + str2;
//                }
//                continue;
//            }
//            else
//                break;;
//        }
//        i = k + 1;
//        if(s2 != "")
//            break;
//    }

//    //检测s1与s2，避免返回空字符串
//    if(s1.size()){
//        if(s2.size())
//            return (s1.size() > s2.size()) ? s2 : s1;
//        else
//            return s1;;
//    }
//    else {
//        if(s2.size())
//            return s2;
//    }


//    string s3 = str1 + str2;                //str1、str2无重合部分
//    return s3;
//}

string question_1092(string str1, string str2){
        vector<int> d(str2.size()+1,0);
        vector<string> s(str2.size()+1,"");
        int pre;
        string pres;
        int b;
        string t;
        for(int i=0;i<=str1.size();++i){
            for(int j=0;j<=str2.size();++j){
                b=d[j];
                t=s[j];
                if(i==0 || j==0){
                    d[j] = 0;
                    if(i)
                        s[j] = str1.substr(0,i);
                    if(j)
                        s[j] = str2.substr(0,j);
                }
                else{
                    int a=d[j];
                    int b=d[j-1];
                    if(a <= b){
                        d[j] = b;
                        s[j] = s[j-1]+str2[j-1];
                    }else{
                        d[j] = a;
                        s[j] = s[j]+str1[i-1];
                    }
                    if(str1[i-1] == str2[j-1]){
                        if(d[j] < pre+1){
                            d[j]=pre+1;
                            s[j]=pres+str2[j-1];
                        }
                    }
                }
                pre=b;
                pres=t;
            }
        }
        return s[str2.size()];
}

//int main()
//{
//    string s1 = "bbbaaaba";
//    string s2 = "bbababbb";
//    cout << question_1092(s1, s2);
//    return 0;
//}
