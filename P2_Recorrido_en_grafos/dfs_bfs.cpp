/** 
 * @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
 * @created     : 16/11/2021
 * @filename    : dfs_bfs
 * @description : Funciones para realizar BFS y DFS en una imagen
 */
#include <bits/stdc++.h>
#include "Image.cpp"
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define PI 3.1415926535897932384626

int RANGE;//rango de busqueda por dfs o bfs
int pos_dfs[(int)1e8]={0};//arreglo de almacenamiento para DFS
int pos_bfs[(int)1e8]={0};//arreglo de almacenamiento para BFS


//Prototipos
void make_bfs(Image,int);
void make_dfs(Image, int);
void dfs(Image, int, int);
void bfs(Image, int, int);
bool dentro_rango(int, int);


bool dentro_rango(int base, int color){
	/**
	 *  Metodo dentro_rango: Determina si un color esta dentro de rango del color base enviado
	 *  Atributos:
	 *  	base  -> Color base
	 *  	color -> Color enviado 
	 */
	return color>=base-RANGE && color<=base+RANGE;
}

void make_dfs(Image img, int range){
	/**
	 *  Metodo make_dfs: Metodo general para hacer el recorrido DFS por una imagen
	 *  Atributos:
	 *  	img   -> imagen enviada para hacer el recorrido
	 *  	range -> rango para hacer el recorrido [0-255]
	 */

	RANGE=range;

	//algoritmo
	for(int i=0;i<img.height*img.width;i++){//se recorre toda la imagen

		int color=(int)img.image[i];//color dominante

		if(pos_dfs[i]==0){//si no esta recorrido, se agrega y se toma como color dominante
			dfs(img, i, color);//se hace DFS desde la posicion i
		}
	}
}
void dfs(Image img,int pos, int color){
	/**
	 *  Metodo dfs: Metodo principal para hacer hacer recorrido DFS
	 *  Atributos:
	 *	 	img   -> imagen principal para hacer DFS
	 *	 	pos   -> posicion desde la que se hará DFS en el imagen
	 *	 	color -> color principal o dominante que pinta los pixeles a recorrer
	 */

	// + Se usa un stack, ya que encaja con la forma iterativa de recorrer por DFS
	// + El path recorre hasta cierto punto el recorrido.
	//	+ Para volver se toma al ultimo dato del PATH y se sigue buscando HIJOS en este
	stack<int>path;//stack principal

	int width=img.width;
	int height=img.height;

	path.push(pos);//Se coloca al primer dato enviado

	//siempre que no este vacio el PATH
	while(!path.empty()){
		if(pos_dfs[pos]!=1){//Pintado
			pos_dfs[pos]=1;
			img.image[pos]=(unsigned char)(color);
		}

		//posicion auxiliar
		int new_pos=pos;
		if(pos-width>=0 && pos_dfs[pos-width]!=1 						&& dentro_rango(color, (int)img.image[pos-width])){//arriba
			new_pos=pos-width;
		}else if(pos+width<width*height && pos_dfs[pos+width]!=1 && dentro_rango(color, (int)img.image[pos+width])){//abajo
			new_pos=pos+width;
		}else if((pos+1)%width!=0 && pos_dfs[pos+1]!=1 				&& dentro_rango(color, (int)img.image[pos+1])){//derecha
			new_pos=pos+1;
		}else if(pos%width!=0 && pos_dfs[pos-1]!=1 					&& dentro_rango(color, (int)img.image[pos-1])){//izquierda
			new_pos=pos-1;
		}

		//Si al menos se encontro a un hijo (posicion diferente), entonces se agrega
		if(new_pos!=pos){
			path.push(new_pos);
			pos=new_pos;
		}else{//si no existen posibles hijos
			path.pop();//se limina al ultimo dato
			if(!path.empty())
				pos=path.top();//se retrocede en el PATH
		}
	}
}

void make_bfs(Image img, int range){
	/**
	 *  Metodo make_bfs: Metodo general para hacer el recorrido BFS por una imagen
	 *  Atributos:
	 *  	img   -> imagen enviada para hacer el recorrido
	 *  	range -> rango para hacer el recorrido [0-255]
	 */

	RANGE=range;

	for(int i=0;i<img.height*img.width;i++){//se recorre todos los datos

		int color=(int)img.image[i];//color dominante o principal

		if(pos_bfs[i]==0){//si no se recorrió antes
			//se pinta al primer dato
			pos_bfs[i]=1;
			img.image[i]=(unsigned char)color;

			bfs(img, i, color);//Se hace BFS desde la posicion i
		}
	}
}

void bfs(Image img, int pos, int color){
	/**
	 *  Metodo bfs: Metodo principal para hacer recorrido BFS sobre la imagen
	 *  Atributos: 
	 *	 	img   -> imagen principal para hacer BFS
	 *	 	pos   -> posicion desde la que se hará BFS en el imagen
	 *	 	color -> color principal o dominante que pinta los pixeles a recorrer
	 */
	int width=img.width;
	int height=img.height;


	// + Se usa un queue, ya que encaja con la forma iterativa de recorrer por BFS
	// + El PATH agrega a todos los hijos del dato en el FRONT y se elimina este mismo
	queue<int> path;//estructura queue principal
	path.push(pos);//se agrega al primer dato

	while(!path.empty()){//mientras el PATH tenga datos

		//Se agrega a todos los hijos y se pintan
		if(pos-width>=0 && pos_bfs[pos-width]!=1 				&& dentro_rango(color, (int)img.image[pos-width])){//arriba
			pos_bfs[pos-width]=1;
			img.image[pos-width]=(unsigned char)color;
			path.push(pos-width);
		}
		if(pos+width<width*height && pos_bfs[pos+width]!=1	&& dentro_rango(color, (int)img.image[pos+width])){//abajo
			pos_bfs[pos+width]=1;
			img.image[pos+width]=(unsigned char)color;
			path.push(pos+width);
		}
		if((pos+1)%width!=0 && pos_bfs[pos+1]!=1 				&& dentro_rango(color, (int)img.image[pos+1])){//derecha
			pos_bfs[pos+1]=1;
			img.image[pos+1]=(unsigned char)color;
			path.push(pos+1);
		}
		if(pos%width!=0 && pos_bfs[pos-1]!=1					&& dentro_rango(color, (int)img.image[pos-1])){//izquierda
			pos_bfs[pos-1]=1;
			img.image[pos-1]=(unsigned char)color;
			path.push(pos-1);
		}

		//se elimina al primer dato (FRONT)
		path.pop();
		if(!path.empty())
			pos=path.front();//el PATH toma el valor del primero
	}
}
