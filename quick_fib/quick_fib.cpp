#include <iostream>
#include <cstring>

using namespace std;

struct Matrix {
    int val[2][2];

    Matrix() { memset(val, 0, sizeof(val)); }

    Matrix operator*(const Matrix& b) const
    {
        Matrix res;

        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
                for(int k = 0; k < 2; k++)
                {
                    res.val[i][j] = res.val[i][j] + this->val[i][k] * b.val[k][j];
                }

        return res;
    }
};

void quick_pow(Matrix& ans, Matrix& base, int N)
{
    while(N > 0)
    {
        if(N & 1) ans = ans * base;
        base = base * base;
        N >>= 1;
    }
}

int main()
{
    Matrix ans, base;
    /**
     * Init
     */
    ans.val[0][0] = ans.val[0][1] = 1;
    base.val[0][0] = base.val[0][1] = base.val[1][0] = 1;

    // fib(12) = 144
    int N = 12;
    quick_pow(ans, base, N-2);

    cout << ans.val[0][0] << endl;
    return 0;
}