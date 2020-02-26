#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> slice;
    int cnt = 0;
    for (int i=0; i<commands.size();i++)
    {
        for (int j=commands[i][0]-1; j<commands[i][1];j++)
        {
            slice.push_back(array[j]);
            cnt++;
        }
        sort(slice.begin(),slice.end());
        answer.push_back(slice[commands[i][2]-1]);
        
        for (int k=0;k<cnt;k++) 
        {   
            slice.pop_back(); //slice 비워줘야함.
        }
        cnt = 0;
    }
    return answer;
}
