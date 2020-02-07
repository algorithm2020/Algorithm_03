class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
    
        int arr[1002];
        int sum=0;
        int n =costs.size();
        
        for (int i=0;i<n;i++)
        {
            if (costs[i][0] >= costs[i][1])
            {
                arr[i] = costs[i][1];
            }
            else {arr[i] = costs[i][0];}
        }
        
        for (int i=0;i<n;i++)
        {
            
            sum += arr[i];
        }
        return sum;
    }
};
