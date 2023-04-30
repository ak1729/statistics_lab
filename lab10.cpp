#include <bits/stdc++.h>
using namespace std;

double ranNum(){
	double rn=0+((double)rand()/RAND_MAX)*(0.999);
	cout<<setprecision(6);
	return rn;
}


int main() {
	int n;
	double ld, k;
	cout<<"Enter n: "; cin>>n;
	cout<<endl;
	cout<<"Enter lambda: "; cin>>ld;
	cout<<endl;
	cout<<"Enter k: "; cin>>k;
	cout<<endl;

	
	double smean=0, svar=0, sskew=0, skurt=0;
	int sam; cout<<"Enter sam: "<<endl; cin>>sam; cout<<endl;
	for(int j=0; j<sam; j++){
		vector<double> random;
		double mean=0.0, var=0.0, skew=0.0, kurt=0.0;
		for(int i=0; i<n; i++){
			double ran=ranNum();
			double num=ld*pow((-log(1-ran)), (1/k));
			random.push_back(num);
			mean+=num;
		}

		mean/=n;
		
		for(int i=0; i<n; i++){
			double num = random[i];
			var += (num-mean)*(num-mean);
			kurt += (num-mean)*(num-mean)*(num-mean)*(num-mean);
			skew += (num-mean)*(num-mean)*(num-mean);
		}
		var = var/(n-1);
		kurt = kurt/(var*var*n);
		skew = skew/(n*pow(var, (3/2)));

		smean+=mean; svar+=var; sskew+=skew; skurt+=kurt;
	}
	smean/=sam; svar/=sam; sskew/=sam; skurt/=sam;

	cout<<setprecision(6);

	cout<<"Estimated Value of mean: "<<smean<<endl;
	cout<<"Estimated Value of variance: "<<svar<<endl;
	cout<<"Estimated Value of skewness: "<<sskew<<endl;
	cout<<"Estimated Value of kurtosis: "<<skurt<<endl;
	cout<<endl;

	double me = (ld*tgamma(1.0+(1.0/k)));
	double vari = (ld*ld*((tgamma(1.0+(2.0/k)))-pow((tgamma(1.0+(1.0/k))), 2)));
	double sk = ((tgamma(1.0+(3.0/k))*pow(ld, 3))-(3*me*vari)-(pow(me, 3)))/(pow(vari, 3/2));
	double ku = ((pow(ld, 4)*(tgamma(1.0+(4.0/k))))-(4*sk*pow(vari, 3/2)*me)-(6*pow(me, 2)*vari)-(pow(me, 4)))/(vari*vari);

	cout<<setprecision(6);

	cout<<"Value of mean: "<<me<<endl;
	cout<<"Value of variance: "<<vari<<endl;
	cout<<"Value of skewness: "<<sk<<endl;
	cout<<"Value of kurtosis: "<<ku<<endl;

	

	return 0;
}