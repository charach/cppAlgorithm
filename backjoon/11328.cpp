#include <iostream>
#include <string>

using namespace std;

bool checkStr(string str1, string str2)
{
    int ary[26] = {0 ,};

    for( char ch : str1 )
    {
        ary[ch-'a']++;
    }

    for( char ch : str2 )
    {
        ary[ch-'a']--;
        if(ary[ch-'a'] < 0 )
        {
            return false;
        }
    }
    return true;
}

int main(void)
{
    int N = 0;
    cin >> N;

    string str1,str2;
    for(int i = 0 ; i < N ; i++)
    {
        cin >> str1 >> str2;
        if( str1.length() == str2.length() && checkStr(str1,str2) )
        {
            cout << "Possible" << endl;
        }
        else
        {
            cout << "Impossible" << endl;
        }
    }
}