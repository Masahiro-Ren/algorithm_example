#include <iostream>
#include <vector>

using namespace std;

// segment tree optimized with lazy mark
class SegmentTree {
private:
    vector<int> tree;
    vector<int> lazy;
    vector<int>* raw;

    int root, end;

    void build(int s, int t, int p)
    {
        if(s == t) 
        {
            tree[p] = (*raw)[s];
        }

        int m = s + ((t - s) >> 1);

        build(s, m, p * 2);
        build(m + 1, t, p * 2 + 1);

        tree[p] = tree[p * 2] + tree[(p * 2) + 1];
    }

    int rangeSum(int l, int r, int s, int t, int p)
    {
        return 0;
    }

    void rangeAdd(int l, int r, int val, int s, int t, int p)
    {
        return;
    }

    void maintain(int s, int t, int p)
    {
        return;
    }
public:
    SegmentTree(vector<int> arr)
    {
        int n = arr.size();
        tree = vector<int>(4 * n, 0);
        lazy = vector<int>(4 * n, 0);
        raw = &arr;

        root = 1;
        end = n - 1;

        build(0, n - 1, 1);

        raw = nullptr;
    }


    int getSum(int l, int r)
    {
        return rangeSum(l, r, 0, end, root);
    }

    void Add(int l, int r, int val)
    {
        rangeAdd(l, r, val, 0, end, root);
    }

    void display(int p, int depth = 0)
    {
        if(p > tree.size() || tree[p] == 0) return;

        display(p * 2, depth + 1);
        for(int i = 0; i < depth; i++) putchar('\t');
        cout << tree[p] << ":" << lazy[p];
        display(p * 2 + 1, depth + 1);
    }
};