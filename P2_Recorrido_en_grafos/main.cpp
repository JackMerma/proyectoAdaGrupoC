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

	Image myImage;
	cout<<"informacion ... "<<endl;
	myImage.read("other.jpg");

	cout<<to_string(myImage)<<endl;

	for(int i=0;i<myImage.height;i++){
		for(int u=0;u<myImage.width;u++){
			if((int)myImage.data[i][u]==0) cout<<"#";
			else if((int)myImage.data[i][u]==255) cout<<" "; 
			else cout<<"*";
		}
		cout<<endl;
	}

	cout<<endl;
	return 0;
}
