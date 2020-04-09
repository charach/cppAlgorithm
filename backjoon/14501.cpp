#include <iostream>

using namespace std;

typedef struct{
    int T = 0;
    int P = 0;
}work;

int max(int a, int b)
{
    return a > b ? a : b;
}

int main(void)
{
    int N = 0;
    cin >> N;
    work workAry[17];
    int maxAry[17] = {0,};

    for(int i =  0; i < N; i++)
    {
        cin >> workAry[i].T >> workAry[i].P;
    }

    int maxValue = 0;

    for(int i = 0 ; i<  N+1; i++)
    {
        if(workAry[i].T + i < N+1 )
        {
            maxAry[i + workAry[i].T] = max(maxAry[i + workAry[i].T], maxAry[i] + workAry[i].P );
        }

        maxAry[i+1] = max( maxAry[i], maxAry[i+1]);
        maxValue = max(maxValue, maxAry[i+1]);
    }
    cout << maxValue << endl;

}