#include <iostream>
#include <string>

using namespace std;
int main(void)
{
    string str;
    cin >> str;

    int depth = 0;
    int result = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            if (str[i - 1] == '(')
            {
                depth++;
            }
        }
        else if (str[i] == ')')
        {
            if (str[i - 1] == ')')
            {
                depth--;
                result++;
            }
            else
            {
                result += depth;
            }
            
        }
    }
    cout << result << "\n";
}