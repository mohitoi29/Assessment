class Solution {
public:
    long long calculateScore(vector<string>& ins, vector<int>& values) {
        int i=0;
        vector<int> arr(values.size(),0);
        long long score=0;
        while(i>=0 && i<values.size() && arr[i]!=1){
            arr[i]=1;
        if(ins[i]=="jump"){
            i=i+values[i];
            
        }
       else if(ins[i]=="add"){
            score+= static_cast<long long> (values[i]); 
            i++;
        }
        }
        return score;
    }
};