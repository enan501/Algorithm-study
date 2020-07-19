#include <string>
#include <vector>
using namespace std;

vector<bool> dig(int n, int a){
    vector<bool> s;
    s.assign(n,false);
    int count = n-1;
    bool isNotZero = a>=1;
    while(a>1){
        s[count--] = (a%2==1);
        a/=2;
    }
    if(isNotZero) s[count] = true;
    return s;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    answer.assign(n, "");
    for(int i=0;i<n;i++){
        vector<bool> s1 = dig(n,arr1[i]);
        vector<bool> s2 = dig(n,arr2[i]);
        for (int j=0;j<n;j++)
            if(s1[j] || s2[j]) answer[i].append("#");
            else answer[i].append(" ");
    }
    return answer;
}
