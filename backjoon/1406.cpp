#include <iostream>
#include <stdio.h>
#include <list>

using namespace std;
int main(void)
{
    list<char> list;

    string str;
    cin >> str;

    for(int i = 0 ; i< str.length();i++)
    {
        list.push_back(str[i]);
    }

    int M = 0;
    cin >> M;

    char buf = 0;

    std::list<char>::iterator iter = list.end();

    for(unsigned int i = 0 ; i < M; i++)
    {
        cin >> buf;

        if(buf == 'L')
        {
            iter = iter == list.begin() ? iter : iter--;
        }
        else if(buf == 'D')
        {
            iter = iter == list.end() ? iter : iter++;
        }
        else if(buf == 'B')
        {
            iter = list.erase(iter);
        }
        else if( buf == 'P')
        {
            cin >> buf;
            iter = list.insert(iter,buf);
        }
    }

    for( char ch : list)
    {
        cout << ch;
    }
    cout << "\n";
}