#include <iostream>
#include <vector>
#define CONNECT 1
#define VIRUS 1
using namespace std;
int ary[101][101];
int comAry[101];
int main(void)
{


    int comCount,line;
    cin >> comCount;
    cin >> line;

    for(int i = 0 ; i < line; i++ ){
        int a,b;
        cin >> a >> b;
        ary[a][b] = CONNECT;
        ary[b][a] = CONNECT;
    }

    for(int i = 0 ; i<= comCount; i++){
        comAry[i] = 0;
    }

    vector<int> vector;

    vector.push_back(1);

    while(vector.size() != 0)
    {
        int buf = vector.back();
        vector.pop_back();
        comAry[buf] = VIRUS;
        for(int i = 0 ; i <= comCount; i++)
        {
            if(ary[buf][i] == CONNECT && comAry[i] != VIRUS){
                vector.push_back(i);
            }
        }        
    }
    int total = 0;
    for(int i = 2; i<= comCount;i++)
    {
        if(comAry[i] == VIRUS){
            total++;
        }
    }
    cout << total << endl;
}