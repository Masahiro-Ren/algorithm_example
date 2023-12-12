#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Comparator {
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs)
    {
        return lhs.second > rhs.second;
    }
};

/**
 * graph is stored in a adjacency list
*/
void dijkstra(vector<vector<pair<int, int>>>& graph, int src)
{
    auto comparator = [](const pair<int, int>& lhs, const pair<int, int>& rhs){return lhs.second > rhs.second;};
    priority_queue<pair<int, int>, vector<pair<int, int>>, Comparator> pq;

    int N = graph.size();

    vector<int> dist(N, INT_MAX);
    dist[src] = 0;

    pq.push({src, 0});

    while(!pq.empty())
    {
        auto curInfo = pq.top(); pq.pop();
        int u = curInfo.first;
        int curDist = curInfo.second;

        if(curDist < dist[u]) continue;

        for(auto v : graph[u])
        {
            int mindist = dist[u] + v.second;
            if(mindist < dist[v.first])
            {
                dist[v.first] = mindist;
                pq.push({v.first, mindist});
            }   
        }
    }


    // print the result
    cout << "Vertex\t\tDistance\n";
    for(int i = 0; i < dist.size(); i++)
    {
        cout << i << "\t\t" << dist[i] << endl; 
    }
}


int main()
{
    vector<vector<int>> matrix = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    // build graph
    int N = matrix.size();
    vector<vector<pair<int, int>>> graph(N, vector<pair<int, int>>());
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(matrix[i][j] != 0)
            {
                graph[i].push_back({j, matrix[i][j]});
            }
        }
    }

    dijkstra(graph, 0);
    /**
       expect 
       Vertex          Distance
        0               0
        1               4
        2               12
        3               19
        4               21
        5               11
        6               9
        7               8
        8               14
    */

    return 0;
}