#include <iostream>
#include <vector>

using namespace std;
vector<int> Merge(vector<int> L, vector<int> R){
	vector<int> A;
	int Ls=L.size();
	int Rs=R.size();
	int As=Ls+Rs;
	int Li=0;
	int Ri=0;
	int Ai=0;
	while(Ai<As){
		if(Li<Ls && Ri<Rs){
		if(L[Li]<=R[Ri]){
			A.push_back(L[Li]);
			Li++;
		}
		else{
			A.push_back(R[Ri]);
			Ri++;
		}
	}
	else{
		if(Ri<Rs){
			A.push_back(R[Ri]);
			Ri++;
		}
		else if(Li<Ls){
			A.push_back(L[Li]);
			Li++;
		}
	}
		Ai++;
	}

	return A;
}
vector<int> MergeSort(vector<int>& V, int beg, int end){
	if(beg>end){
		vector<int> ansV;
		return ansV;
	}
	if(beg==end){
		vector<int> ansV;
		ansV.push_back(V[end]);
		return ansV;
	}
	int m=(beg+end)/2;
	vector<int> Ls=MergeSort(V, beg, m);
	vector<int> Rs=MergeSort(V, m+1, end);
	return Merge(Ls, Rs);
}

int main(){
    cout<<"Enter number of integers to sort: \n";
    int n;
    cin>>n;
	vector<int> V;
    cout<<"Enter the integers: \n";
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        V.push_back(x);
    }
	vector<int> sorted=MergeSort(V, 0, n-1);
    cout<<"Sorted integers are: \n";
	for(int i =0;i<sorted.size();i++)
		cout<<sorted[i]<<" ";
    cout<<endl;
}
