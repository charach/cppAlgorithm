#include <iostream>

using namespace std;
int main(void)
{
    int ary[26] = { 0,};

    string str;

    cin >> str;
    for(int i = 0 ; i< str.length() ; i++)
    {
        ary[str[i]-'a']++;
    }

    for(int i = 0 ; i< 26 ; i++)
    {
        cout << ary[i] << " ";
    }
    cout << endl;
}