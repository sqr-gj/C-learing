#include <vector>
#include <string>

using namespace std;

//                              2022/1/8
vector<int> grayCode(int n) {
    vector<string> result;
    result.push_back("0");
    result.push_back("1");
    for (int i = 0; i < n; ++i) {
        for(auto &s : result)
            s = "0" + s;
        for (int j = result.size() - 1; j >= 0; --j) {
            string s = result[j];
            s[0] = '1';
            result.push_back(s);
        }
    }
    vector<int> result_(result.size());
    for (int i = 0; i < result.size(); ++i) {
        int k = stoi(result[i], 0, 2);
        result_[i] = k;
    }
    return result_;
}
