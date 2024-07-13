class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        vector<int>actual(n);
        
        for(int i=0;i<n;i++){
            actual[i]=i;

        }
        auto lambda=[&](int &i,int &j){
            return positions[i]<positions[j];
        };
        sort(begin(actual),end(actual),lambda);
        vector<int>result;
        stack<int>st;
        for(auto &cri : actual){
            if(directions[cri]=='R'){
                st.push(cri);
            }
            else{
                while(!st.empty() && healths[cri]>0){
                    int tidx= st.top();
                    st.pop();
                    if(healths[tidx] > healths[cri]){
                        healths[tidx]-=1;
                        healths[cri]=0;
                        st.push(tidx);
                    }
                    else if(healths[tidx]<healths[cri]){
                        healths[cri]-=1;
                        healths[tidx]=0;

                    }
                    else{
                        healths[cri]=0;
                        healths[tidx]=0;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(healths[i]>0){
                result.push_back(healths[i]);
            }
        }
        return result;

    }
};
