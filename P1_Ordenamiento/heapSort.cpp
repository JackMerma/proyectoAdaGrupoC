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

template <class X>
void swap(X arr[], int a, int b){
	X aux=arr[a];
	arr[a]=arr[b];
	arr[b]=aux;
}

template <class X>
void heapify(X arr[], int idx, int max){
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

template <class X>
void buildHeap(X arr[], int len){
	for(int i=len/2-1;i>=0;i--)
		heapify(arr, i, len);
}

template <class X>
void sort(X arr[], int len){
	buildHeap(arr,len);
	for(int i=len-1;i>0;i--){
		swap(arr,0,i);
		heapify(arr,0,i);
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int arr1[] = {7,2,3,1,9,3,1,0};
	string arr2[]={"flipo","hola","jack","b","random","cpp","x","holo"};

	sort(arr1,8);
	sort(arr2,8);

	for(int i=0;i<8;i++)
		cout<<arr1[i]<<" ";
	cout<<endl;
	for(int i=0;i<8;i++)
		cout<<arr2[i]<<" ";
	cout<<endl;

	return 0;
}
