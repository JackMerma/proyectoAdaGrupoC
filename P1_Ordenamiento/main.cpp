/** 
 * @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
 * @created     : 30/10/2021
 * @filename    : main
 * @description : Archivo main para probar los ordenamientos (heapsort, quicksort,  insertionsort)
 */
#include <bits/stdc++.h>
#include "heapSort.cpp"
#include "insertionSort.cpp"
#include "quickSort.cpp"
using namespace std;

#define ll long long
#define endl "\n"


//template para convertir un dato generico a string
template<typename T>
string toString(T t){
	stringstream s;
	s<<t;
	return s.str();
}


template <class X>
float procesar_algoritmo(X arr[], int opt, int len){

	clock_t t;

	t=clock();//INICIO

	if(opt==1){
		sort_by_quick_method(arr,len);
	}else if(opt==2){
		sort_by_heap_method(arr,len);
	}else{
		sort_by_insertion_method(arr,len);
	}

	t=clock()-t;//FIN

	return ((float)t)/CLOCKS_PER_SEC;
}

template <class X>
void procesar(X arr,int len){
	//algoritmo a usar
	int opt;
	printf("Algoritmo de ordenamiento a usar:\n1. Quick Sort\n2. Heap Sort\n3. Insertion Sort\nOpcion:");
	scanf("%i",&opt);

	//manejo del tiempo de ejecusion
	if(opt<1||opt>3){
		opt=1;//quicksort por defecto
		printf("Quick Sort por defecto\n");
	}

	float time=procesar_algoritmo(arr,opt,len);


	//mostrando datos ordenados y tiempo de ejecucion
	printf("Datos: ");
	for(int i=0;i<len;i++){
		if(typeid(arr[0])==typeid(string)){//imprimir cadenas
			char buffer[100];
			char* data = strcpy(buffer,toString(arr[i]).c_str());//convertir el string a char
			printf("%s ",data);
		}else{//imprimir numeros
			printf("%i ",arr[i]);
		}
	}
	printf("\nTiempo tomado: %f segundos.\n",time);
}

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
void opcion_2(){
	int n;
	//los datos se generan aleatoriamente
	printf("Advertencia: Los datos se generaran aleatoriamente (datos numericos)\n");
	printf("Cantidad de datos:");
	scanf("%i",&n);
	n=abs(n);//si se ingresa un negativo

	ll arr[n]={0};

	ll a=1,b=0;
	printf("Rangos(separada por espacios):");
	scanf("%i %i", &a,&b);

	//para datos invalidos
	ll minX=min(a,b),maxX=max(a,b);
	a=minX;
	b=maxX;

	//generacion de 'n' datos aleatorios en el rango [a-b]
	for(int i=0;i<n;i++)
		arr[i]=rand()%(b-a+1)+a;

	procesar(arr,n);

}

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

