//정렬해주지 않으면 2중for문을 쓰게되어 시간초과가 남

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(),participant.end()); 
    sort(completion.begin(),completion.end());
    
    for (int i=0;i<participant.size();i++)
    {
        if (i == participant.size()-1)
        {
            answer = participant[i];
            break;
        }
        if(participant[i] != completion[i])
        {
            answer = participant[i];
            break;
        }
    }
    
    return answer;
}
