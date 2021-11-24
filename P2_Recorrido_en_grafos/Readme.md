# Proyecto 2 : Recorrido en Grafos
En este proyecto, se implementó el recorrido en grafos DFS (búsqueda en profundidad) y BFS (búsqueda en anchura), para ser aplicado en el pintado de imagenes en general.

## Recursos
Más allá de la implementación, se brinda un archivo [main.cpp](https://github.com/JackMerma/proyectoAdaGrupoC/blob/main/P2_Recorrido_en_grafos/main.cpp), donde se realizan los casos de prueba o salidas mostradas en la carpeta de [Imagenes](https://github.com/JackMerma/proyectoAdaGrupoC/tree/main/P2_Recorrido_en_grafos/imagenes).

## Clase Image
Se implementó una clase [Image](https://github.com/JackMerma/proyectoAdaGrupoC/blob/main/P2_Recorrido_en_grafos/Image.cpp), donde básicamente se usa los recursos de [lectura](https://github.com/JackMerma/proyectoAdaGrupoC/blob/main/P2_Recorrido_en_grafos/stb_files/stb_image.h) y [escritura](https://github.com/JackMerma/proyectoAdaGrupoC/blob/main/P2_Recorrido_en_grafos/stb_files/stb_image_write.h) ya proporcionadas, estos se pueden encontrar en la carpeta [stb_files](https://github.com/JackMerma/proyectoAdaGrupoC/tree/main/P2_Recorrido_en_grafos/stb_files).
Entonces, esta clase tiene algunas funciones y métodos como las dimensiones de la imagen (width - height), la **data** de la imagen (array image), funciones de escritura, lectura, conversion a escala de grises, etc., esto para facilitar el manejo de operaciones a realizar con las imagenes.

## Archivo [dfs_bfs.cpp](https://github.com/JackMerma/proyectoAdaGrupoC/blob/main/P2_Recorrido_en_grafos/dfs_bfs.cpp)
Para facilitar los procesos en el archivo **main**, se implementó este archivo, donde se realizan las operaciones pedidas (recorridos en DFS y BFS) y otros metodos necesarios que usan estos mismos.
Luego, el archivo **main** solo importa este archivo que ya importa a su vez la clase **Image**.

## Funcionamiento
En este apartado se indicará el uso general del software haciendo cambios directos de código en **main.cpp**

### Lectura
En la lectura de la imagen se recomienda el uso de extensiones .jpg y .png. Por otro lado, usted solo debe llamar a la función enviando el **path** de la imagen y se cargará automáticamente en **escala de GRISES**.
Para este proyecto se tienen 2 imagenes de muestra ([dory.jpg](https://github.com/JackMerma/proyectoAdaGrupoC/blob/main/P2_Recorrido_en_grafos/imagenes/dory.jpg) y [nemo.jpg](https://github.com/JackMerma/proyectoAdaGrupoC/blob/main/P2_Recorrido_en_grafos/imagenes/nemo.jpg)) ubicadas en la carpeta de [imagenes](https://github.com/JackMerma/proyectoAdaGrupoC/tree/main/P2_Recorrido_en_grafos/imagenes), que se usarán para hacer el análisis correspondiente.

### Recorridos
En los recorridos **BFS** y **DFS**, se debe tomar en cuenta que estos sobrescriben los valores de un objeto **Image** en su **data**, por ello no es conveniente realizar multiples procesos de recorridos en un mismo objeto **Image**, por lo cual podria recurrir a volver a leer el mismo archivo desde otro objeto **Image** como se hace en algunos casos en **main.cpp**.
Por otro lado, para el llamado, se da la libertad de enviar un rango positivo \[0-255] para recorrer los pixeles de la imagen (mientras más grande sea el rango, menos componentes mostrados).
Además, es necesario recalcar que ambos recorridos estan implementados iterativamente, de esta forma puede despreocuparse de errores en los recorridos con imagenes grandes.

Finalmente, también se debe indicar que el 'repintado' de las imagenes están dadas por un **color dominante**, esto quiere decir que el color que forma a un componente k, esta dado por el primer color añadido en ese componente para ambos recorridos, esto para que el resultado pueda compararse con la imagen inicial y además que de tener un color natural y no forzado. Luego, los colores entre otros componentes no pueden verse afectados mediante el **RANGO**, ya que se usa una matriz de verificación (1 y 0 / booleano). 

### Escritura
En la escritura de una imagen modificada, se brinda la opcion de tener salidas de tipo **.png** y **.jpg**, ademas de enviar un path y el nombre del archivo para la salida. Para los ejemplos en el **main**, la salida se realizan en la carpeta de **imagenes**.

## Análisis de salidas
En este apartado, se dará un pequeño análisis sobre los resultados encontrados en las pruebas realizadas de las dos imagenes proporcionadas y los recorridos implementados.

### Salidas con rangos de 20, 40 y 60
Primero se quiere mostrar cuales son las salidas tomando 3 rangos diferentes sobre la misma imagen, para ello se cargó a la imagen 3 veces y se realizó esta modificación con rangos de 20, 40 y 60: 

#### Nemo
Resultados de los 3 rangos de la imagen **nemo.jpg**

**Rango de 20** ![rango de 20](https://github.com/JackMerma/proyectoAdaGrupoC/blob/main/P2_Recorrido_en_grafos/imagenes/nemo_20.jpg)  
**Rango de 40** ![rango de 40](https://github.com/JackMerma/proyectoAdaGrupoC/blob/main/P2_Recorrido_en_grafos/imagenes/nemo_40.jpg)  
**Rango de 60** ![rango de 60](https://github.com/JackMerma/proyectoAdaGrupoC/blob/main/P2_Recorrido_en_grafos/imagenes/nemo_60.jpg)

Entonces, se puede decir que esta imagen es generalmente recomendable para su experimentacion por que los colores en general, difieren entre si (componentes) sobre rangos grandes (mas de 40).

#### Dory
Resultados de los 3 rangos de la imagen **dory.jpg**

**Rango de 20** ![rango de 20](https://github.com/JackMerma/proyectoAdaGrupoC/blob/main/P2_Recorrido_en_grafos/imagenes/dory_20.jpg)  
**Rango de 40** ![rango de 40](https://github.com/JackMerma/proyectoAdaGrupoC/blob/main/P2_Recorrido_en_grafos/imagenes/dory_40.jpg)  
**Rango de 60** ![rango de 60](https://github.com/JackMerma/proyectoAdaGrupoC/blob/main/P2_Recorrido_en_grafos/imagenes/dory_60.jpg)

En este caso, la imagen a medida que trabaja con rangos grandes, va perdiendo la forma del objeto principal a evaluar, es por ello que no es una buena imagen de experimentacion.

### Salidas finales
Entonces, dadas las conclusiones del último apartado, se decidió mostrar los resultados de la imagen **nemo.jpg** trabajando con un rango de 60 y **dory.jpg** con un rango de 31. Las siguientes imagenes muestra la imagen aplicada en disho rango y los componentes identificados.

#### Nemo
**Imagen principal** ![salida de nemo con rango de 60](https://github.com/JackMerma/proyectoAdaGrupoC/blob/main/P2_Recorrido_en_grafos/imagenes/nemo2.jpg)
**Componentes identificados** ![componentes](https://github.com/JackMerma/proyectoAdaGrupoC/blob/main/P2_Recorrido_en_grafos/imagenes/nemo2_modificacion.jpg)

Como se puede observar, a este rango, se identifican en general 9 componentes (ojo humano), y se puede decir que en la imagen, aun se puede identificar al objeto principal (pez)

#### Dory
**Imagen principal** ![salida de dory con rango de 31](https://github.com/JackMerma/proyectoAdaGrupoC/blob/main/P2_Recorrido_en_grafos/imagenes/dory2.jpg)
**Componentes identificados** ![componentes](https://github.com/JackMerma/proyectoAdaGrupoC/blob/main/P2_Recorrido_en_grafos/imagenes/dory2_modificacion.jpg)

En este caso, sin tomar en consideracion a los componentes en el fondo del objeto principal, se puede identificar 4 componentes (ojo humano), y se puede decir que el objeto se llega a identificar a este rango bajo sin poder haber pintado el fondo de un solo componente.
