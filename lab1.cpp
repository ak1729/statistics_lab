#include<bits/stdc++.h>
using namespace std;

// Sort Function
void srt(vector<int>& arr, int n){
	for(int i=0; i<n; i++){
		int mini=arr[i];
		int ind=i;
		for(int j=i; j<n; j++){
			if(mini>arr[j]){
				mini=arr[j];
				ind=j;
			}
		}
		swap(arr[i], arr[ind]);
	}
}

int main(){
	int a, b, n;
	cout<<"Enter the lower limit: ";
	cin>>a;
	cout<<endl;
	cout<<"Enter the higher limit: ";
	cin>>b;
	cout<<endl;
	cout<<"Enter the number of points: ";
	cin>>n;
	cout<<endl;
	vector<int> arr;
	if(a==b) cout<<"Interval is same"<<endl;
	else{
		for(int i=0; i<n; i++){
			int num=a+(rand()%(b-a+1));
			arr.push_back(setprecision(num));
		}
		cout<<"The random number generated are: "<<endl;
		for(auto &it: arr) cout<<it<<" ";
		cout<<endl;
	}

	srt(arr, n);
	bool s;
	cout<<endl;
	cout<<"Enter 1 for ascending order and 0 for descending order: ";
	cin>>s;
	cout<<endl;

	if(s==1){
		cout<<"The sorted numbers in ascending order are: "<<endl;
		for(auto &it: arr) cout<<it<<" ";
		cout<<endl;
	}
	else{
		int i=0, j=n-1;
		while(i<=j){
			swap(arr[i], arr[j]);
			i++; j--;
		}
		cout<<"The sorted numbers in descending order are: "<<endl;
		for(auto &it: arr) cout<<it<<" ";
		cout<<endl;

	}

	return 0;
}