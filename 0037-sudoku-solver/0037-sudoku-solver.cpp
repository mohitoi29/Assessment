class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char ch='1' ;ch <='9';ch++ ){
                        if(isPossible(board,ch,i,j)){
                            board[i][j]=ch;
                            if(solve(board)==true)
                            return true;
                            else{
                                board[i][j]='.';
                            }
                        }
                    }
                     return false;
                }
            }
        }
        return true;
    }
    bool isPossible(vector<vector<char>>& board,char ch,int row,int col){
        for(int i=0;i<9;i++){
            if(board[row][i]==ch)return false;
            if(board[i][col]==ch)return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==ch)return false;
        }
    return true;
    }
};