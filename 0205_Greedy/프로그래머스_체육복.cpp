#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n-lost.size();
    
    for (int i=0;i<lost.size();i++){ //여벌있는 학생이 도난당한 경우
        for(int j=0;j<reserve.size();j++){
            if (lost[i] == reserve[j]){
                lost.erase(lost.begin()+i);
                reserve.erase(reserve.begin()+j);
                i--;
                j--;
                answer ++; }}}
    
    for (int i=0;i<lost.size();i++){
        for(int j=0;j<reserve.size();j++){            
            if (lost[i]+1 == reserve[j] || lost[i]-1 == reserve[j]){
                reserve.erase(reserve.begin()+j);
                answer ++; 
                break; } }} //lost[3]이고 reserve[2,4]경우 break없으면 둘 다 걸려서 에러남.
    
    return answer;
}
