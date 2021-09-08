///*大餐计数
//大餐是指恰好包含两道不同餐品的一餐，其美味程度之和等于2的幂。
//你可以搭配任意两道餐品做一顿大餐。
//给你一个整数数组deliciousness ，其中 deliciousness[i]是第i​​​​​​​​​​​​​​道餐品的美味程度，返回你可以用数组中的餐品做出的不同大餐的数量。
//结果需要对10^9 + 7取余。

//注意，只要餐品下标不同，就可以认为是不同的餐品，即便它们的美味程度相同。

//示例 1：
//输入：deliciousness = [1,3,5,7,9]
//输出：4
//解释：大餐的美味程度组合为 (1,3) 、(1,7) 、(3,5) 和 (7,9) 。
//它们各自的美味程度之和分别为 4 、8 、8 和 16 ，都是 2 的幂。

//示例 2：
//输入：deliciousness = [1,1,1,3,3,3,7]
//输出：15
//解释：大餐的美味程度组合为 3 种 (1,1) ，9 种 (1,3) ，和 3 种 (1,7) 。

//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/count-good-meals
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
//*/

//#include <vector>
//#include <unordered_map>
//#include <algorithm>

//using namespace std;

//static constexpr int MOD = 1000000007;

////判断val是否为2的幂
//bool is_twopower(double val){
//    if(val == 1)
//        return true;
//    if(val == 0)
//        return false;
//    double val_2 = val / 2;
//    if(val_2 == 1)
//        return true;
//    else if(val_2 != int(val_2))
//        return false;
//    else
//        return is_twopower(val_2);;
//}

////暴力->超出时间限制                  2021/7/7
////int question_1711(vector<int>& deliciousness) {
////    int cnt = 0;                //计大餐数量
////    for(size_t i = 9; i < deliciousness.size() - 1; ++i){
////        for(size_t j = i + 1; j < deliciousness.size(); ++j){
////            double sum = deliciousness[i] + deliciousness[j];
//////            cout << sum << " ";
////                if(is_twopower(sum))
////                ++cnt;
//////            cout << (is_twopower(sum) ? "true" : "false") << endl;
////        }
////    }
////    return cnt;
////}

////哈希存储，当有重复元素时降低时间复杂度 ->超出时间限制          2021/7/12
////int  question_1711(vector<int>& deliciousness){
////    unordered_map<int, size_t> hs_deli;         //将餐品存入哈希表
////    for(auto &a : deliciousness)
////        ++hs_deli[a];

////    int cnt = 0;        //计大餐数量
////    for(auto first = hs_deli.begin(); first != hs_deli.end(); ++first){
////        auto nfirst = first;
////        if(is_twopower(2 * first->first))
////            cnt +=  (first->second * (first->second - 1)) / 2;
////        for(auto next_first = ++nfirst; next_first != hs_deli.end(); ++next_first){
////            if(is_twopower(first->first + next_first->first))
////                cnt += first->second * next_first->second;
////        }
//////        cnt = cnt % MOD;
////    }
////    return cnt;
////}

////
//int question_1711(vector<int> &deliciousness){
//    int max_sum = 0;
//    for(auto a : deliciousness)
//        max_sum = (max_sum > a) ? max_sum : a;
//    max_sum *= 2;

//    unordered_map<int, size_t> hs_deli;
//    int cnt = 0;
//    for(auto &a : deliciousness){
//        for(int sum = 1; sum <= max_sum; sum <<= 1){
//            int new_cnt = hs_deli.count(sum - a) ? hs_deli[sum - a] : 0;    //哈希表中有此元素即读出元素个数
//            cnt += new_cnt;
//        }
//        ++hs_deli[a];
//        cnt %=  MOD;
//    }
//    return cnt;
//}
