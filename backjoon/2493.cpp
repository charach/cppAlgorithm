#include <iostream>
#include <stack>

using namespace std;
typedef struct building{
    int height;
    int index;
} build;

build tower[500010];


int main(void)
{

    stack<build> stack;
    int N;
    cin >> N;

    for(int i = 0 ; i< N; i++)
    {
        cin >> tower[i].height;
        tower[i].index = i+1;
    }

    cout << "0 ";

    stack.push(tower[0]);
    for(int i =1 ; i< N; i++)
    {
        while(stack.size() != 0)
        {
            if(tower[i].height > stack.top().height)
            {
                stack.pop();
            }
            else
            {
                cout << stack.top().index << " ";
                break;
            }
        }
        if(stack.size() == 0)
        {
            cout << "0 ";
        }
        stack.push(tower[i]);
    }
    cout << "\n";

}