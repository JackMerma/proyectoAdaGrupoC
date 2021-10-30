/** 
 * @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
 * @created     : 30/10/2021
 * @filename    : insertionSort
 * @description : algoritmo de ordenamiento, mediante insercion 
 */
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

template <class X>
void sort_by_insertion_method(X arr[], int len){
	for(int k=1;k<len;k++){
		X key=arr[k];
		int j=k-1;

		while(j>=0&&arr[j]>key){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int arr1[]={5,1,4,2};
	string arr2[]={"hola","...","..","alma"};

	sort_by_insertion_method(arr1,4);
	sort_by_insertion_method(arr2,4);


	for(int i=0;i<4;i++)
		cout<<arr1[i]<<" ";
	cout<<endl;
	for(int i=0;i<4;i++)
		cout<<arr2[i]<<" ";
	cout<<endl;

	return 0;
}

