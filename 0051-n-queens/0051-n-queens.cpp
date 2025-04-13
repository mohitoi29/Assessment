class Solution {
    private:
    // bool fill(int col,int row,vector<string>& board,int n){
    //     int duprow=row;
    //     int dupcol=col;
    //     while(row>=0 && col>=0){
    //         if(board[row][col]=='Q') return false;
    //         row--;
    //         col--;
    //     }
    //     row=duprow;
    //     col=dupcol;
    //     while(col>=0){
    //         if(board[row][col]=='Q') return false;
    //         col--;
    //     }
    //     row=duprow;
    //     col=dupcol;
    //     while(col>=0 && row<n){
    //         if(board[row][col]=='Q') return false;
    //         col--;
    //         row++;
    //     }
    //     return true;
    // }
        void func(int col,vector<vector<string>>& sol,vector<string>& board,int n,vector<int>& left,vector<int>& leftUpDiagonal,vector<int>& leftDownDiagonal){
            if(col==n){
                sol.push_back(board);
                return;
            }
            for(int row=0;row<n;row++){
                if(left[row]==0 && leftUpDiagonal[(n-1)+(col-row)]==0 && leftDownDiagonal[row+col]==0){
                    left[row]=1;
                    leftUpDiagonal[(n-1)+(col-row)]=1 ;
                      leftDownDiagonal[row+col]=1;
                    board[row][col]='Q';
                    func(col+1,sol,board,n,left,leftUpDiagonal,leftDownDiagonal);
                    board[row][col]='.';
                    left[row]=0;
                     leftUpDiagonal[(n-1)+(col-row)]=0 ;
                      leftDownDiagonal[row+col]=0;
                }
            }
        }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> sol;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<int> left(n,0);
        vector<int> leftUpDiagonal(2*n-1,0);
        vector<int> leftDownDiagonal(2*n-1,0);
        func(0,sol,board,n,left,leftUpDiagonal,leftDownDiagonal);
        return sol;
    }
};