#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int size = 0; int color = 0;
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    queue<pair<int,int>> q;
    bool visit[101][101] = {false,}; //false로 초기화 안해주니까 오답?!
    
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (picture[i][j] != 0 && visit[i][j] == false)
            {
                size = 1;
                color = picture[i][j];
                q.push({i,j});
                visit[i][j] = true;
                while(!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    
                    for (int k=0;k<4;k++)
                    {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                    
                        if (nx >= 0 && nx < m && ny >=0 && ny < n )
                        {
                            if (picture[nx][ny] == color && visit[nx][ny]==false)
                            {
                                visit[nx][ny] = true;
                                q.push({nx,ny});
                                size ++;
                            }
                        }
                    }
                }
                max_size_of_one_area = max(size,max_size_of_one_area);
                number_of_area++;
            }
        }
    }
    
    
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
} 
