/** 
 * @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
 * @created     : 07/11/2021
 * @filename    : image_functions
 * @description : _
 */
#include <bits/stdc++.h>
#include <stdint.h>
using namespace std;

#define ll long long
#define endl "\n"

#define STB_IMAGE_IMPLEMENTATION //necesario
#include "stb_files/stb_image.h"

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int width, height, channels;

	unsigned char * _image=stbi_load("img.jpg", &width, &height, &channels, 0);

	if(_image==NULL){
		cout<<"Error en cargar la imagen"<<endl;
		exit(1);
	}else{
		cout<<"Cargado correctamente"<<endl;
		stbi_image_free(_image);
		cout<<"width:"<<width<<endl;
		cout<<"height:"<<height<<endl;
		cout<<"channels:"<<channels<<endl;
	}

	return 0;
}

