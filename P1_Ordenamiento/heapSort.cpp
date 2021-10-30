/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 30/10/2021
* @filename    : heapSort
* @description : Ordenamiento Heap
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

void swap(int arr[], int a, int b){
	int aux=arr[a];
	arr[a]=arr[b];
	arr[b]=aux;
}
void heapify(int arr[], int idx, int max){
	int lar=idx,left=2*idx+1,right=2*idx+2;

	if(left<max&&arr[left]>arr[idx])
		lar=left;
	if(right<max&&arr[right]>arr[lar])
		lar=right;
	if(lar!=idx){
		swap(arr,idx,lar);
		heapify(arr,lar,max);
	}
}
void buildHeap(int arr[], int len){
	for(int i=len/2-1;i>=0;i--)
		heapify(arr, i, len);
}

void sort(int arr[], int len){
	buildHeap(arr,len);
	for(int i=len-1;i>0;i--){
		swap(arr,0,i);
		heapify(arr,0,i);
		for(int u=0;u<len;++u)
			cout<<arr[u]<<" ";
		//cout<<endl;
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];

	sort(arr,n);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";

	return 0;
}
