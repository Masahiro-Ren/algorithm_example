#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class UF{
private:
    int count;
    vector<int> parent;
public:
    UF(int n)
    {
        count = n;
        parent = vector<int>(n);

        for(int i = 0; i < n; i++)
        {
            // each vertex will point to itself in the beginning
            parent[i] = i;
        }
    }

    // operations
    // union two sets
    void union_(int p , int q);
    // find the root of p
    int find(int p);
    // are p and q in the same set ?
    bool isConnected(int p, int q);
    // get the number of sets
    int getCount() {return count;};
};

void UF::union_(int p, int q)
{
    int rootP = find(p);
    int rootQ = find(q);

    if(rootP == rootQ) return;

    parent[rootQ] = rootP;

    count--;
}

int UF::find(int p)
{
    // find while compress the tree
    // this method will compress the tree into a very low height
    if(parent[p] != p)
        parent[p] = find(parent[p]);
    return parent[p];
}

bool UF::isConnected(int p, int q)
{
    int rootP = find(p);
    int rootQ = find(q);

    return (rootP == rootQ);
}

// a small test 
// minimum cost to connect all citys
// costs are represneted by a vector {city_a, city_b, cost}
int minCost(int n, vector<vector<int>>& connections)
{
    int mst = 0;
    UF uf(n + 1);

    // some greedy strategy, sort the connections by cost ascendingly
    std::sort(connections.begin(), connections.end(), [](const auto& lhs, const auto& rhs){
        return lhs[2] < rhs[2];
    });

    for(const auto& connection : connections)
    {
        int u = connection[0];
        int v = connection[1];
        int cost = connection[2];

        if(uf.isConnected(u, v)) continue;

        uf.union_(u, v);
        mst += cost;
    }

    return uf.getCount() == 2 ? mst : -1;

}


int main()
{
    int n = 3;
    vector<vector<int>> connections = {
        {1, 2, 5},
        {1, 3, 6},
        {2, 3, 1}
    };
    // expect 6
    cout << minCost(n, connections) << endl;
    return 0;
}