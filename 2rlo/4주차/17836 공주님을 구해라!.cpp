// BOJ 17836 공주님을 구해라! https://www.acmicpc.net/problem/17836
// Created by JEY on 2024-01-27.

#include <iostream>
#include <queue>
using namespace std;

typedef struct {
    int x, y, gram;
} point;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, t;
    int map[101][101];
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    int visit[101][101][2];

    cin >> n >> m >> t;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }

    queue<point> q;
    q.push({0, 0, 0});
    visit[0][0][0] = 1;

    for(int time=0, size=0; time<=t; time++){
        size = q.size();
        while(size--){
            point cur = q.front();
            q.pop();
            if(cur.x == m-1 && cur.y == n-1){
                cout << time;
                return 0;
            }

            for(int i=0; i<4; i++){
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];

                if(nx <0 || nx >= m || ny < 0 || ny >= n)
                    continue;
                if((cur.gram == 1 || map[ny][nx] == 2) && !visit[ny][nx][1]){
                    visit[ny][nx][1] = 1;
                    q.push({nx, ny, 1});
                }
                else {
                    if(!visit[ny][nx][0] && map[ny][nx] == 0){
                        visit[ny][nx][0] = 1;
                        q.push({nx, ny, 0});
                    }
                }
            }
        }
    }

    cout << "Fail";

    return 0;
}