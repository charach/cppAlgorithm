#include <iostream>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

int ary[50][50];
int main(void)
{
    cout << "hiih"<< endl;
    printf("\33[2K\r");
    int a = 0;
    while(true)
    {
        printf("\033c\n");

    ary[0][0]++;
    for(int i = 0 ; i< 50;i++)
    {
        for(int j = 0 ; j< 50;j++)
        {
            printf("%d",ary[i][j]);
        }
        printf("\n");
    }
    sleep(1);

    }
}