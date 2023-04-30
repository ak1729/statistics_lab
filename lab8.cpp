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


double digamma(double x){
	double epsilon = 1e-8;
    if (x == 0) return INFINITY;
    else if (x < 0) return NAN;
    else if (x == 1) return -tgamma(1);
    else if (x < epsilon) return 1/x - tgamma(1);
    double result = 0;
    while (x < 10)
    {
        result -= 1/x;
        x += 1;
    }
    double t = 1/(x*x);
    result += log(x) - 0.5/x - t*(1.0/12 - t*(1.0/120 - t*(1.0/252)));
    return result;
}

double func(double x, int n, double sum, double logSum){
	return ((-n*digamma(x))-(n*log(sum/(n*x)))+logSum);
}


int main(){

	double alpha, beta;
	int n;
	cout<<"Enter the value of alpha: "<<endl; cin>>alpha;
	cout<<"Enter the value of beta: "<<endl; cin>>beta;
	cout<<"Enter the value of n: "<<endl; cin>>n;
	cout<<endl;

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
	cout<<endl;

	// Maximum Likelihood Estimator

	sum=0.0;
	double logSum=0.0;
	for(auto &it: res){
		sum+=it;
		logSum+=log(it);
	}

	
	// Secant method

	double a=1e-6, b=1e-5;
	double c=(a*func(b, n, sum, logSum)-b*func(a, n, sum, logSum))/(func(b, n, sum, logSum)-func(a, n, sum, logSum));
	// cout<<c<<endl;
	while(c>1e-6){
		a=b;
    	b=c;
    	c=(a*func(b, n, sum, logSum)-b*func(a, n, sum, logSum))/(func(b, n, sum, logSum)-func(a, n, sum, logSum));
	}


	cout<<"Given value of alpha: "<<alpha<<endl;
	cout<<"Estimated value of alpha: "<<a<<endl;
	cout<<endl;
	cout<<"Given value of beta: "<<beta<<endl;
	cout<<"Estimated value of beta: "<<sum/(n*a)<<endl;
	
	// cout<<digamma(1e5)<<endl;

	return 0;
}