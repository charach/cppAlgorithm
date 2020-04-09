#include <iostream>

using namespace std;
int main(void)
{
    int N = 0;
    
    cin >> N;

    int ary[201] = { 0, };

    int numBuf = 0;
    for(int i = 0 ; i < N ; i++)
    {
        cin >> numBuf;
        ary[numBuf+100]++;
    }

    cin >> numBuf;
    cout << ary[numBuf+100] << endl;
}