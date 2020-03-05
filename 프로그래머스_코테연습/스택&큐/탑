#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    int sz= heights.size();
    bool check = true;
    
    answer.push_back(0);
    for (int i=1; i<sz;i++)
    {
        for (int j=1; j <= i;j++)
        {
            if (heights[i] < heights[i-j])
            {
                answer.push_back(i-j+1);
                check = true;
                break;
            }
            else check = false;
        }
        if (check == false) answer.push_back(0);
    }
    
    return answer;
}
