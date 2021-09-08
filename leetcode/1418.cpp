///*点菜展示表
//给你一个数组orders，表示客户在餐厅中完成的订单，确切地说，orders[i]=[customerNamei,tableNumberi,foodItemi]，其中
//customerNamei是客户的姓名，tableNumberi是客户所在餐桌的桌号，而foodItemi是客户点的餐品名称。
//请你返回该餐厅的点菜展示表。在这张表中，表中第一行为标题，其第一列为餐桌桌号 “Table”，后面每一列都是按字母顺序排列的餐品名称。
//接下来每一行中的项则表示每张餐桌订购的相应餐品数量，第一列应当填对应的桌号，后面依次填写下单的餐品数量。
//注意：客户姓名不是点菜展示表的一部分。此外，表中的数据行应该按餐桌桌号升序排列。

//示例 1：
//输入：orders = [["David","3","Ceviche"],["Corina","10","Beef Burrito"],["David","3","Fried Chicken"],["Carla","5","Water"],["Carla","5","Ceviche"],["Rous","3","Ceviche"]]
//输出：[["Table","Beef Burrito","Ceviche","Fried Chicken","Water"],["3","0","2","1","0"],["5","0","1","0","1"],["10","1","0","0","0"]]
//解释：
//点菜展示表如下所示：
//Table,Beef Burrito,Ceviche,Fried Chicken,Water
//3    ,0           ,2      ,1            ,0
//5    ,0           ,1      ,0            ,1
//10   ,1           ,0      ,0            ,0
//对于餐桌 3：David 点了 "Ceviche" 和 "Fried Chicken"，而 Rous 点了 "Ceviche"
//而餐桌 5：Carla 点了 "Water" 和 "Ceviche"
//餐桌 10：Corina 点了 "Beef Burrito"

//示例 2：
//输入：orders = [["James","12","Fried Chicken"],["Ratesh","12","Fried Chicken"],["Amadeus","12","Fried Chicken"],["Adam","1","Canadian Waffles"],["Brianna","1","Canadian Waffles"]]
//输出：[["Table","Canadian Waffles","Fried Chicken"],["1","2","0"],["12","0","3"]]
//解释：
//对于餐桌 1：Adam 和 Brianna 都点了 "Canadian Waffles"
//而餐桌 12：James, Ratesh 和 Amadeus 都点了 "Fried Chicken"

//示例 3：
//输入：orders = [["Laura","2","Bean Burrito"],["Jhon","2","Beef Burrito"],["Melissa","2","Soda"]]
//输出：[["Table","Bean Burrito","Beef Burrito","Soda"],["2","1","1","1"]]

//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/display-table-of-food-orders-in-a-restaurant
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
//*/

//#include <vector>
//#include <string>
//#include <unordered_map>
//#include <unordered_set>
//#include <algorithm>

//using namespace std;

////                  2021/7/6
//vector<vector<string>> displayTable(vector<vector<string>>& orders) {
//    unordered_set<string> food_namesSet;       //保存菜名
//    unordered_map<size_t, unordered_map<string, size_t>> tablesMap;       //保存每桌点餐情况

//    //读取点餐情况
//    for(auto order : orders){
//        food_namesSet.insert(order[2]);
//        ++tablesMap[stoi(order[1])][order[2]];
//    }

//    //对菜名进行排序
//    vector<string> food_names;
//    for(auto &name : food_namesSet)
//        food_names.push_back(name);

//    sort(food_names.begin(), food_names.end());

//    //对桌号进行排序
//    vector<size_t> table_num;
//    auto num = tablesMap.begin();
//    while(num != tablesMap.end()){
//        table_num.push_back(num++->first);
//    }

//    sort(table_num.begin(), table_num.end());

//    //点餐情况
//    vector<vector<string>> displaytables(tablesMap.size() + 1, vector<string>(food_names.size() + 1));
//    displaytables[0][0] = "Table";
//    copy(food_names.begin(), food_names.end(), displaytables[0].begin() + 1);

//    for(size_t i = 0; i < tablesMap.size(); ++i){
//        size_t id = table_num[i];      //桌号
//        auto cnt = tablesMap[id];       //桌号对应点餐情况
//        displaytables[i + 1][0] = to_string(id);
//        for(size_t j = 0; j < food_names.size(); ++j){
//            displaytables[i + 1][j + 1] = to_string(cnt[food_names[j]]);
//        }

//    }
//    return displaytables;
//}
