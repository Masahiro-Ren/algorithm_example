#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minKey(vector<int>& keys, vector<bool>& inMST)
{
    int n = inMST.size();
    int min = INT_MAX;
    int min_idx;

    for(int i = 0; i < n; i++)
    {
        if( !inMST[i] && keys[i] < min)
        {
            min = keys[i];
            min_idx = i;
        }
    }

    return min_idx;
}

void printMST(vector<int>& parent, vector<vector<int>>& graph)
{
    int N = graph.size();

    cout << "Edge\tWeight\n";
    for(int i = 1; i < N; i++)
    {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << endl;
    }
}
// graph is a N x N matrix
// graph[i][j] is weight value of edge i to j
void Prim(vector<vector<int>>& graph)
{
    int N = graph.size();

    vector<int> parent(N);
    vector<int> keys(N, INT_MAX);
    vector<bool> inMST(N, false);

    keys[0] = 0;
    parent[0] = -1;

    for(int i = 0; i < N - 1; i++)
    {
        int u = minKey(keys, inMST);

        inMST[u] = true;

        for(int v = 0; v < N; v++)
        {
            if(graph[u][v] != 0 && !inMST[v])
            {
                if(graph[u][v] < keys[v])
                {
                    parent[v] = u;
                    keys[v] = graph[u][v];
                }
            }
        }
    }

    printMST(parent, graph);
}


int main()
{
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };


    Prim(graph);

    return 0;
}
