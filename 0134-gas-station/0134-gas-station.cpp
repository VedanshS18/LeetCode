class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totGas = 0;
        int totCost = 0;

        int start = 0;
        int currGas = 0;

        for(int i = 0; i < n; i++){
            totGas += gas[i];
            totCost += cost[i];

            currGas += (gas[i] - cost[i]);

            if(currGas < 0){
                start = i+1;
                currGas = 0;
            }
        }
        return totGas < totCost ? -1 : start;
    }
};