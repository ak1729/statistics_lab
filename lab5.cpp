#include <bits/stdc++.h>
#include <cmath>

using namespace std;

// Define the function to integrate
double f(double x) {
    return exp(-(x*x)/2);
}

// Define the Simpson's 1/3 rule function
double simpson(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        double x = a + i*h;
        sum += (i % 2 == 0) ? 2*f(x) : 4*f(x);
    }

    return sum * h / 3.0;
}

int main() {
    double a, b;
    int n;
    cout<<"Enter lower limit: "<<endl; cin>>a;
    cout<<"Enter z: "<<endl; cin>>b;
    cout<<"Enter the subinterval: "<<endl; cin>>n;

    double integral = (1.0/(sqrt(2.0*3.1415)))*simpson(a, b, n);
    cout<<setprecision(5);
    cout<<integral<<endl;

   map<float, float> ans;
    float z=-3.0;
    while(z<=3.0){
        float integral = (1.0/(sqrt(2.0*3.1415)))*simpson(a, z, n);
        cout<<setprecision(5);
        ans[z]=(z>=0? integral: 1.0-integral);
        z+=0.01;
    } 
    
    for(auto &it: ans){
        cout<<setprecision(5);
        cout<<it.first<<" "<<it.second<<endl; 
    }


    return 0;
}
