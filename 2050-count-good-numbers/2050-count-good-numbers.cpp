class Solution {
public:
    long long MOD=1000000007;
    int countGoodNumbers(long long n) {
        long long even =(n+1)/2;
        long long odd=n/2;
        long long first=pow(5,even);
        long long second=pow(4,odd);
      return (int)((first % MOD * second % MOD) % MOD);
    }
    long long pow(long long x,long long n){
        if(n==0)
        return 1;
        long long temp=pow(x,n/2);
        if(n%2==0){
            return (long long)(temp*temp)%MOD;
        }
        else{
            return (long long)(x*temp*temp)%MOD;
        }
    }
};