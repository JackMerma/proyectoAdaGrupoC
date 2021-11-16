/** 
 * @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
 * @created     : 07/11/2021
 * @filename    : Image
 * @description : Clase imagen que lee, escribe y convierte a escala de grises una imagen
 */
#include <bits/stdc++.h>
#include "dfs_bfs.cpp"//ya incluye a Image.cpp
using namespace std;

#define ll long long
#define endl "\n"

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Image myImage;
	myImage.read("other.jpg");

	//recorrido DFS
	make_dfs(myImage);

	//recorrido BFS
	make_bfs(myImage);

	informacion_dfs();
	informacion_bfs();

	cout<<endl;
	return 0;
}
