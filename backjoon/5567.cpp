#include <stdio.h>
#include <vector>
#define FRIEND 1
using namespace std;

int ary[500][500];
bool boolary[500];
int main(void)
{
    int n;
    int m;
    scanf("%d",&n);
    scanf("%d",&m);

    int a,b;
    for(int i = 0 ; i< n; i++)
    {
        boolary[i] = false;
    }
    for(int i = 0; i<m ; i++)
    {
        scanf("%d %d",&a,&b);
        ary[a-1][b-1] = FRIEND;
        ary[b-1][a-1] = FRIEND; 
    }
    vector<int> vect;

    for(int i = 1; i< n ; i++)
    {
        if(ary[0][i] == FRIEND){
            vect.push_back(i);
            boolary[i] =true;
        }
    }

    while(vect.size() != 0)
    {
        int numBuf = vect.back();
        vect.pop_back();
        for(int i = 1; i< n; i++)
        {
            if(ary[numBuf][i] == FRIEND)
            {
                boolary[i]  = true;
            }
        }
    }
    int cnt = 0;
    boolary[0] = false;
    for(int i = 0 ; i< n; i++)
    {
        if(boolary[i])
        {
            cnt++;
        }
    }
    printf("%d\n",cnt);

}