/** 
 * @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
 * @created     : 07/11/2021
 * @filename    : Image
 * @description : Clase imagen que lee, escribe y convierte a escala de grises una imagen
 */
#include <bits/stdc++.h>
#include <stdint.h>
using namespace std;

#define ll long long
#define endl "\n"

#define STB_IMAGE_IMPLEMENTATION 
#include "stb_files/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_files/stb_image_write.h"

class Image{
	public:
		int height;
		int width;
		int channels;
		unsigned char *image=NULL;

		void read(char *path){
			image=stbi_load(path, &width, &height, &channels, 0);
			if(image==NULL){
				cout<<"Error al cargar la imagen"<<endl;
				exit(1);
			}
			stbi_image_free(image);
		}
		void write(){}
		void convert_to_gray(){}
		friend string to_string(Image const& img){
			return "width:"+to_string(img.width)+
				"\nheight:"+to_string(img.height)+
				"\nchannels:"+to_string(img.channels)+"\n";
		}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Image myImage;
	myImage.read("img.jpg");
	cout<<to_string(myImage)<<endl;

	return 0;
}

