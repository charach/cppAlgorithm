#include <iostream>
#include <list>

using namespace std;

int main(void)
{
    int N = 0, K = 0;
    cin >> K >> N;

    list<int> list;

    for(int i = 1; i <= K; i++)
    {
        list.push_back(i);
    }

    N--;
    std::list<int>::iterator iter = list.begin();

    cout << "<";
    int iterPos = 0;
    for(int i = 0 ; i < K ; i++)
    {
        iter = list.begin();

        iterPos = (N + iterPos) % list.size();
        
        std::advance(iter,iterPos);
        
        cout << *iter;

        list.erase(iter);
        
        if(list.size() > 0)
        {
             cout << ", ";
        }
    }
    cout << ">\n";
}