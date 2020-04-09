#include <iostream>

using namespace std;

int main(void)
{
    int boy[6] = { 0, };
    int girl[6] = { 0, };

    int N = 0;
    int K = 0;

    cin >> N >> K;
    int S,Y;
    S = Y = 0;
    
    for(int i = 0 ; i < N; i++)
    {
        cin >> S >> Y;
        if(S)
        {
            boy[Y-1]++;
        }
        else
        {
            girl[Y-1]++;
        }
    }

    int totalCnt = 0;

    for(int i = 0 ; i < 6; i++)
    {
        totalCnt += (boy[i] / K) + (girl[i] / K);
        totalCnt += ( boy[i] % K == 0 ? 0 : 1);
        totalCnt += ( girl[i] % K == 0 ? 0 : 1);
    }
    cout << totalCnt << endl;
}