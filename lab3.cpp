/* Write a program to generate n normal random number */
#include<bits/stdc++.h>
using namespace std;

# define pi 3.1415


int main(){
	double mean, var;
	int n;
	cout<<"Enter mean: "<<endl; cin>>mean;
	cout<<"Enter var: "<<endl; cin>>var;
	cout<<"Enter sample size: "<<endl; cin>>n;

  default_random_engine generator;

  uniform_real_distribution<double> distribution (0.0,1.0);

  vector<double> y;

  for (int i=0; i<n; ++i){
 	double u1=distribution(generator);
 	double u2=distribution(generator);
 	
 	double num=sqrt(-2.0*(double)log(u1))*sin(2.0*pi*u2);
 	double y1=(var*num)+mean;
 	y.push_back(y1);
  }

  double exp_mean=(1.0/n)*(accumulate(y.begin(), y.end(), 0.0));
  double exp_var;
  double sum=0.0;
  for(auto &it: y){
  	sum+=(it-exp_mean)*(it-exp_mean);
  }
  exp_var=sqrt(sum/n);

  cout<<"Mean is: "<<mean<<endl;  
  cout<<"Expected Mean is: "<<exp_mean<<endl;

  cout<<"variance is: "<<var<<endl;  
  cout<<"Expected variance is: "<<exp_var<<endl;


	return 0;
}