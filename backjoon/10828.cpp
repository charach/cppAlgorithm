#include <iostream>

int stack[20000];

using namespace std;
int main(void)
{
    int N = 0;

    cin >> N;

    string str;
    int stackPoint = 0, num = 0;
    while(N-->0)
    {
        cin >> str;

        if(str.find("push") != string::npos)
        {
            cin >> num;
            stack[stackPoint++] = num;
        }
        else if(str.find("pop") != string::npos)
        {
            if(stackPoint == 0)
            {
                cout << "-1" << endl;
            }
            else
            {
                stackPoint--;
                cout << stack[stackPoint] << endl;
            }
        }
        else if(str.find("size") != string::npos)
        {
            cout << stackPoint << endl;
        }
        else if(str.find("empty") != string::npos)
        {
            cout << (stackPoint == 0 ? 1 : 0) << endl;
        }
        else if(str.find("top") != string::npos)
        {
            if(stackPoint == 0)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << stack[stackPoint-1] << endl;
            }
        }   
    }
}