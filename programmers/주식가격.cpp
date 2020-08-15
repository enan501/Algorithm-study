#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<int> st;
    st.push(0);
    answer.assign(prices.size(),0);
    for(int i=1;i<prices.size();i++){
        if(prices[st.top()] <= prices[i])
            st.push(i);
        else{
            while(!st.empty()&& prices[st.top()]>prices[i]){
                answer[st.top()]= i - st.top();
                st.pop();
            }
            st.push(i);
        }
    }
    while(!st.empty()){
        if(prices.size()-1 - st.top() == 1)
            answer[st.top()]= 1;
        else
            answer[st.top()] = prices.size()- 1 - st.top();
        st.pop();
    }
    answer.back() = 0;
    return answer;
}


//int main(){
//    vector<int> prices;
//    prices.push_back(1);
//    prices.push_back(2);
//    prices.push_back(3);
//    prices.push_back(2);
//    prices.push_back(3);
//    prices.push_back(3);
//    prices.push_back(1);
//
//    for(int i=0;i<prices.size();i++)
//        cout<<prices[i];
//    cout<<endl;
//    vector<int> answer = solution(prices);
//    for(int i=0;i<answer.size();i++)
//        cout<<answer[i];
//}
