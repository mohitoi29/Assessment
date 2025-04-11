class Solution {
private:
 void func(int index,vector<vector<string>>& sol,vector<string>& path,string s){
    int n=s.length();
    if(index==n){
        sol.push_back(path);
        return;
    }
    for(int i=index;i<n;i++){
        if(isPalindrome(s,index,i)){
            path.push_back(s.substr(index,i-index+1));
            func(i+1,sol,path,s);
            path.pop_back();
        }
    }
 }
 bool isPalindrome(string s,int start,int end){
    while(start<=end){
        if(s[start++]!=s[end--])
            return false;        
    }
    return true;
 }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> sol;
        vector<string> path;
        func(0,sol,path,s);
        return sol;
    }
};