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
			//stbi_image_free(image);
		}
		void write(){}
		void convert_to_gray(){
			size_t img_size=width*height*channels;
			int gray_channels=channels==4?2:1;
			size_t gray_img_size=width*height*gray_channels;
			
			//localizar memoria para la imagen de grises
			unsigned char *gray_img=(unsigned char*)malloc(gray_img_size);

			if(gray_img==NULL){
				cout<<"No se encontro el recurso"<<endl;
				exit(1);
			}

			for(unsigned char *p=image, *pg=gray_img; p!= image+img_size; p+=channels,pg+=gray_channels){
				*pg = (uint8_t)((*p+*(p+1)+*(p+2))/3.0); //rgb
				if(channels==4){
					*(pg+1)=*(p+3);
				}
			}

			this->channels=gray_channels;
			this->image=gray_img;
		}
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
	myImage.convert_to_gray();
	cout<<to_string(myImage)<<endl;

	return 0;
}

