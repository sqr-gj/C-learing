#include <vector>
#include <algorithm>

using namespace std;

//
int minimumDeletions(vector<int>& nums) {
    vector<int> c_nums = nums;
    sort(nums.begin(), nums.end());
    int sz = nums.size();
    if (sz == 1 || sz == 2)
        return sz;
    int min_num = nums[0];
    int max_num = nums[sz - 1];
    int min_p;
    int max_p;
    for (int i = 0; i < sz; ++i) {
        if (c_nums[i] == min_num)
            min_p = i;
        else if (c_nums[i] == max_num)
            max_p = i;
    }
    if (max_p < min_p)
        swap(min_p, max_p);
    int k = min(max_p + 1, sz - min_p);
    return min(k, min_p + 1 + sz - max_p);
}
