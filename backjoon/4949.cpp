#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
    stack<char> *st;
    string str = "";
    bool flag = true;
    while (true)
    {
        std::getline(std::cin, str);
        if(str == ".")
        {
            break;
        }
        st = new stack<char>;
        flag = true;
        for (int idx = 0; idx < str.length(); idx++)
        {

            if (str[idx] != '(' && str[idx] != ')' && str[idx] != '[' && str[idx] != ']')
            {
                continue;
            }
            else if (str[idx] == '(' || str[idx] == '[')
            {
                st->push(str[idx]);
            }
            else if (str[idx] == ')')
            {
                if (st->empty() || st->top() != '(')
                {
                    flag = false;
                    break;
                }
                st->pop();
            }
            else if (str[idx] == ']')
            {
                if (st->empty() || st->top() != '[')
                {
                    flag = false;
                    break;
                }
                st->pop();
            }
        }
        if(!st->empty() || !flag)
        {

            cout << "no\n";
        }
        else
        {
            cout << "yes\n";
        }
        
        delete st;
    }
}