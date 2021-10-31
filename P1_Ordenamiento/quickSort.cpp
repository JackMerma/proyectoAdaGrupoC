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

/**
 * Metodo swap: intercambia dos datos del arreglo
 * Atributos:
 * 	arr  -> arreglo principal
 * 	posA -> primera posicion a intercambiar
 * 	posB -> segunda posicion a intercambiar
 */
template <class X>
void swap(X arr[], int posA, int posB){
	X aux=arr[posA];
	arr[posA]=arr[posB];
	arr[posB]=aux;
}

/**
 * Metodo sort_quick: Aplica recursivamente el metodo quicksort
 * Atributos:
 * 	arr    -> arreglo principal
 * 	limIzq -> limite a la izquierda para aplicar el metodo
 * 	limDer -> limite a la derecha para aplicar el metodo
 */
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

/**
 * Metodo sort_by_quick_method: metodo principal de ordenamiento quick
 * Atributos:
 * 	arr -> arreglo a modificar
 * 	len -> longitud del arreglo
 */
template <class X>
void sort_by_quick_method(X arr[], int len){
	sort_quick(arr,0,len-1);
} 
