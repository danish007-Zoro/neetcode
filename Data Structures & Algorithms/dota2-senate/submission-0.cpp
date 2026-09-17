class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rq;
        queue<int>dq;

        for(int i=0; i<senate.size(); i++){
            if(senate[i]=='R'){
                rq.push(i);
            }
            else{
                dq.push(i);
            }
        }

        int position = senate.size();

        while(!rq.empty() && !dq.empty()){
            int rfront = rq.front();
            rq.pop();
            int qfront = dq.front();
            dq.pop();

            if(rfront < qfront){
                rq.push(position++);
            }
            else{
                dq.push(position++);
            }
        }

        return rq.empty() ? "Dire" : "Radiant";
    }
};