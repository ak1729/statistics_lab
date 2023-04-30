#include<bits/stdc++.h>
using namespace std;
#define M 2000
#define pi 3.1415927
 
double f(double z){
        return exp(-pow(z,2)/2)/sqrt(2*pi);
}
 
double integral(double z){
        double h = (z-(-M))/10000;
        double sum = f(z)+f(-M);
        for(int i=1; i<10000; i++){
                if(i%2 == 0) sum += (2*f(-M+i*h));
                else sum += (4*f(-M+i*h));
        }
 
        double ans = (h/3)*sum;
 
        return ans;
}
 
int observe(double data[], pair<double,double> p){
        int ans = 0;
        for(int i=0; i<100; i++){
                if(data[i] > p.first && data[i] <= p.second) ans++;
        }
        return ans;
}
 
int main(){
        double data[] = {320,350,370,320,400,420,390,360,370,340,
        380,340,390,350,360,400,330,390,400,360,
        340,350,390,360,350,350,360,350,360,390,
        410,360,440,340,390,370,380,370,350,400,
        380,370,330,340,400,330,350,370,380,370,
        340,350,390,350,350,320,330,350,380,410,
        360,380,330,350,360,390,360,390,360,360,
        350,370,360,390,340,380,300,370,340,400,
        320,300,400,380,370,400,360,370,330,340,
        370,420,370,340,420,370,360,340,370,360};
 
        pair<double,double> intervals[] = {{-M,325},{325,335},{335,345},{345,355},{355,365},{365,375},{375,385},{385,395},{395,405},{405,M}};
 
        double mean = 0, var = 0;
 
        for(int i=0; i<100; i++) mean+=data[i];
 
        mean/=100;
 
        for(int i=0; i<100; i++) var+=pow(data[i]-mean,2);
 
        var /= 99;
 
        var = sqrt(var);
 
        double chi_square = 0;
 
        for(int i=0; i<10; i++){
                int bj = observe(data,intervals[i]);
                intervals[i].first = (intervals[i].first - mean)/var;
                intervals[i].second = (intervals[i].second - mean)/var;
 
                double phi1 = integral(intervals[i].first);
                double phi2 = integral(intervals[i].second);
 
                double ej = (phi2 - phi1)*100;
 
                cout << ej << " " << bj << endl;
 
                chi_square += (pow(bj-ej,2)/ej);
        }
 
        cout<<chi_square << endl;
        cout<<','-'0'<<endl;
 
        return 0;
}