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

	/**
	 * Casos en rangos de 20 - 40 y 60 (+-) 
	 */
	Image dory1,dory2,dory3;
		//lectura
	dory1.read("imagenes/dory.jpg");
	dory2.read("imagenes/dory.jpg");
	dory3.read("imagenes/dory.jpg");

		//recorrido
	make_dfs(dory1, 20);
	make_dfs(dory2, 40);
	make_dfs(dory3, 60);

		//escritura
	dory1.write("imagenes/dory_20","jpg");
	dory2.write("imagenes/dory_40","jpg");
	dory3.write("imagenes/dory_60","jpg");
		
		//lectura
	Image nemo1,nemo2,nemo3;
	nemo1.read("imagenes/nemo.jpg");
	nemo2.read("imagenes/nemo.jpg");
	nemo3.read("imagenes/nemo.jpg");
		
		//recorrido
	make_bfs(nemo1, 20);
	make_bfs(nemo2, 40);
	make_bfs(nemo3, 60);

		//escritura
	nemo1.write("imagenes/nemo_20","jpg");
	nemo2.write("imagenes/nemo_40","jpg");
	nemo3.write("imagenes/nemo_60","jpg");




	/**
	 *  CASOS FINALES
	 */

		//lectura
	Image dory;
	dory.read("imagenes/dory.jpg");

	Image nemo;
	nemo.read("imagenes/nemo.jpg");

		//recorrido
	make_dfs(dory, 31);
	make_bfs(nemo, 60);

		//escritura
	dory.write("imagenes/dory2","jpg");
	nemo.write("imagenes/nemo2","jpg");


	cout<<"Proceso terminado."<<endl;

	return 0;
}
