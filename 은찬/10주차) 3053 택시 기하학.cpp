#include <iostream>
#include <cstdio>
#define PI 3.141592653589793238462643383279502884197169

using namespace std;

int main(void){
    double R;
    
    scanf("%lf", &R);
    
    printf("%.6lf\n%.6lf\n", PI * R * R, 2 * R * R);

    return 0;
}