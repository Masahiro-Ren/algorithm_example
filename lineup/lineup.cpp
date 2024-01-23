/**
 * Problem Description
 * There are N people ordered in a line
 * Their information is stored in an array A{a1, a2, ...., an}, which means:
 *  1. if a_i is -1, indicates the i th person is in the front of the line
 *  2. otherwise the a_i indicates the i th person is right behind the a_i th person
 * 
 * plese output the real order of these people
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    int F, A;

    cin >> N;

    vector<int> arr(N + 1);
    /**
     * Basic idea:
     * arr[A] = i represents the person i is right behind the person A
     * Just write the code as description :D
    */
    for(int i = 1; i <= N; i++)
    {
        cin >> A;
        if(A == -1) 
            F = i;
        else
            arr[A] = i;
    }

    cout << F;

    for(int i = 1; i < N; i++)
    {
        F = arr[F];
        cout << " " << F;
    }

    cout << endl;

    return 0;
}