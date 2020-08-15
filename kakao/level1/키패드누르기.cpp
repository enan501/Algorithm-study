#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int curL = 3;
    int curR = 3;
    int isLOnL = 1;
    int isROnR = 1;
    char h = 'L';
    
    if(hand[0] == 'r')
        h = 'R';
    for(int i=0;i<numbers.size();i++){
        if(numbers[i]%3 == 1){
            answer += 'L';
            curL = numbers[i]/3;
            isLOnL = 1;
        }
        else if(numbers[i] >0 && numbers[i]%3 == 0) {
            answer += 'R';
            curR = numbers[i]/3-1;
            isROnR = 1;
        }
        else{
            if(numbers[i] == 0)
                numbers[i] = 11;
            if(abs(curL - numbers[i]/3) + isLOnL < abs(curR - numbers[i]/3) + isROnR){ //0,1,2,3
                answer += 'L';
                isLOnL = 0;
                curL = numbers[i]/3;
            }
            else if(abs(curL - numbers[i]/3)+ isLOnL > abs(curR - numbers[i]/3)+ isROnR){
                answer += 'R';
                isROnR = 0;
                curR = numbers[i]/3;
            }
            else{
                answer += h;
                if(h == 'L'){
                    isLOnL = 0;
                    curL = numbers[i]/3;
                }
                else{
                    isROnR = 0;
                    curR = numbers[i]/3;
                }
            }
        }
    }
    return answer;
}
