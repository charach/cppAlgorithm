#include <stdio.h>

using namespace std;

int ary[100];
int main(void)
{
    int n,m;
    scanf("%d %d",&n,&m);

    for(int i = 0 ; i< n;i++)
    {
        scanf("%d",&ary[i]);
    }
    int minM = -400000;
    bool flag = true;
    for(int i = 0 ; i< n;i++)
    {
        for(int j = 1 ; j< n; j++)
        {
            if( j == i) continue;
            for(int k = 2; k < n; k++)
            {
                if( k == i || k == j) continue;
                if( ary[i] + ary[j] + ary[k] <= m  && ( ( m - ary[i] - ary[j] - ary[k]) < m - minM))
                {
                    minM = ary[i] + ary[j] + ary[k];
                    if(m - minM == 0)
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if(!flag)
                break;
        }
        if(!flag)
            break;
    }
    printf("%d\n",minM);
}