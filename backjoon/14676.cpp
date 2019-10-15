#include <stdio.h>
#include <vector>
using namespace std;

int ary[100001];
int aryDegree[100001];
int aryCurDegree[100001];
vector<int> preAry[100001];

void addDegree(int x,int value)
{
    vector<int>::iterator iter;
    for(iter = preAry[x].begin(); iter != preAry[x].end(); iter++)
    {
        aryCurDegree[*iter] += value;
    }
}

int main(void)
{
    int N,M,K;

    scanf("%d %d %d",&N,&M,&K);

    int x,y;
    for(int i = 0 ; i < M;i++)
    {
        scanf("%d %d",&x,&y);
        preAry[x].push_back(y);
        aryDegree[y]++;
    }

    bool gameFlag = true;

    for(int i = 0 ; i < K; i++)
    {
        scanf("%d %d",&x,&y);
        if(gameFlag)
        {
            if(x == 1)
            {
                if(aryCurDegree[y] == aryDegree[y])
                {
                    if( ary[y] == 0)
                    {
                        addDegree(y,1);
                    }
                    ary[y]++;
                }
                else 
                {
                    gameFlag = false;
                }
                
            }
            else
            {
                if(ary[y] == 1)
                {
                    addDegree(y,-1);
                }
                else if(ary[y] == 0)
                {
                    gameFlag = false;
                }
                ary[y]--;
            }
        }
    }

    if(gameFlag)
    {
        printf("King-God-Emperor\n");
    }
    else
    {
        printf("Lier!\n");
    }
    

}