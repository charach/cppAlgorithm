#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(void)
{
    string str1, str2;
    cin >> str1;
    cin >> str2;

    int ary[26] = {0,};

    for( char ch : str1)
    {
        ary[ch-'a']++;
    }

    for( char ch : str2)
    {
        ary[ch-'a']--;
    }

    int totalNum = 0;
    for(int i = 0 ; i < 26; i++)
    {
        totalNum += abs(ary[i]);
    }

    cout << totalNum << endl;
}