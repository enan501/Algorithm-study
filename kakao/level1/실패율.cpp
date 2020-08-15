#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> failed;
    vector<double> failrates;
    int clear = 0;
    answer.assign(N,0);
    failrates.assign(N,0);
    failed.assign(N,0);
    for(int i : stages){
        if((i-1)==N)
            clear++;
        else
            failed[i-1]++;
    }
    for(int i = N-1;i>=0;i--){
        answer[i] = i+1;
        clear += failed[i];
        if(clear != 0) failrates[i] = (double)failed[i] / clear;
    }
    stable_sort(answer.begin(),answer.end(),[&failrates](int i, int j) -> bool{return failrates[i-1]>failrates[j-1];});
    return answer;
}
