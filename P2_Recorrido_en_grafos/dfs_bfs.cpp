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

int RANGE;
int pos_dfs[100000000]={0};//largo
int pos_bfs[100000000]={0};//largo


//Prototipos
bool dentro_rango(int, int);
bool fuera_rango(int, int);
void dfs(Image, int, int, unsigned char*);
void bfs(Image, int, int);
void make_bfs(Image,int);
void make_dfs(Image, int);


bool dentro_rango(int base, int color){
	return color>=base-RANGE && color<=base+RANGE;
}
bool fuera_rango(int base, int color){
	return color<base-RANGE || color>base+RANGE;
}


void make_dfs(Image img, int range){

	RANGE=range;

	unsigned char output[img.height*img.width];

	for(int i=0;i<img.height*img.width;i++){
		int color=(int)img.image[i];
		if(pos_dfs[i]==0){
			dfs(img, i, color, output);//hace dfs
		}
	}

	//img.image=output;
}
void dfs(Image img,int pos, int color, unsigned char *output){
	stack<int>path;

	int width=img.width;
	int height=img.height;

	path.push(pos);

	while(!path.empty()){
		if(pos_dfs[pos]!=1){
			//pintar
			pos_dfs[pos]=1;
			//img.image[pos]=(unsigned char)(color_count%256);
			img.image[pos]=(unsigned char)(color);
		}

		int new_pos=pos;
		if(pos-width>=0 && pos_dfs[pos-width]!=1 						&& !fuera_rango(color, (int)img.image[pos-width])){//arriba
			new_pos=pos-width;
		}else if(pos+width<width*height && pos_dfs[pos+width]!=1 && !fuera_rango(color, (int)img.image[pos+width])){//abajo
			new_pos=pos+width;
		}else if((pos+1)%width!=0 && pos_dfs[pos+1]!=1 				&& !fuera_rango(color, (int)img.image[pos+1])){//derecha
			new_pos=pos+1;
		}else if(pos%width!=0 && pos_dfs[pos-1]!=1 					&& !fuera_rango(color, (int)img.image[pos-1])){//izquierda
			new_pos=pos-1;
		}

		if(new_pos!=pos){
			path.push(new_pos);
			pos=new_pos;
		}else{
			path.pop();
			if(!path.empty())
				pos=path.top();
		}
	}
}



void make_bfs(Image img, int range){

	RANGE=range;

	for(int i=0;i<img.height*img.width;i++){
		int color=(int)img.image[i];
		if(pos_bfs[i]==0){
			//pintar
			pos_bfs[i]=1;
			img.image[i]=(unsigned char)color;

			bfs(img, i, color);
		}
	}
}
void bfs(Image img, int pos, int color){
	int width=img.width;
	int height=img.height;


	queue<int> path;
	path.push(pos);

	while(!path.empty()){
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

		path.pop();
		pos=path.front();
	}
}
