///*二进制求和
//给你两个二进制字符串，返回它们的和（用二进制表示）。
//输入为 非空 字符串且只包含数字 1 和 0。

//示例 1:
//输入: a = "11", b = "1"
//输出: "100"

//示例 2:
//输入: a = "1010", b = "1011"
//输出: "10101"

//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/add-binary
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
//*/

//#include <string>

//using namespace std;

////二进制转十进制转二进制->当字符串过长，转换为十进制超出存储范围       2021/7/12
////string question_67(string a, string b){
////    int a_int = stoi(a, 0, 2);
////    int b_int = stoi(b, 0, 2);

////    int sum = a_int + b_int;
////    string str_sum = "";
////    if(!sum)
////        return "0";

////    while(sum != 0){
////        if(sum % 2)
////            str_sum = "1" + str_sum;
////        else
////            str_sum = "0" + str_sum;

////        sum /= 2;
////    }
////    return str_sum;
////}

////直接对字符串进行操作            2021/7/13
//string question_67(string a, string b){
//    if(a.size() < b.size())         //确保a为较长字符串
//        swap(a, b);
//    int sum = 0;
//    int a_end = a.size() - 1;
//    for(int b_end = b.size() - 1; b_end >= 0; --b_end){
//        sum += (b[b_end] == '1') ? 1 : 0;
//        sum += (a[a_end] == '1') ? 1 : 0;

//        a[a_end] = (sum % 2) ? '1' : '0';       //逢2进1
//        sum /= 2;
//        --a_end;
//    }

//    if(sum == 1 && a_end == -1)             //两字符串长度相同且最后有进位
//        return "1" + a;

//    while(sum == 1){
//        sum += (a[a_end] == '1') ? 1 : 0;
//        a[a_end] = (sum % 2) ? '1' : '0';

//        if(!a_end)                          //a直到首位仍有进位
//            return "1" + a;
//        sum /= 2;
//        --a_end;
//    }
//    return a;
//}
