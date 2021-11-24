/** 
 * @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
 * @created     : 07/11/2021
 * @filename    : Image
 * @description : Main principal, donde se ralizan procedimientos generales con las imagenes (lectura, escritura y recorridos)
 */
#include <bits/stdc++.h>
#include "dfs_bfs.cpp"//ya incluye a Image.cpp
using namespace std;

#define ll long long
#define endl "\n"

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	Image img1;
	img1.read("imagenes/dory.jpg");

	Image img2;
	img2.read("imagenes/nemo.jpg");

	//recorridos diferentes en imagenes diferentes
	make_dfs(img1, 31);//25-30
	make_bfs(img2, 60);//55-60-70


	//salidas
	img1.write("imagenes/dory2","jpg");
	img2.write("imagenes/nemo2","jpg");

	cout<<"Proceso terminado."<<endl;

	return 0;
}
