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

/**
 * Metodo swap_heap: Cambia dos valores de un arreglo
 * Atributos:
 * 	arr -> arreglo de tipo generico
 * 	a   -> posicion del primer elemento
 * 	b   -> posicion del segundo elemento
 */
template <class X>
void swap_heap(X arr[], int a, int b){
	X aux=arr[a];
	arr[a]=arr[b];
	arr[b]=aux;
}

/**
 * Metodo heapify: Construye un heap recursivamente
 * Atributos:
 * 	arr -> arreglo principal
 * 	idx -> posicion del elemento que se cree el mas grande en 'arr'
 * 	max -> limite de recorrido en el arreglo
 */
template <class X>
void heapify(X arr[], int idx, int max){
	int lar=idx,
			left=2*idx+1,
			right=2*idx+2;

	if(left<max&&arr[left]>arr[idx])
		lar=left;
	if(right<max&&arr[right]>arr[lar])
		lar=right;
	if(lar!=idx){
		swap_heap(arr,idx,lar);
		heapify(arr,lar,max);
	}
}

/**
 * Metodo buildHeap: construye un heap llamando a heapify
 * Atributos:
 *  arr -> arreglo que se modificará
 *  len -> longitud del arreglo
 */
template <class X>
void buildHeap(X arr[], int len){
	for(int i=len/2-1;i>=0;i--)
		heapify(arr, i, len);
}

/**
 * Metodo sort_by_heap_method: ordena mediante la metodologia heap
 * Atributos:
 * 	arr -> arreglo que se modificara
 * 	len -> longitud del arreglo
 */
template <class X>
void sort_by_heap_method(X arr[], int len){
	buildHeap(arr,len);
	for(int i=len-1;i>0;i--){
		swap_heap(arr,0,i);
		heapify(arr,0,i);
	}
}
