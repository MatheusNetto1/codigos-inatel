#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double Raiz(double x, double x0, double e);

int main(){
    double x, x0, R;
    double e;

    cin >> x >> x0 >> e;

    R = Raiz(x, x0, e);

    cout << fixed << setprecision(4) << R << endl;

    return 0;
}

double Raiz(double x, double x0, double e){
    double mod;

    mod = fabs(pow(x0, 2) - x);

    if(mod <= e){
        return x0;
    }

    else{
        return Raiz(x, (pow(x0, 2) + x)/(2 * x0), e);
    }
}