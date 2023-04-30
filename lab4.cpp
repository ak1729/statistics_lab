#include <iostream>
#include <ctime>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int main(){
    srand(time(0));
    cout<<"Input sample size: "<<endl;
    int n;
    cin>>n;

    cout<<"Input mean: "<<endl;
    double mu;
    cin>> mu;

    cout<<"Input variance: "<<endl;
    double sig;
    cin>> sig;
    
    double a[2];
    double ram[n];
    double num;
    for (int j = 0; j<n; j++){
      for (int i = 0; i< 2; i++){
        num = ((double)rand() / RAND_MAX);
        a[i]=num;
        //cout<<a[i]<<endl;
      }
      double put = sqrt(sig);
      double p = sqrt((-2)*(log(a[0])))*(cos(2*3.14159265359*a[1]));
      double q = (put*p)+mu;
      //cout<<q<<endl;
      ram[j]=q;
    }   
    double sum = 0;
    double mean;

    for (int i = 0; i<n; i++){
        sum = sum + ram[i];
      }
    mean = sum/n;
    cout<<"expected mean: "<< mean<<endl;

    double add = 0;
    double var;

    for (int i = 0; i< n; i++){
         add = add + pow((ram[i]-mean), 2);
      }
    var = add/n;
    cout<<"expected variance: "<<var<<endl;

    double up=0;
    double skit;
    double skew;
    for (int i=0; i<n;i++){
        up = up+pow((ram[i]-mean), 3);
    }
    skit = up/n;
    skew = skit/(pow(var, (3/2)));
    cout<<"Skewness: "<<skew<<endl;
    if(skew >0){
        cout<<"positively skewed"<<endl;
    }
    else{
        cout<<"negatively skewed"<<endl;
    }

    double down = 0;
    double tip;
    double kurt;
    for (int i=0; i<n;i++){
        down = down+pow((ram[i]-mean), 4);
    }
    tip = down/n;
    kurt=tip/(pow(var,2));
    cout<<"Kurtosis is: "<<kurt<<endl;
     if(kurt >3){
        cout<<"Leptokurtic sample"<<endl;
    }
    else{
        cout<<"Platykurtic sample"<<endl;
    }
    return 0;
}