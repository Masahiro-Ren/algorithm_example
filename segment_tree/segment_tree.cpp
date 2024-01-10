#include <iostream>
#include <vector>

using namespace std;

// segment tree optimized with lazy mark
class SegmentTree {
private:
    vector<int> tree;
    vector<int> lazy;

    int root, end;

    void build(int s, int t, int p, vector<int>& raw)
    {
        if(s == t) 
        {
            tree[p] = raw[s];
            return;
        }

        int m = s + ((t - s) >> 1);

        build(s, m, p * 2, raw);
        build(m + 1, t, p * 2 + 1, raw);

        tree[p] = tree[p * 2] + tree[(p * 2) + 1];
    }

    int rangeSum(int l, int r, int s, int t, int p)
    {
        if(l <= s && t <= r) return tree[p];
        int m = s + ((t - s) >> 1);
        int sum = 0;

        maintain(s, t, p);

        if(l <= m) sum += rangeSum(l, r, s, m, p * 2);
        if(r > m) sum += rangeSum(l, r, m + 1, t, p * 2 + 1);
        return sum;
    }

    void rangeAdd(int l, int r, int val, int s, int t, int p)
    {
        if(l <= s && t <= r)
        {
            lazy[p] += val;
            tree[p] += (t - s + 1) * val;
            return;
        }

        int m = s + ((t - s) >> 1);
        maintain(s, t, p);

        if(l <= m) rangeAdd(l, r, val, s, m, p * 2);
        if(r > m) rangeAdd(l, r, val, m + 1, t, p * 2 + 1);

        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }

    void rangeSet(int l, int r, int val, int s, int t, int p)
    {
        if(l <= s && t <= r)
        {
            lazy[p] = val;
            tree[p] = (t - s + 1) * val;
            return;
        }

        int m = s + ((t - s) >> 1);
        maintain(s, t, p);

        if(l <= m) rangeSet(l, r, val, s, m, p * 2);
        if(r > m) rangeSet(l, r, val, m + 1, t, p * 2 + 1);

        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }

    void maintain(int s, int t, int p)
    {
        int m = s + ((t - s) >> 1);
        if(s != t && lazy[p] != 0)
        {
            lazy[p * 2] += lazy[p];
            lazy[p * 2 + 1] += lazy[p];
            tree[p * 2] += lazy[p] * (m - s + 1);
            tree[p * 2 + 1] += lazy[p] * (t - m);
            lazy[p] = 0;
        }
    }
public:
    SegmentTree(vector<int> raw_data)
    {
        int n = raw_data.size();
        tree = vector<int>(4 * n, 0);
        lazy = vector<int>(4 * n, 0);

        root = 1;
        end = n - 1;

        build(0, n - 1, 1, raw_data);
    }


    int getSum(int l, int r)
    {
        return rangeSum(l, r, 0, end, root);
    }

    void Add(int l, int r, int val)
    {
        rangeAdd(l, r, val, 0, end, root);
    }

    void Set(int l, int r, int val)
    {
        rangeSet(l, r, val, 0, end, root);
    }

    void display(int p, int depth = 0)
    {
        if(p > tree.size() || tree[p] == 0) return;

        display(p * 2, depth + 1);
        for(int i = 0; i < depth; i++) putchar('\t');
        cout << tree[p] << ":" << lazy[p] << endl;
        display(p * 2 + 1, depth + 1);
    }
};


int main()
{
    vector<int> array = {10, 11, 12, 13, 14};

    SegmentTree segTree(array);

    segTree.display(1);

    cout << "get sum in range [3, 5] : " << segTree.getSum(2, 4) << endl;

    segTree.Add(2, 4, 5);
    cout << "After add 5 in range [3, 5] \n";
    segTree.display(1);

    segTree.Set(2, 4, 15);
    cout << "After set all to 15 in range[3, 5] \n";
    segTree.display(1);

    return 0;
}