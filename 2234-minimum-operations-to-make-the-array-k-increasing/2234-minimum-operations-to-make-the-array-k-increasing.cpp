class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int n=arr.size();
        int len=0;
        for(int i=0;i<k;i++){
            vector<int>lis;
            for(int j=i;j<n;j=j+k){
                if(lis.empty() || lis.back()<=arr[j])
                    lis.push_back(arr[j]);
                    else{
                        int index=upper_bound(lis.begin(),lis.end(),arr[j])-lis.   begin();
                        lis[index]=arr[j];
                    }
            }
             len+=lis.size();
        }
        return arr.size()-len;
    }
};