#include <iostream>
#include <queue>

using namespace std;

int map[501][501];
bool mapVisited[501][501];
int maxArea = 0;
int cnt = 0;
int width = 0, height = 0;
typedef struct
{
    int x;
    int y;
} node;

int bfs(int i, int j)
{
    int xAry[4] = {0, 1, 0, -1};
    int yAry[4] = {1, 0, -1, 0};

    queue<node> qu;
    node *buf = new node;
    buf->x = i;
    buf->y = j;
    qu.push(*buf);
    int total = 0;
    mapVisited[i][j] = true;
    while (!qu.empty())
    {
        node tmp = qu.front();
        qu.pop();
        total++;
        for (int idx = 0; idx < 4; idx++)
        {
            int xTmp = tmp.x + xAry[idx];
            int yTmp = tmp.y + yAry[idx];
            if (xTmp < height && yTmp < width)
            {
                if (!mapVisited[xTmp][yTmp] && map[xTmp][yTmp] == 1)
                {
                    mapVisited[xTmp][yTmp] = true;

                    buf = new node;
                    buf->x = xTmp;
                    buf->y = yTmp;
                    qu.push(*buf);
                }
            }
        }
    }

    return total;
}

int main(void)
{
    cin >> height >> width;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cin >> map[i][j];
            mapVisited[i][j] = false;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (!mapVisited[i][j] && map[i][j] == 1)
            {
                int ret = bfs(i, j);
                maxArea = maxArea > ret ? maxArea : ret;
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
    cout << maxArea << "\n";
}