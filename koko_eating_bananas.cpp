class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int n=piles.size();
        int l=1;
        int r=piles[n-1];
        while(l<r){
            int mid=l+(r-l)/2;
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=(piles[i]+mid-1)/mid;
            
            }
            
            if(sum>h){
                l=mid+1;
                
            }
            else{
                r=mid;
                

            }
            
        }
        
        
        return l;
    }
};
