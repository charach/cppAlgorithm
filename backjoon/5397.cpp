#include <iostream>
#include <list>

using namespace std;
int main(void)
{


    int num = 0;
    cin >> num;

    while(num-->0)
    {
        list<char> list;

        
        string str;
        cin >> str;
        std::list<char>::iterator iter = list.begin();

        for(int i = 0 ; i< str.length();i++)
        {
            switch(str[i])
            {
                case '-' :
                    if(iter != list.begin())
                    {
                        iter--;
                        iter = list.erase(iter);
                    }
                break;

                case '<':
                    if(iter != list.begin())
                    {
                        iter--;
                    }
                break;
                case '>':
                    if(iter != list.end())
                    {
                        iter++;
                    }
                break;

                default:
                    list.insert(iter,str[i]);
            }
        }
        for( char ch : list)
        {
            cout << ch;
        }
        cout << "\n";
    }

}