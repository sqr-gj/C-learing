#include <string>

using namespace std;

int minimumBuckets(string street) {
    int sz = street.size();
    if (sz == 1) {
        if (street[0] == '.')
            return 0;
        else
            return -1;
    }
    int cnt = 0;
    for (int i = 0; i < sz;) {
        if (street[i] == '.') {
            ++i;
            continue;
        }
        if (i == sz - 1){
            if (street[i - 1] == 'H')
                return -1;
            else {
                ++cnt;
                break;
            }
        }
        else {
            if (street[i + 1] == 'H'){
                if (i == 0 || street[i - 1] == 'H')
                    return -1;
                ++cnt;
                ++i;
            }
            else {
                ++cnt;
                i += 3;
            }

        }
    }
    return cnt;
}
