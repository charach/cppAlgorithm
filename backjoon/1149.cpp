#include <stdio.h>
#include <algorithm>

using namespace std;
int ary[1000][1000];
int val[1000][3];
int main(void)
{
    int N;
    scanf("%d",&N);
    
    for(int i = 0 ; i < N; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            scanf("%d",&val[i][j]);
        }
    }

    ary[0][0] = val[0][0];
    ary[0][1] = val[0][1];
    ary[0][2] = val[0][2];

    for(int i = 1 ; i< N; i++)
    {
        ary[i][0] = min(ary[i-1][1],ary[i-1][2]) + val[i][0];
        ary[i][1] = min(ary[i-1][0],ary[i-1][2]) + val[i][1];
        ary[i][2] = min(ary[i-1][0] , ary[i-1][1]) + val[i][2];
    }

    printf("%d\n",min({ary[N-1][0],ary[N-1][1],ary[N-1][2]}));
}