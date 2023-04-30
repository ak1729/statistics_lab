#include<bits/stdc++.h>
using namespace std;

float mean(vector<int>& arr){
	float sum=accumulate(arr.begin(), arr.end(), 0.0);
	return (sum/(arr.size())); 
}

int min_ele(vector<int>& arr){
	int mini=INT_MAX;
	for(auto &it: arr) mini = min(mini, it);
	return mini;
}

int max_ele(vector<int>& arr){
	int maxi=INT_MIN;
	for(auto &it: arr) maxi = max(maxi, it);
	return maxi;
}

float median(vector<int>& arr){
	int n=arr.size();
    sort(arr.begin(), arr.end());
    if(n % 2 == 0)
        return (float)(arr[n/2 - 1] + arr[n/2])/2;

    return (float)arr[n/2];
}

float mode(vector<int>& arr){
	int n=arr.size();
    sort(arr.begin(), arr.end()); 
    int max_count = 1, res = arr[0], count = 1; 

    for (int i = 1; i < n; i++) { 
        if (arr[i] == arr[i - 1]) 
            count++; 
        else { 
            if (count > max_count) { 
                max_count = count; 
                res = arr[i - 1]; 
            } 
            count = 1; 
        } 
    }
    if (count > max_count) 
    { 
        max_count = count; 
        res = arr[n - 1]; 
    } 
    
    return (float)res;
}

float variance(vector<int>& arr){
	float sum=0.0;
	float m=mean(arr);
	for(int i=0; i<arr.size(); i++){
		sum+=pow(abs(arr[i]-m), 2);
	}
	return sum/(arr.size());
}

float skewness(vector<int>& arr)
{  
    // Find skewness using above formula
    int n=arr.size();
    float me=mean(arr);
    float std=sqrt(variance(arr));
    float sum = 0;
    for (int i = 0; i < n; i++)
        sum += (arr[i] - me)*(arr[i] - me)*(arr[i] - me);             
    return sum / (n*std*std*std);
}

float kurtosis(vector<int>& arr){
	int n=arr.size();
	float me=mean(arr);
	float var=variance(arr);
	float sum=0;
	for(int i=0; i<n; i++){
		sum+=(arr[i]-me)*(arr[i]-me)*(arr[i]-me)*(arr[i]-me);
	}
	return sum/((n)*var*var);
}

int main(){
	vector<int> tab1{9, 4, 2, 2, 8, 4, 8, 2, 2, 19, 2, 17, 4, 8, 5, 10};
	vector<int> tab2{25, 11, 19, 17, 12, 31, 16, 11, 12, 11, 15, 20, 18, 14, 21, 29};
	vector<int> tab3{101, 86, 64, 99, 99, 114, 107, 118, 79, 121, 90, 146, 63, 108, 85, 110};

	vector<string> data{"Min", "Max", "Mean", "Median", "Mode", "Variance", "Skewness", "Kurtosis"};

	vector<float> tab1_data(8), tab2_data(8), tab3_data(8);

	tab1_data[0]=min_ele(tab1);
	tab1_data[1]=max_ele(tab1);
	tab1_data[2]=mean(tab1);
	tab1_data[3]=median(tab1);
	tab1_data[4]=mode(tab1);
	tab1_data[5]=variance(tab1);
	tab1_data[6]=skewness(tab1);
	tab1_data[7]=kurtosis(tab1);

	tab2_data[0]=min_ele(tab2);
	tab2_data[1]=max_ele(tab2);
	tab2_data[2]=mean(tab2);
	tab2_data[3]=median(tab2);
	tab2_data[4]=mode(tab2);
	tab2_data[5]=variance(tab2);
	tab2_data[6]=skewness(tab2);
	tab2_data[7]=kurtosis(tab2);

	tab3_data[0]=min_ele(tab3);
	tab3_data[1]=max_ele(tab3);
	tab3_data[2]=mean(tab3);
	tab3_data[3]=median(tab3);
	tab3_data[4]=mode(tab3);
	tab3_data[5]=variance(tab3);
	tab3_data[6]=skewness(tab3);
	tab3_data[7]=kurtosis(tab3);

	// for(int i=0; i<data.size(); i++){
	// 	cout<<data[i]<<" ";
	// }
	// cout<<endl;
	// for(int i=0; i<tab1_data.size(); i++){
	// 	cout<<tab1_data[i]<<"  ";
	// }
	// cout<<endl;
	// for(int i=0; i<tab2_data.size(); i++){
	// 	cout<<tab2_data[i]<<"  ";
	// }
	// cout<<endl;
	// for(int i=0; i<tab3_data.size(); i++){
	// 	cout<<tab3_data[i]<<"  ";
	// }
	// cout<<endl;


	unordered_map<int, int> tab1_freq, tab2_freq, tab3_freq;

	for(int i=0; i<tab1.size(); i++){
		tab1_freq[tab1[i]]++;
	}
	for(int i=0; i<tab2.size(); i++){
		tab2_freq[tab2[i]]++;
	}
	for(int i=0; i<tab3.size(); i++){
		tab3_freq[tab3[i]]++;
	}
	cout<<setw(19)<<"SO2"<<setw(10)<<"NO2"<<setw(10)<<"PM10"<<endl;
	for(int i=0; i<8; i++){
		cout<<data[i]<<setw(15)<<tab1_data[i]<<setw(10)<<tab2_data[i]<<setw(10)<<tab3_data[i]<<endl;
	}

	cout<<endl<<endl;
	cout<<"SO2 frequency"<<endl;
	for(auto &it: tab1_freq){
		cout<<it.first<<"->"<<it.second<<endl;
	}
	cout<<endl<<endl;
	cout<<"NO2 frequency"<<endl;
	for(auto &it: tab2_freq){
		cout<<it.first<<"->"<<it.second<<endl;
	}
	cout<<endl<<endl;
	cout<<"PM10 frequency"<<endl;
	for(auto &it: tab3_freq){
		cout<<it.first<<"->"<<it.second<<endl;
	}

	cout<<endl<<endl;
	cout<<"Skewness of SO2 is: "<<endl;
    if(tab1_data[6] >0){
        cout<<"positively skewed"<<endl;
    }
    else{
        cout<<"negatively skewed"<<endl;
    }

    cout<<endl<<endl;
	cout<<"Skewness of NO2 is: "<<endl;
    if(tab2_data[6] >0){
        cout<<"positively skewed"<<endl;
    }
    else{
        cout<<"negatively skewed"<<endl;
    }

    cout<<endl<<endl;
	cout<<"Skewness of PM10 is: "<<endl;
    if(tab3_data[6] >0){
        cout<<"positively skewed"<<endl;
    }
    else{
        cout<<"negatively skewed"<<endl;
    }

	cout<<endl<<endl;
	cout<<"Kurtosis of SO2 is: "<<endl;
     if(tab1_data[7] >3){
        cout<<"Leptokurtic sample"<<endl;
    }
    else{
        cout<<"Platykurtic sample"<<endl;
    }

    cout<<endl<<endl;
	cout<<"Kurtosis of NO2 is: "<<endl;
     if(tab2_data[7] >3){
        cout<<"Leptokurtic sample"<<endl;
    }
    else{
        cout<<"Platykurtic sample"<<endl;
    }

    cout<<endl<<endl;
	cout<<"Kurtosis of PM10 is: "<<endl;
     if(tab3_data[7] >3){
        cout<<"Leptokurtic sample"<<endl;
    }
    else{
        cout<<"Platykurtic sample"<<endl;
    }


	return 0;
}