#include <bits/stdc++.h>
using namespace std;

int board[501][501];
bool vist[501][501];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    } // 입력 받기

    int max_area = 0; // 최대 넓이
    int max_num = 0;  // 최대 갯수
    int count_area = 0;
    queue<pair<int, int>> Q;

    for (int i = 0; i < n; i++)

    {
        for (int j = 0; j < m; j++)
        { 
            if (board[i][j] == 1 && vist[i][j] != 1)
            {
                Q.push({i, j});
                vist[i][j] = 1;
                count_area  = 0;
                max_num++;
                while (!Q.empty())
                {
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int x = cur.first + dx[dir];x   
                        int y = cur.second + dy[dir];
                        if (x > n || y > m || x < 0 || y < 0)continue;
                        if (board[x][y] != 1 || vist[x][y])continue;
                        vist[x][y] = 1;
                        Q.push({x, y});
                    }
                    count_area++;
                }
                if(max_area<count_area)
                max_area = count_area;
            }
        }
    }

    cout<<max_num<<"\n"<<max_area;

    return 0;
}