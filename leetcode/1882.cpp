/* 使用服务器处理任务
给你两个 下标从 0 开始 的整数数组 servers 和 tasks ，长度分别为 n​​​​​​ 和 m​​​​​​ 。servers[i] 是第 i​​​​​​​​​​ 台服务器的 权重 ，
而 tasks[j] 是处理第 j​​​​​​ 项任务 所需要的时间（单位：秒）。
你正在运行一个仿真系统，在处理完所有任务后，该系统将会关闭。每台服务器只能同时处理一项任务。第 0 项任务在第 0 秒可以开始处理，相应地，
第 j 项任务在第 j 秒可以开始处理。处理第 j 项任务时，你需要为它分配一台 权重最小 的空闲服务器。如果存在多台相同权重的空闲服务器，请选择 下标最小 的服务器。如果一台空闲服务器在第 t 秒分配到第 j 项任务，那么在 t + tasks[j] 时它将恢复空闲状态。
如果没有空闲服务器，则必须等待，直到出现一台空闲服务器，并 尽可能早 地处理剩余任务。 如果有多项任务等待分配，则按照 下标递增 的顺序完成分配。

如果同一时刻存在多台空闲服务器，可以同时将多项任务分别分配给它们。
构建长度为 m 的答案数组 ans ，其中 ans[j] 是第 j 项任务分配的服务器的下标。
返回答案数组 ans​​​​ 。

示例 1：
输入：servers = [3,3,2], tasks = [1,2,3,2,1,2]
输出：[2,2,0,2,1,2]
解释：事件按时间顺序如下：
- 0 秒时，第 0 项任务加入到任务队列，使用第 2 台服务器处理到 1 秒。
- 1 秒时，第 2 台服务器空闲，第 1 项任务加入到任务队列，使用第 2 台服务器处理到 3 秒。
- 2 秒时，第 2 项任务加入到任务队列，使用第 0 台服务器处理到 5 秒。
- 3 秒时，第 2 台服务器空闲，第 3 项任务加入到任务队列，使用第 2 台服务器处理到 5 秒。
- 4 秒时，第 4 项任务加入到任务队列，使用第 1 台服务器处理到 5 秒。
- 5 秒时，所有服务器都空闲，第 5 项任务加入到任务队列，使用第 2 台服务器处理到 7 秒。

示例 2：
输入：servers = [5,1,4,3,2], tasks = [2,1,2,4,5,2,1]
输出：[1,4,1,4,1,3,2]
解释：事件按时间顺序如下：
- 0 秒时，第 0 项任务加入到任务队列，使用第 1 台服务器处理到 2 秒。
- 1 秒时，第 1 项任务加入到任务队列，使用第 4 台服务器处理到 2 秒。
- 2 秒时，第 1 台和第 4 台服务器空闲，第 2 项任务加入到任务队列，使用第 1 台服务器处理到 4 秒。
- 3 秒时，第 3 项任务加入到任务队列，使用第 4 台服务器处理到 7 秒。
- 4 秒时，第 1 台服务器空闲，第 4 项任务加入到任务队列，使用第 1 台服务器处理到 9 秒。
- 5 秒时，第 5 项任务加入到任务队列，使用第 3 台服务器处理到 7 秒。
- 6 秒时，第 6 项任务加入到任务队列，使用第 2 台服务器处理到 7 秒。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/process-tasks-using-servers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <algorithm>
#include <deque>
#include <queue>

using namespace std;

//
vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
    //超时                            2021/12/22
    int n = servers.size();
    vector<vector<int>> f_servers(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        f_servers[i][0] = servers[i];   //权重
        f_servers[i][1] = i;            //下标
    }
    //按权重排序，权重相同按下标排序
    sort(f_servers.begin(), f_servers.end(), [](vector<int> &a, vector<int> &b) {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    });

    //将权重重置为剩余运行时间，0表示空闲
    for(int i = 0; i < n; ++i)
        f_servers[i][0] = 0;

    int cnt = 0;    //当前已添加的任务下标
    int cnt_end = 1; //当前已添加的任务下标尾
    int m = tasks.size();
    vector<int> result(m);
    while (cnt < m) {
        int ptr = 0;
        int min_time = 200000;
        //当前存在任务且有空闲服务器
        while (cnt < cnt_end && ptr < n) {
            //ptr所指向空闲服务器
            if (f_servers[ptr][0] == 0) {
                result[cnt] = f_servers[ptr][1];
                f_servers[ptr][0] = tasks[cnt];
                ++cnt;
            }
            min_time = min(min_time, f_servers[ptr][0]);
            ++ptr;
        }

        if (cnt == cnt_end) {         //当前无任务
            ++cnt_end;      //向后添加一个任务
            //服务器全部-1s
            for (int i = 0; i < n; ++i) {
                if (f_servers[i][0] > 0)
                    --f_servers[i][0];
            }
        }
        else {                      //还有任务，说明无空闲服务器
            //将这段时间进来的任务加入任务队列中
            cnt_end = cnt_end + min_time > m ? m : cnt_end + min_time;

            //所有服务器运行时间减去最短时间
            for (int i = 0; i < n; ++i) {
                f_servers[i][0] -= min_time;
            }
        }
    }
    priority_queue<int> q;
    return result;
}
