#include <iostream>
#include <vector>

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
// valid tree
bool validTree(int n, vector<vector<int>>& edges)
{
    UF uf(n);

    for(auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        if(uf.isConnected(u, v)) return false;

        uf.union_(u, v);
    }

    return uf.getCount() == 1;
}



int main()
{
    int n = 5;
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {0, 3}, {0, 4}};
    vector<vector<int>> edges2 = {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};

    // expect true
    cout << boolalpha << validTree(n, edges1) << endl;
    // expect false
    cout << boolalpha << validTree(n, edges2) << endl;

    return 0;
}