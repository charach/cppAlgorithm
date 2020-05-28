#include <iostream>
#include <stack>

using namespace std;

int building[80010];
int main(void)
{
    int N;
    cin >> N;

    for(int i = 0 ; i < N; i++)
    {
        cin>> building[i];
    }

    stack<int> s;

    long long sum = 0;

    for(int i = 0 ; i< N; i++)
    {
        while(!s.empty() && s.top() <= building[i])
        {
            s.pop();
        }
        sum += s.size();


        s.push(building[i]);
    }

    cout << sum << endl;
}