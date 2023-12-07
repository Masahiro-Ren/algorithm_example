#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ======================================== Prim begin here ===========================
/**
 * Another prim algorithm, using adjacency list
 * edges are stored in a priority queue, which will obtain less time complxity
*/

// define a edge
struct Edge {
    int from;
    int to;
    int weight;

    Edge(int u, int v, int w) : from{u}, to{v}, weight{w} {}
};
// define a comparator for priority queue
// auto comparator = [](const Edge& e1, const Edge& e2){ return e1.weight < e2.weight; };
struct comparator {
    bool operator()(const Edge& e1, const Edge& e2)
    {
        return e1.weight > e2.weight;
    }
};
// variables will be used 
vector<bool> inMST;
vector<vector<Edge>> graph;
priority_queue<Edge, vector<Edge>, comparator> pq;
// to store the result
int W_SUM;

// some auxiliary functions
bool isAllconnected();
void cut(int v);

void Prim(vector<vector<Edge>>& graph)
{
    // TO-DO
    int N = graph.size();
    inMST = vector<bool>(N, false);
    W_SUM = 0;

    inMST[0] = true;
    cut(0);

    while(!pq.empty())
    {
        auto edge = pq.top(); pq.pop();
        int to = edge.to;
        if(inMST[to]) continue;

        W_SUM += edge.weight;
        inMST[to] = true;
        cut(to);
    }
}

bool isAllconnected()
{
    for(int i = 0; i < inMST.size(); i++)
    {
        if(!inMST[i]) return false;
    }

    return true;
}

void cut(int v)
{
    for(const auto& edge : graph[v])
    {
        int to = edge.to;
        if(inMST[to]) continue;
        pq.push(edge);
    }
}

// ====================================== End of Prim ===============================

// ========== a small test program: Leet Code #1135 ==========
/**
 *  Input data is an array of 3-tuple
 *  tuple format : {from, to, weight}
 * */ 
void buildGraph(vector<vector<int>>& data, int N)
{
    graph = vector<vector<Edge>>(N);
    for(const auto& line : data)
    {
       // the No. of city start from 1
       int u = line[0] - 1; 
       int v = line[1] - 1;
       int w = line[2];

       graph[u].push_back({u, v, w});
       graph[v].push_back({v, u, w});
    }
}

int minCost(int N, vector<vector<int>>& connections)
{
    buildGraph(connections, N);

    Prim(graph);

    if(!isAllconnected()) return -1;

    return W_SUM;
}

int main()
{
    int N = 3;
    vector<vector<int>> connections = {
        {1, 2, 5},
        {1, 3, 6},
        {2, 3, 1}
    };

    int res = minCost(N, connections);

    // expect 6
    cout << res << endl;

    return 0;
}