#include <iostream>
#include <vector>

using namespace std;

/**
 * an auxiliary funtion
*/
int getCloest(vector<int>& dist, vector<bool>& isSet)
{
    int min_dist = INT_MAX;
    int min_idx;
    for(int v = 0; v < dist.size(); v++)
    {
        if(!isSet[v] && dist[v] < min_dist)
        {
            min_dist = dist[v];
            min_idx = v;
        }
    } 

    return min_idx;
}


/**
 * a N-vertices graph is stored in a N by N matrix
 * matrix[u][v] is weight from u to v
 * 
 * NOTE dijkstra cannot process edge with negative weight
*/
void dijkstra(vector<vector<int>>& graph, int src)
{
    int N = graph.size();

    vector<int> dist(N, INT_MAX);
    vector<bool> isSet(N, false); 

    dist[src] = 0;

    for(int i = 0; i < N - 1; i++)
    {
        int u = getCloest(dist, isSet);

        isSet[u] = true;

        for(int v = 0; v < N; v++)
        {
            if(!isSet[v] && graph[u][v] != 0 && dist[u] != INT_MAX)
            {
                if(dist[u] + graph[u][v] < dist[v])
                {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    // print result
    cout << "Vertex\t\tDistance\n";
    for(int i = 0; i < graph.size(); i++)
    {
        cout << i << "\t\t" << dist[i] << endl;
    }
}

int main()
{
    vector<vector<int>> graph = {
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

    dijkstra(graph, 0);

    return 0;
}
