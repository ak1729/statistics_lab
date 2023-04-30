#include<bits/stdc++.h>
using namespace std;

double ranNum(){
	double rn=((double)rand()/RAND_MAX);
	cout<<setprecision(3);
	return rn;
}

double expNum(double alpha, double beta){
	while(true){
		double rn1 = ranNum(), rn2 = ranNum();
		if(alpha>0 && alpha<1){
			double e=2.718;
			double b=(e+alpha)/alpha;
			double p=rn1*b;

			if(p>1){
				double y = -log((b-p)/alpha);
				if(rn2<=pow(y, (alpha-1))){
					return y;
				}
			}
			else if(p<=1){
				double y = pow(p, (1/alpha));
				if(rn2<=exp(-y)){
					return y;
				}
			}
		}
		if(alpha>1){
			double a=1/(sqrt((2*alpha)-1));
			double b=alpha-log(4);
			double q=alpha+(1/a);
			double d=1+log(4.5);

			double v=a*log(rn1/(1-rn1));
			double y=alpha*exp(v);
			double z=rn1*rn1*rn2;
			double w=b+q*v-y;
			if(w+d-(4.5*z)>=0){
				return y;
			}
			else if(w>=log(z)){
				return y;
			}
		}
	}
}


int main(){

	double alpha, beta;
	int n;
	cout<<"Enter the value of alpha: "<<endl; cin>>alpha;
	cout<<"Enter the value of beta: "<<endl; cin>>beta;
	cout<<"Enter the value of n: "<<endl; cin>>n;

	double mini;
	double sum=0;
	vector<double> res; 
	
	for(int i=0; i<n; i++){
		double num=expNum(alpha, beta);
		num*=beta;
		res.push_back(num);
		sum+=num;
	}

	double mean=sum/n;
	double var=0, kurt=0, skew=0;

	for(int i=0; i<n; i++){
		double num=res[i];
		var += (num-mean)*(num-mean);
		kurt += (num-mean)*(num-mean)*(num-mean)*(num-mean);
		skew += (num-mean)*(num-mean)*(num-mean);
	}

	var = var/n;
	kurt = kurt/(var*var*n);
	skew = skew/(n*pow(var, (3/2)));

	cout<<"mean: "<<mean<<endl;
	cout<<"variance: "<<var<<endl;
	cout<<"kurtosis: "<<kurt<<endl;
	cout<<"skewness: "<<skew<<endl;

	return 0;
}