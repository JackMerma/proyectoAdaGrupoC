/** 
 * @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
 * @created     : 30/10/2021
 * @filename    : main
 * @description : Archivo main para probar los ordenamientos (heapsort, quicksort,  insertionsort)
 */
#include <bits/stdc++.h>
#include "heapSort.cpp"
#include "quickSort.cpp"//implementa el metodo por insercion
using namespace std;

#define ll long long
#define endl "\n"

//	Prototipos
template <typename T> string toString(T);
template <class X> float procesar_algoritmo(X*,int,int);
template <class X> void procesar(X*,int);
void opcion_1();
void opcion_2();

//	Metodo principal
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int opt=-1;

	while(opt!=3){
		printf("******** Menu ********\n1. Ingresar datos\n2. Generar datos\n3. Salir\n");
		printf("Opcion:");scanf("%i",&opt);
		if(opt==1){
			opcion_1();
		}else if(opt==2){
			opcion_2();
		}else if(opt==3){
			printf("Finalizando...\n");
		}else{
			printf("Intente de nuevo\n");
		}
	}
	return 0;
}


/**
 * Metodos ...
 */

/**
 * Metodo toString: Convierte un dato de tipo generico a string
 * Atributos:
 * 	t -> dato de tipo generico
 */
template<typename T>
string toString(T t){
	stringstream s;
	s<<t;
	return s.str();
}

/**
 * Metodo procesr_algoritmo: Procesa uno de los 3 algoritmos de ordenamiento y captura el tiempo
 * Atributos: 
 * 	arr -> arreglo principal (datos genericos)
 * 	opt -> opcion de algoritmo
 * 	len -> longitud del arreglo
 */
template <class X>
float procesar_algoritmo(X arr[], int opt, int len){

	clock_t t;

	t=clock();//INICIO

	if(opt==1){
		sort_by_quick_method(arr,len);
	}else if(opt==2){
		sort_by_heap_method(arr,len);
	}else{
		sort_by_insertion_method(arr,0,len-1);
	}

	t=clock()-t;//FIN

	return ((float)t)/CLOCKS_PER_SEC;
}

/**
 * Metodo procesar: Muestra un menu de opciones y luego de llamar a procesar_algoritmo
 * 									muestra los datos ordenados y el tiempo tomado
 * Atributos:
 * 	arr -> arreglo principal
 * 	len -> longitud del arreglo
 */
template <class X>
void procesar(X arr[],int len){

	//2 copias del arreglo

	X arr2[len]; copy(arr,arr+len,arr2);
	X arr3[len]; copy(arr,arr+len,arr3);

	float time_quick_sort=procesar_algoritmo(arr,1,len);
	float time_heap_sort=procesar_algoritmo(arr2,2,len);
	float time_insertion_sort=procesar_algoritmo(arr3,3,len);


	//mostrando datos ordenados y tiempo de ejecucion
	printf("Datos: ");
	for(int i=0;i<len;i++){
		char buffer[100];
		char* data = strcpy(buffer,toString(arr[i]).c_str());//convertir el string a char
		printf("%s ",data);
	}
	printf("\n\nTiempo tomado");
	printf("\n(Quick Sort): %f segundos.",time_quick_sort);
	printf("\n(Heap Sort): %f segundos.",time_heap_sort);
	printf("\n(Insertion Sort): %f segundos.\n\n",time_insertion_sort);
}

/**
 * Metodo opcion_1: muestra el contenido de la opcion por ingreso de datos, luego llama a procesar
 */
void opcion_1(){
	int n;
	printf("Cantidad de datos:");
	scanf("%i",&n);

	int optTipo;
	printf("Tipo de datos:\n1. Letras\n2. Numeros\nOpcion:");
	scanf("%i",&optTipo);

	//manejo de malas entradas
	if(optTipo<1||optTipo>2){
		optTipo=1;
		printf("Default: letras\n");
	}

	if(optTipo==1){													//Letras
		string arr[n];
		printf("Ingrese los datos separados por espacios:");

		for(int i=0;i<n;i++)
			cin>>arr[i];

		procesar(arr,n);


	}else{																	//Numeros
		int arr[n];
		printf("Ingrese los datos separados por espacios:");

		for(int i=0;i<n;i++)
			cin>>arr[i];

		procesar(arr,n);
	}
}

/**
 * Metodo opcion_2: muestra el contenido de la opcion por generador de datos, luego llama a procesar
 */
void opcion_2(){
	int n;
	//los datos se generan aleatoriamente
	printf("Advertencia: Los datos se generaran aleatoriamente (datos numericos)\n");
	printf("Cantidad de datos:");
	scanf("%i",&n);
	n=abs(n);//si se ingresa un negativo

	int arr[n]={0};

	int a=1,b=0;
	printf("Rangos(separada por espacios):");
	scanf("%i %i", &a,&b);

	//para datos invalidos
	int minX=min(a,b),maxX=max(a,b);
	a=minX;
	b=maxX;

	printf("\nGenerando datos ...\n");
	//generacion de 'n' datos aleatorios en el rango [a-b]
	for(int i=0;i<n;i++)
		arr[i]=rand()%(b-a+1)+a;

	procesar(arr,n);

}
