/** 
 * @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
 * @created     : 30/10/2021
 * @filename    : quickSort
 * @description : Ordenamiento Quicksort con el uso de insertion sort
 */
#include <bits/stdc++.h>
#include "insertionSort.cpp"
using namespace std;

#define ll long long
#define endl "\n"
const int THRESHOLD = 11; //se define el umbral

/**
 * Metodo sort_quick: Aplica recursivamente el metodo quicksort
 * Atributos:
 * 	arr    -> arreglo principal
 * 	limIzq -> limite a la izquierda para aplicar el metodo
 * 	limDer -> limite a la derecha para aplicar el metodo
 */
template <class X>
void sort_quick(X arr[], int limIzq, int limDer){

	while(limIzq<limDer){

		if(limDer-limIzq+1<THRESHOLD){//cantidad de datos menores a 10 -> insertion sort
			sort_by_insertion_method(arr,limIzq,limDer);
			break;


		}else{//quick sort
			//algoritmo de quicksort
			X pivot=arr[limDer];
			int a=limIzq,b=limIzq;//b almacenará la posicion correcta del pivot

			for(;a<limDer;a++){
				if(arr[a]<pivot){
					swap(arr[a],arr[b]);
					b++;
				}
			}

			swap(arr[b],arr[limDer]);

			//Recursividad rapida
			if(b-limIzq<limDer-b){//sort por la izquierda
				sort_quick(arr,limIzq,b-1);
				limIzq=b+1;
			}else{
				sort_quick(arr,b+1,limDer);//sort por la derecha
				limDer=b-1;
			}
		}
	}
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
