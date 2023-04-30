/* 2. Write a program to Generate n the random numbers and find the frequency of all 
data points, mean, variance, standard deviation*/

#include<bits/stdc++.h>
using namespace std;

vector<double> numGen(double a, double b, int n){
	vector<double> num;
	for(int i=0; i<n; i++){
		double rn=a+((double)rand()/RAND_MAX)*(b-a-1);
		cout<<setprecision(3);
		// cout<<rn<<endl;
		num.push_back(rn);
	}
	return num;
}

int main(){

	double a, b;
	int n, m;
	cout<<"Enter lower limit: "<<endl; cin>>a;
	cout<<"Enter upper limit: "<<endl; cin>>b;
	cout<<"Enter no. of points: "<<endl; cin>>n;
	cout<<"Enter m: "<<endl; cin>>m;

	
	// for(auto &it: num) cout<<it<<" ";
	// cout<<endl;
	unordered_map<double, int> mp;
	vector<double> mean, variance, std_dev;
	for(int i=0; i<m; i++){
		vector<double> res=numGen(a, b, n);
		for(auto &i: res) mp[i]++;
		double sum1=0, sum2=0;
		for(auto &it: res) sum1+=it;
		mean.push_back((double)sum1/n);
		int cnt=0;
		for(auto &it: res){
			sum2+=(mean[cnt]-it)*(mean[cnt]-it);
		}
		cnt++;
		sum2/=n;
		variance.push_back(sum2); 
		std_dev.push_back(sqrt(sum2));
	}
	for(auto &it: mp) cout<<it.first<<" -> "<<it.second<<endl;
	cout<<endl;
	double me=0, v=0, s=0;
	for(auto &it: mean) me+=it;
	cout<<"Mean is: "<<me/m<<endl;
	for(auto &it: variance) v+=it;
	cout<<"variance is: "<<v/m<<endl;
	for(auto &it: std_dev) s+=it;
	cout<<"Standard Deviation is: "<<s/m<<endl;


	return 0;
}