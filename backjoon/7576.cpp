#include <iostream>
#include <queue>
#define RIPE_TOMATO 1
#define UNRIPE_TOMATO 0
#define EMPTY -1

int ary[1001][1001];
using namespace std;
int totalCnt = 0;

struct Node
{
    int x;
    int y;
};

int day = 0;
queue<Node> qu1;
queue<Node> qu2;
int M, N;

void RIPE(Node node)
{
    int aryX[] = {-1, 0, 1, 0};
    int aryY[] = {0, -1, 0, 1};
    for (int i = 0; i < 4; i++)
    {
        int tmpX = node.x + aryX[i];
        int tmpY = node.y + aryY[i];
        if (tmpX < 0 || tmpX >= N)
        {
            continue;
        }
        if (tmpY < 0 || tmpY >= M)
        {
            continue;
        }
        if (ary[tmpX][tmpY] == UNRIPE_TOMATO)
        {
            totalCnt--;
            Node node = {tmpX, tmpY};
            ary[tmpX][tmpY] = RIPE_TOMATO;

            if (day % 2 == 0)
            {
                qu2.push(node);
            }
            else
            {
                qu1.push(node);
            }
        }
    }
}

int main(void)
{
    cin >> M >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> ary[i][j];
            if (ary[i][j] == UNRIPE_TOMATO)
            {
                totalCnt++;
            }
            else if (ary[i][j] == RIPE_TOMATO)
            {
                Node node = {i, j};

                qu1.push(node);
            }
        }
    }

    while (true)
    {
        if (day % 2 == 0)
        {
            if (qu1.empty())
            {
                break;
            }
            Node node = qu1.front();
            qu1.pop();
            RIPE(node);
            if(qu1.empty())
            {
                day++;
            }
        }
        else
        {
            if (qu2.empty())
            {
                break;
            }
            Node node = qu2.front();
            qu2.pop();
            RIPE(node);
            if(qu2.empty())
            {
                day++;
            }
        }

        if(qu1.empty() && qu2.empty())
        {
            break;
        }
    }

    if (totalCnt != 0)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << day -1 << "\n";
    }
}