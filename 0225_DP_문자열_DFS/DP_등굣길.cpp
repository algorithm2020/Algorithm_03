// 좌표값이 (행,열)값이 아니라 (x축,y축)으로 입력이 되어있어서 헷갈렸음 ㅜ

#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int D[101][101] = {0,};

    for (int k=0;k<puddles.size();k++)
    {    
        int x=puddles[k][1]; //행,열 값 주의!!
        int y=puddles[k][0];
        D[x][y] = -1;
    }
        
    for(int i=1; i<=n;i++)
    {
        for (int j=1; j<=m;j++)
        {
            if (i==1 && j==1) D[i][j] = 1;
            else if (D[i][j] == -1) D[i][j] = 0;
            else D[i][j] = (D[i-1][j] + D[i][j-1]) % 1000000007;
        }
    }
    answer = D[n][m];
    
    return answer;
}
