#include <stdio.h>
#include <map>
using namespace std;


int main(void)
{
    map<int,bool> map;

    int n,m;
    scanf("%d",&n);
    int numBuf;

    for(int i = 0 ; i< n;i++)
    {
        scanf("%d",&numBuf);
        map.insert(std::make_pair(numBuf,true));
    }

    scanf("%d",&m);
    for(int i = 0 ; i< m; i++)
    {
        scanf("%d",&numBuf);
        if(map.find(numBuf) != map.end()){
            printf("1\n");
        }else{
            printf("0\n");
        }
    }
}