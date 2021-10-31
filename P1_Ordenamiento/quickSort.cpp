/** 
 * @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
 * @created     : 30/10/2021
 * @filename    : quickSort
 * @description : Ordenamiento Quicksort
 */
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

template <class X>
void swap(X arr[], int posA, int posB){
	X aux=arr[posA];
	arr[posA]=arr[posB];
	arr[posB]=aux;
}

template <class X>
void sort_quick(X arr[], int limIzq, int limDer){
	X pivot=arr[limIzq];//inicializando el pivot --> primera posicion del sub-arreglo
	int a=limIzq,b=limDer;//limites de recorrido

	while(a<b){
		//buscando la posicion correcta para el pivot
		while(arr[a]<=pivot&&a<b) a++;
		while(arr[b]>pivot) b--;

		//intercambia datos en el proceso
		if(a<b) swap(arr,a,b);
	}

	//pivote en su posicion correcta
	arr[limIzq]=arr[b];
	arr[b]=pivot;

	//recursividad subdivisionanda

	if(limIzq<b-1)//si hay elementos por la izquierda
		sort_quick(arr,limIzq,b-1);

	if(b+1<limDer)//si hay elementos por la derecha
		sort_quick(arr,b+1,limDer);

}

template <class X>
void sort_by_quick_method(X arr[], int len){
	sort_quick(arr,0,len-1);
} 

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int arr1[]={5,1,7,2,9,2,1,4,5};
	string arr2[]={"hola","hol","a",".","aa","otro"};
	bool arr3[]={true,false,false,true};

	sort_by_quick_method(arr1,9);
	sort_by_quick_method(arr2,6);
	sort_by_quick_method(arr3,4);

	for(int i=0;i<9;i++)
		cout<<arr1[i]<<" ";
	cout<<endl;

	for(int i=0;i<6;i++)
		cout<<arr2[i]<<" ";
	cout<<endl;

	for(int i=0;i<4;i++)
		cout<<arr3[i]<<" ";
	cout<<endl;

	return 0;
}

