/* 一周中的第几天
给你一个日期，请你设计一个算法来判断它是对应一周中的哪一天。
输入为三个整数：day、month 和 year，分别表示日、月、年。
您返回的结果必须是这几个值中的一个 {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}。

示例 1：
输入：day = 31, month = 8, year = 2019
输出："Saturday"

示例 2：
输入：day = 18, month = 7, year = 1999
输出："Sunday"

示例 3：
输入：day = 15, month = 8, year = 1993
输出："Sunday"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/day-of-the-week
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>

using namespace std;

//                                          2022/1/3
string dayOfTheWeek(int day, int month, int year) {
    vector<string> week = {"Thursday", "Friday", "Saturday", "Sunday","Monday", "Tuesday", "Wednesday",  };

    long long days = (year - 1971) * 365 + (year - 1969) / 4;
    int m = 1;
    while (m < month) {
        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m== 10)
            days += 31;
        else if (m == 4 || m == 6 || m == 9 || m == 11)
            days += 30;
        else
            days += 28;
        ++m;
    }
    if (month > 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
        ++days;
    days += day ;
    return week[days % 7];
}
