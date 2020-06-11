#include <iostream>
#include <queue>
#define WALL "#"
#define SPACE "."

using namespace std;

int C, R;
char ary[1001][1001];

struct Node
{
    int x;
    int y;
};

int jCnt = 1;

queue<Node> jQ;
queue<Node> fQ;

int main(void)
{
    cin >> R >> C;

    int jX, jY;
    for (int i = 0; i < C; i++)
    {
        for (int j = 0; j < R; j++)
        {
            cin >> ary[i][j];
            switch (ary[i][j])
            {
            case 'J':
                Node node = {i, j};
                jQ.push(node);
                break;
            case 'F':
                Node node = {i, j};
                fQ.push(node);
                break;
            }
        }
    }

    int cnt = 0;

    int aryX[] = {-1, 0, 1, 0};
    int aryY[] = {0, -1, 0, 1};
    int tmpX, tmpY;
    while (true)
    {
        cnt = jQ.size();

        while (cnt-- > 0)
        {
            for (int i = 0; i < 4; i++)
            {
                Node tmpN = jQ.front();
                tmpX = tmpN.x + aryX[i];
                tmpY = tmpN.y + aryY[i];
                

            }
        }
    }
}
