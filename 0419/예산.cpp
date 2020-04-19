#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long Totalsum(vector<int> budgets, int limit){
    long long sum = 0;
    
    for (int i=0;i<budgets.size();i++){
        if (limit <= budgets[i]) sum += limit;
        else sum += budgets[i];
    }
    return sum;
}

int solution(vector<int> budgets, int M) {
    int answer = 0;
    sort(budgets.begin(),budgets.end());
    int left = 0;
    int right = budgets[budgets.size()-1];
    int mid;
    long long total;
    
    if (Totalsum(budgets,right) <= M) return right;
    else {
        while(left <= right){
            mid = left + (right - left)/2;
            total = Totalsum(budgets, mid);
        
            if (left == mid){
                answer = left;
                break;
            }
            if (right == mid){
                answer = right;
                break;
            }
            if (total <= M){
                left = mid;
            } 
            else {
                right = mid;
            }
        }
        return answer;
    }
}
