#include <string>
#include <vector>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int cur = 1;
    vector<int> originPoint{0,0,0};
    for(int i=0;i<3;i++){
        if(dartResult[cur] == '0'){
            cur++;
            originPoint[i] = 10;
        } else
            originPoint[i] = dartResult[cur-1] - '0';
        if(dartResult[cur] == 'D'){
            originPoint[i] *= originPoint[i];
        }
        else if(dartResult[cur] == 'T'){
            originPoint[i] *= (originPoint[i]*originPoint[i]);
        }
        if(cur < dartResult.length()-1 && dartResult[++cur] == '*'){
            if(i!=0) answer += originPoint[i-1];
            originPoint[i] *= 2;
            cur++;
        }else if(dartResult[cur] == '#'){
            originPoint[i] *= -1;
            cur++;
        }
        answer += originPoint[i];
        cur++;
    }
    return answer;
}
