#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double data[], int N, double rtn[]){
    double ari = 0, geo = 1, har = 0, max = data[0], min = data[0];
    for(int i = 0; i < N; i++){
        max = data[i] > max ? data[i] : max;
        min = data[i] < min ? data[i] : min;
        ari += data[i];
        geo *= data[i];
        har += 1/data[i];
    }

    ari = ari/N;
    geo = pow(geo, 1./N);
    har = N/har;

    double sd = 0;
    for(int i = 0; i < N; i++) sd += pow((data[i]-ari),2);
    sd = sqrt(sd/N);

    rtn[0] = ari;
    rtn[1] = sd;
    rtn[2] = geo;
    rtn[3] = har;
    rtn[4] = max;
    rtn[5] = min;
}