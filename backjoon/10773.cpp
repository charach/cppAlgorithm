#include <iostream>

int stack[200000];

using namespace std;
int main(void)
{
    int stackPoint = 0;
    int K = 0;
    cin >> K;

    int num = 0;
    for (int i = 0; i < K; i++)
    {
        cin >> num;

        switch (num)
        {
        case 0:
            stackPoint--;
            break;
        default:
            stack[stackPoint++] = num;
        }
    }

    long sum = 0;
    for (int i = 0; i < stackPoint; i++)
    {
        sum += stack[i];
    }
    cout << sum << endl;
}
