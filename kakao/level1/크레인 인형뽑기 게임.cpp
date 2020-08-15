#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(vector<vector<int> > board, vector<int> moves) {
    int answer = 0;
        int n = board.size();
    vector<int> top;
    stack<int> st;
    for (int j = 0; j < n; j++){
        bool check = false;
        for (int i = 0; i < n; i++){
            if(board[i][j] != 0){
                top.push_back(i);
                check = true;
                break;
            }
        }
        if(!check) top.push_back(n);
    }
    for(int i=0;i<moves.size();i++){
        if(top[moves[i]-1] == n) continue;
        if(!st.empty() && st.top() == board[top[moves[i]-1]][moves[i]-1]){
            st.pop();
            answer+=2;
        }
        else {
            st.push(board[top[moves[i]-1]][moves[i]-1]);
        }
        top[moves[i]-1]++;
    }
    return answer;
}
