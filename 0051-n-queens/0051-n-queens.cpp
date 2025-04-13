class Solution {
    private:
    bool fill(int col,int row,vector<string>& board,int n){
        int duprow=row;
        int dupcol=col;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        row=duprow;
        col=dupcol;
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }
        row=duprow;
        col=dupcol;
        while(col>=0 && row<n){
            if(board[row][col]=='Q') return false;
            col--;
            row++;
        }
        return true;
    }
        void func(int col,vector<vector<string>>& sol,vector<string>& board,int n){
            if(col==n){
                sol.push_back(board);
                return;
            }
            for(int row=0;row<n;row++){
                if(fill(col,row,board,n)){
                    board[row][col]='Q';
                    func(col+1,sol,board,n);
                    board[row][col]='.';
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
        func(0,sol,board,n);
        return sol;
    }
};