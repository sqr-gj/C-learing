#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;


vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
    sort(meetings.begin(), meetings.end(), [](vector<int> &a, vector<int> &b) {return a[2] < b[2];});
    unordered_set<int> peo_know;
    peo_know.insert(0);
    peo_know.insert(firstPerson);
    int sz = meetings.size();
    int max_time = meetings[sz - 1][2];
    int ptr = 0;
    for (int time = 0; time <= max_time; ++time) {
        while (ptr < sz && meetings[ptr][2] <= time) {
            if (peo_know.count(meetings[ptr][0]) || peo_know.count(meetings[ptr][1])){
                peo_know.insert(meetings[ptr][0]);
                peo_know.insert(meetings[ptr][1]);
           }
            ++ptr;
        }
    }
    vector<int> result;
    for (auto &p : peo_know)
        result.push_back(p);
    return result;
}
