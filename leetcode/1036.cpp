#include <vector>
#include <deque>

using namespace std;

//No pass               2022/1/11
bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
    if (blocked.size() < 2)
        return true;
    vector<vector<int>> plant(1000000, vector<int>(1000000));
    for (int i = 0; i < blocked.size(); ++i) {
        plant[blocked[i][0]][blocked[i][1]] = 1;
    }
    deque<pair<int, int>> source_;
    source_.push_back({source[0], source[1]});
    while (!source_.empty()) {
        int x = source_.front().first;
        int y = source_.front().second;
        source_.pop_front();
        if (x == target[0] && y == target[1])
            return true;

        if (x > 0 && plant[x - 1][y] != 1)
            source_.push_back({x - 1, y});
        if (x < 999999 && plant[x + 1][y] != 1)
            source_.push_back({x + 1, y});

        if (y > 0 && plant[x][y - 1] != 1)
            source_.push_back({x, y - 1});
        if (y < 999999 && plant[x][y + 1] != 1)
            source_.push_back({x, y + 1});
    }
    return false;
}
