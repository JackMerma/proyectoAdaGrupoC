/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 30/10/2021
* @filename    : main
* @description : Archivo main para probar los ordenamientos (heapsort, quicksort, insertion sort)
*/
#include <bits/stdc++.h>
#include "heapSort.cpp"
using namespace std;

#define ll long long
#define endl "\n"

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int arr1[] = {7,2,3,1,9,3,1,0};
	string arr2[]={"flipo","hola","jack","b","random","cpp","x","holo"};

	sort_by_heap_method(arr1,8);
	sort_by_heap_method(arr2,8);

	for(int i=0;i<8;i++)
		cout<<arr1[i]<<" ";
	cout<<endl;
	for(int i=0;i<8;i++)
		cout<<arr2[i]<<" ";
	cout<<endl;

	return 0;
}

