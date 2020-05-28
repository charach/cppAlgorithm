#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


int queue[2000010];
int queueFront = 0;
int queueBack = 0;
int queueSize = 0;

int main(void)
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int N;
    cin >> N;

    string cmd; 
    while(N-->0)
    {
        cin >> cmd;

        if(cmd.find("push") != string::npos)
        {
            cin >> cmd;
            queue[queueBack++] = atoi(cmd.c_str());
            queueSize++;
        }
        else if(cmd.find("pop") != string::npos)
        {
            if( queueSize == 0)
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << queue[queueFront++] << "\n";
                queueSize--;
            }
        }
        else if(cmd.find("size") != string::npos)
        {
            cout << queueSize << "\n";
        }
        else if(cmd.find("empty") != string::npos)
        {
            if(queueSize == 0)
            {
                cout << "1\n";
            }
            else
            {
                cout << "0\n";
            }
        }
        else if(cmd.find("front") != string::npos)
        {
            if(queueSize == 0)
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << queue[queueFront] << "\n";
            }
            
        }
        else
        {
            if(queueSize == 0)
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << queue[queueBack-1] << "\n";
            }
        }
        
    }
}