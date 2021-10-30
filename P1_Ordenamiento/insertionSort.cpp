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

/**
 * Metodo sort_by_insertion_method: ordena mediante la metodologia insertion
 * Atributos:
 * 	arr -> arreglo que se modificara
 * 	len -> longitud del arreglo
 */
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
