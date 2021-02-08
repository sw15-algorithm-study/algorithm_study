#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

int main(void){
    long long N, A, B, C, ans = 0;
    queue<long long> place;

    cin >> N;

    for(int i = 0; i < N; i++){
        scanf("%lld", &A);
        place.push(A);
    }

    scanf("%lld %lld", &B, &C);

    ans += N;

    //총감독관이 감시할 수 있는 응시자 수 빼기
    for(int i = 0; i < N; i++){
    	long long student = place.front() - B;
    	
    	if(student > 0){
    		place.push(place.front() - B);	
    	}
        place.pop();
    }

    //큐가 빌 때까지 반복
    while(!place.empty()){
        if(place.front() >= C){
            // 부감독관이 감시할 수 있는 응시자 수가 남은 학생보다 작은 경우
        	long long student = place.front() % C;
        	
            ans += place.front() / C;
            
            if(student > 0){
            	place.push(student);
            }
        }
        else{
            // 부감독관이 감시할 수 있는 응시자 수가 남은 학색보다 큰 경우
            ans++;
        }

        place.pop();
    }
    
    printf("%lld", ans);
    
    return 0;
}