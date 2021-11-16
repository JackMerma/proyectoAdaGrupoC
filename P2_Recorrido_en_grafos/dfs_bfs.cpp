/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 16/11/2021
* @filename    : dfs_bfs
* @description : _
*/
#include <bits/stdc++.h>
#include "Image.cpp"
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define PI 3.1415926535897932384626

int RANGE=50;//	+/- RANGE
vector<int> color_group_dfs;
vector<int> color_group_bfs;
int pos_dfs[100000000]={0};//largo
int pos_bfs[100000000]={0};//largo

//Prototipos
bool dentro_rango(int, int);
bool fuera_rango(int, int);
void dfs(Image, int, int);
void bfs(Image, int, int);
void make_bfs(Image,int);
void make_dfs(Image, int);
void informacion_dfs();
void informacion_bfs();


bool dentro_rango(int base, int color){
	return color>=base-RANGE && color<=base+RANGE;
}
bool fuera_rango(int base, int color){
	return color<base-RANGE || color>base+RANGE;
}


void make_dfs(Image img){
	for(int i=0;i<img.height*img.width;i++){
		int color=(int)img.image[i];
		if(pos_dfs[i]==0){
			color_group_dfs.push_back(color);//coloca al color principal
			dfs(img, i, color);//hace dfs
		}
	}
}
void dfs(Image img,int pos, int color){
	int width=img.width;
	int height=img.height;

	if(fuera_rango(color, (int)img.image[pos]))//fuera de rango del color actual
		return;

	if(pos_dfs[pos]==1) return;
	//se agrega
	pos_dfs[pos]=1;
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



void make_bfs(Image img){
	for(int i=0;i<img.height*img.width;i++){
		int color=(int)img.image[i];
		if(pos_bfs[i]==0){
			pos_bfs[i]=1;
			color_group_bfs.push_back(color);
			bfs(img, i, color);
		}
	}
}
void bfs(Image img, int pos, int color){
	int width=img.width;
	int height=img.height;
	
	bool son[4]={
		pos-width>=0 && pos_bfs[pos-width]==0 				&& dentro_rango(color, (int)img.image[pos-width]), //arriba
		pos+width<width*height && pos_bfs[pos+width]==0	&& dentro_rango(color, (int)img.image[pos+width]),//abajo
		(pos+1)%width!=0 && pos_bfs[pos+1]==0 				&& dentro_rango(color, (int)img.image[pos+1]),//derecha
		pos%width!=0 && pos_bfs[pos-1]==0					&& dentro_rango(color, (int)img.image[pos-1]) //izquierda
	};

	//verificando y agregando
	if(son[0])//arriba
		pos_bfs[pos-width]=1;
	if(son[1])//abajo
		pos_bfs[pos+width]=1;
	if(son[2])//derecha
		pos_bfs[pos+1]=1;
	if(son[3])//izquierda
		pos_bfs[pos-1]=1;


	//verificando y recorriendo
	if(son[0])//arriba
		bfs(img, pos-width, color);
	if(son[1])//abajo
		bfs(img, pos+width, color);
	if(son[2])//derecha
		bfs(img, pos+1, color);
	if(son[3])//izquierda
		bfs(img, pos-1, color);
}

void informacion_dfs(){
	cout<<"Grupos formados por DFS ("<<color_group_dfs.size()<<"):"<<endl;
	for(int i=0;i<color_group_dfs.size();i++)
		cout<<color_group_dfs[i]<<" ";
	cout<<endl;
}
void informacion_bfs(){
	cout<<"Grupos formados por BFS ("<<color_group_bfs.size()<<"):"<<endl;
	for(int i=0;i<color_group_bfs.size();i++)
		cout<<color_group_bfs[i]<<" ";
	cout<<endl;
}
