/** 
 * @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
 * @created     : 07/11/2021
 * @filename    : Image
 * @description : Clase imagen que lee, escribe y convierte a escala de grises una imagen
 */
#include <bits/stdc++.h>
#include "Image.cpp"
using namespace std;

#define ll long long
#define endl "\n"

int RANGE=20;//+-10
int conteo=0;
vector<int> color_group;
vector<int> posiciones_recorridas;

void dfs(unsigned char img[], int pos, int n, int color){
	int color_actual=(int)img[pos];
	if(color_actual<color-RANGE || color_actual>color+RANGE)//fuera de rango de pintado
		return;

	for(int i=0;i<posiciones_recorridas.size();i++)
		if(pos==posiciones_recorridas[i]) return;
	//se agrega
	posiciones_recorridas.push_back(pos);
	cout<<pos<<endl;
	conteo++;
	//cout<<(int)img[pos]<<" ";
	//img[pos]=(unsigned char)color;//no es necesario para la primera pasada

	if(pos-n>=0)//arriba
		dfs(img,pos-n,n,color);
	if(pos+n<n*n)//abajo
		dfs(img,pos+n,n,color);
	if((pos+1)%n!=0)//derecha
		dfs(img,pos+1,n,color);
	if(pos%n!=0)//izquierda
		dfs(img,pos-1,n,color);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Image myImage;
	cout<<"informacion ... "<<endl;
	myImage.read("other.jpg");

	cout<<to_string(myImage)<<endl;

	//recorrido DFS
	for(int i=0;i<myImage.height*myImage.width;i++){
		bool en_rango=false;
		int color=(int)myImage.image[i];
		//consulta si ya esta dentro del rango de uno de los colores principales
		for(int u=0;u<color_group.size();u++){
			if(color>=color_group[u]-RANGE && color<= color_group[u]+RANGE){
				en_rango=true;
			}
		}
		//si no estuvo en rango de ninguno
		if(en_rango==false){
			color_group.push_back(color);//coloca al color principal
			dfs(myImage.image, i,myImage.width, color);//hace dfs
			posiciones_recorridas.clear();
		}
	}

	cout<<"grupos formados:"<<color_group.size()<<endl;
	for(int i=0;i<color_group.size();i++)
		cout<<color_group[i]<<" ";
	cout<<endl<<"count:"<<conteo<<endl;
	//recorrido BFS


	//convertir nueva imagen



	cout<<endl;
	return 0;
}
