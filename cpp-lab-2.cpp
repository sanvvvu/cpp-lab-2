#include <iostream>
#include <cmath>                            // для вызова функции степени pow
using namespace std;

long long int dvoinoi_factorial(int x){          // создаём функцию для x!! 

    if(x <= 1) return 1;
    else{
        long long int res = dvoinoi_factorial(x-2) * x;
        return res;
    } 
}
long double t(long double x){                // создаём функцию для t(x) из условия
    long double numerator, denominator;      // отдельно посчитаем числитель и знаменатель
    
    numerator = 0.0;
    denominator = 0.0;
    
    for(int k = 0; k <= 10; k++){
        numerator += ((pow(x, 2*k+1)) / (dvoinoi_factorial(2*k+1)));
        denominator += ((pow(x, 2*k)) / (dvoinoi_factorial(2*k)));
    }
    
    return numerator / denominator;             // итоговое значение t(x)
}

int main(){
    long double y, answer;
    
    cout << "Enter a value y: ";
    cin >> y;
    
    answer = (7*(t(0.25)) + 2*(t(1+y))) / (6 - (t((pow(y, 2)) - 1)));         // формула из условия
    
    cout << "The final value of the expression: " << answer;
    
    return 0;
}