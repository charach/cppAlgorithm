#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
    string str;
    stack<char> st;
    cin >> str;

    long long result = 0;
    int temp = 1;
    bool flag = false;

    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '(')
        {
            temp *= 2;
            st.push(str[i]);
        }
        else if(str[i] == '[')
        {
            temp *= 3;
            st.push(str[i]);
        }
        else if(str[i] == ')' && (st.empty() || st.top() != '('))
        {
            flag = true;
            break;
        }
        else if(str[i] == ']' && (st.empty() || st.top() != '['))
        {
            flag = true;
            break;
        }
        else if(str[i] == ')')
        {
            if(str[i-1] == '(')
                result += temp;
            st.pop();
            temp /= 2;
        }
        else if(str[i] == ']')
        {
            if(str[i-1] == '[')
                result += temp;
            st.pop();
            temp /= 3;
        }
    }
    if(flag || !st.empty())
    {
        cout << 0 << "\n";
    
    }
    else
    {
        cout << result << "\n";
    }
    


    return 0;
}