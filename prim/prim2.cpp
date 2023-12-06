#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * Another prim algorithm, using adjacency list
*/

struct Edge {
    int from;
    int to;
    int weight;

    Edge(int u, int v, int w) : from{u}, to{v}, weight{w} {}
};

bool isAllconnected();

void cut(int v);

void Prim(vector<vector<Edge>>& graph)
{
    // TO-DO
}


int main()
{
    return 0;
}