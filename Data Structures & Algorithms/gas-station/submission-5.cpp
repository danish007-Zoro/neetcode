class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasc = 0, tcost = 0, start = 0, curr = 0;

        for(int i=0; i<gas.size(); i++){
            gasc += gas[i];
            tcost += cost[i];
            curr += gas[i] - cost[i];

            if(curr < 0){
                start = i + 1;
                curr = 0;
            }
        }

        return gasc >= tcost ? start : -1;
    }
};
