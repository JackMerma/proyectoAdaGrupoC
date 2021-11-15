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
		vector<vector<unsigned char>> data_image;
		//unsigned char data_image[2000][2000]; //en forma de matriz y en escala gris
		unsigned char *image=NULL; //en forma lineal y en escala RGB

		void read(char *path){
			/**
			 * Metodo read: Lee una imagen RGB
			 * Atributos:
			 * 	*path -> path para encontrar al archivo
			 */
			image=stbi_load(path, &width, &height, &channels, 0);
			if(image==NULL){
				cout<<"Error al cargar la imagen"<<endl;
				exit(1);
			}
			//stbi_image_free(image);
			//free(image)
		}

		void write(char* type, char* name){
			/**
			 * Metodo write: Escribe sobre un archivo nuevo
			 * Atributos:
			 * 	*type -> tipo de extension de la imagen
			 * 	*name -> nombre de la imagen
			 */

			//transformando todo el nombre del nuevo archivo
			char complete_name[100];
			strcpy(complete_name,name);
			strcat(complete_name,".");
			strcat(complete_name,type);

			//procedimiento
			string option=string(type);
			if(option=="png"){
				stbi_write_png(complete_name,width,height,channels,image,width*channels);
			}else if(option=="jpg"){
				stbi_write_jpg(complete_name,width,height,channels,image,100);
			}else{
				//por defecto
				write("jpg",name);
			}
		}

		void convert_to_gray(){
			/**
			 * Metodo convert_to_gray: Convierte una imagen a escala de grises
			 */
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

		void convert_to_matrix(){
			/**
			 * Metodo covert_to_matrix: coloca los datos lineales en una matriz de height*width
			 */
			
			vector<unsigned char> aux;
			int fil=0,col=0;
			for(int i=0;i<height*width;i++,col++){
				if(i%width==0 && i!= 0)
					data_image.push_back(aux);


				if((int)(i/width)==0){
					aux.push_back(image[i]);
				}else{
					aux[i%width]=image[i];
				}
			}
			data_image.push_back(aux);

			//for(int i=0;i<height*width;i++)
			//	data_image[(int)(i/width)][i%width]=image[i];
			//la fila se determina con i/width
			//la columna se determina con i%width
		}

		friend string to_string(Image const& img){
			/**
			 * Metodo to_string: retorna informacion de la imagen en forma de cadena
			 * Atributos:
			 * 	img -> Imagen de donde se saca la informacion
			 */
			return "width:"+to_string(img.width)+
				"\nheight:"+to_string(img.height)+
				"\nchannels:"+to_string(img.channels)+"\n";
		}
};
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cout<<"hola"<<endl;
	Image myImage;
	myImage.read("other.jpg");
	myImage.convert_to_gray();
	myImage.convert_to_matrix();

	cout<<to_string(myImage)<<endl;

	for(int i=0;i<myImage.height;i++){
		for(int u=0;u<myImage.width;u++){
			if((int)myImage.data_image[i][u]==0) cout<<"*";
			else if((int)myImage.data_image[i][u]==255) cout<<"$";
			else cout<<"O";
		}
		cout<<endl;
	}

	cout<<endl;
	return 0;
}
