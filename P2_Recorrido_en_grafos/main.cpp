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
vector<int> color_group;
int posiciones_recorridas[100000000]={0};//largo

void dfs(Image img,int pos, int color){

	unsigned char *data=img.image;
	int width=img.width;
	int height=img.height;

	int color_actual=(int)data[pos];
	if(color_actual<color-RANGE || color_actual>color+RANGE)//fuera de rango de pintado
		return;

	if(posiciones_recorridas[pos]==1) return;
	//se agrega
	posiciones_recorridas[pos]=1;
	//cout<<(int)img[pos]<<" ";
	//img[pos]=(unsigned char)color;//no es necesario para la primera pasada

	if(pos-width>=0)//arriba
		dfs(img,pos-width,color);
	if(pos+width<width*height)//abajo
		dfs(img,pos+width,color);
	if((pos+1)%width!=0)//derecha
		dfs(img,pos+1,color);
	if(pos%width!=0)//izquierda
		dfs(img,pos-1,color);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Image myImage;
	myImage.read("other.jpg");

	//recorrido DFS
	for(int i=0;i<myImage.height*myImage.width;i++){
		int color=(int)myImage.image[i];
		if(posiciones_recorridas[i]==0){
			color_group.push_back(color);//coloca al color principal
			dfs(myImage, i, color);//hace dfs
		}
	}

	cout<<"grupos formados:"<<color_group.size()<<endl;
	for(int i=0;i<color_group.size();i++)
		cout<<color_group[i]<<" ";
	cout<<endl;
	cout<<"informacion ... "<<endl;
	cout<<to_string(myImage)<<endl;
	//recorrido BFS


	//convertir nueva imagen



	cout<<endl;
	return 0;
}
