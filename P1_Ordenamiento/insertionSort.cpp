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
 * 	ini -> posicion donde empieza el ordenamiento
 * 	fin -> posicion donde termina el ordenamiento
 */
template <class x>
void sort_by_insertion_method(x arr[], int ini, int fin){
	for(int k=ini+1;k<fin+1;k++){
		x key=arr[k];
		int j=k-1;

		while(j>=0&&arr[j]>key){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}
