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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cout<<"hola"<<endl;
	Image img;
	img.read("sdasdsd.jpg");
	img.convert_to_gray();
	img.convert_to_matrix();

	cout<<to_string(img)<<endl;

	for(int i=0;i<img.height;i++){
		for(int u=0;u<img.width;u++){
			if((int)img.data[i][u]==0) cout<<"*";
			else if((int)img.data[i][u]==255) cout<<"$";
			else cout<<"O";
		}
		cout<<endl;
	}

	cout<<endl;
	return 0;
}

