# Proyecto 1 : Algoritmos de Ordenamiento
En este primer proyecto se implementan 3 algoritmos de ordenamiento ([Insertion Sort](https://github.com/JackMerma/proyectoAdaGrupoC/blob/main/P1_Ordenamiento/insertionSort.cpp), [Heap Sort](https://github.com/JackMerma/proyectoAdaGrupoC/blob/main/P1_Ordenamiento/heapSort.cpp) y [Quick Sort](https://github.com/JackMerma/proyectoAdaGrupoC/blob/main/P1_Ordenamiento/quickSort.cpp)), además, se detalla un análisis de la complejidad matemática para diferentes situaciones en las que se encuentre la dispersión de los datos.

## Recursos
Más allá de la implementación, se brinda un archivo [main.cpp](https://github.com/JackMerma/proyectoAdaGrupoC/blob/main/P1_Ordenamiento/main.cpp), donde usted podrá realizar sus propias operaciones mediante un pequeño software ya implementado que se explicará más adelante; esto además implica correr cualquier cantidad de datos o si desea comparar la complejidad, será más fácil generarlos.

### Obtención del software
Baje este repositorio localmente:
```console
git clone https://github.com/JackMerma/proyectoAdaGrupoC.git sort_software
```
Luego, cambie al directorio **sort_software**

### Ejecución del programa/consola
Una vez obtenido el recurso, asegúrese de tener el **GNU Compiler** (gcc), luego deberá compilar el recurso y ejecutarlo:
```console
g++ -o programa.exe main.cpp && programa
```

## Descripción
Al ejecutar este recurso, notará que se muestra un menú simple, donde usted podrá elegir entre ingresar los datos o generarlos aleatoriamente. Si elige ingresarlos, usted podrá ingresar números o palabras, pero si desea generarlos solo se podrán generar números. Finalmente, en cualquiera de los dos casos, el programa calculará el tiempo que demoró en ordenar los datos con los 3 tipos de ordenamientos:
+ Quick Sort
+ Heap Sort
+ Insertion Sort

### Ingresando datos
Para ingresar datos, deberá entrar la cantidad de datos a ingresar y luego, el tipo de dato (letras o números). Entonces, en este punto usted deberá ingresar **n** datos separados por espacios.

### Generando datos
En la generación de datos se le pedirá la cantidad de datos **n** y el rango de estos, separados por espacios (incluye al mínimo y máximo de este rango)

### Salida
En la salida de datos, se le presentará los **n** datos ordenados separados por espacios y en la última línea se imprimirá el tiempo de ejecución que tardó los 3 algoritmos (en segundos).

## Análisis de algoritmos

### Insertion Sort
![insertion sort gif](https://github.com/JackMerma/proyectoAdaGrupoC/blob/main/P1_Ordenamiento/img/insertion.gif)

La idea de este algoritmo, es comparar desde el primer elemento al n-ésimo de la lista y decrementar en 1 la longitud del arreglo a la derecha (arreglo desordenado); mientras esto sucede, el i-ésimo elemento es comparado con el arreglo a la izquierda (arreglo ordenado) y se busca la mejor posición para el dato i-ésimo dentro de este arreglo.

![insetion sort example](https://iq.opengenus.org/content/images/2020/04/Untitled-document.png)

En general, si se pudiera imaginar que se quiere ordenar el arreglo de forma ascendente(menor a mayor) y tenemos un arreglo ordenado en forma descendente(mayor a menor), entonces el arreglo tendría que coger a cada i-ésimo dato del arreglo a la derecha (arreglo no ordenado) y buscar la mejor posición en el arreglo a la izquierda, en este punto se puede deducir que la mejor posición para el i-ésimo dato a ordenar, está en la posición 1; entonces el arreglo recorrería en este segundo bucle: 1, 2, 3, 4, ..., n-1 posiciones, y multiplicando con las iteraciones que se hacen de 1 a n - 1, se puede concluir que la complejidad de este algoritmo es de O(n^2). Sin embargo, si el arreglo está ordenado, la complejidad puede llegar a ser O(n), pero trabajando con datos aleatorios, esta probabilidad es de: 1/n!, por lo cual se considera que es O(n^2).

### Heap Sort
![heap sort gif](https://github.com/JackMerma/proyectoAdaGrupoC/blob/main/P1_Ordenamiento/img/heap.gif)

Este ordenamiento hace uso de un **heap** para poder encontrar al mayor dentro de un arreglo de n-1 elementos y colocarlo en la primera posición de este arreglo, para luego intercambiar el n-2 elemento con este primero y realizar el mismo procedimiento con n-2 datos.

![heap general sort](https://github.com/JackMerma/proyectoAdaGrupoC/blob/main/P1_Ordenamiento/img/heap.PNG)

La particularidad está en el uso del heap, ya que para construir uno, el coste demanda en general O(log2(n)), esto ya que pasa solo por 'nodos' padres que se encuentran en una distribución de árbol binario, lo que se interpreta como un coste de logaritmo en base 2 de **n**; finalmente luego de construir el heap, intercambia posiciones con el n-1,n-2,n-3, ... 1 posiciones, lo que lo hace este coste exterior de O(n), entonces en general, el coste total habrá sido de O(n\*log2(n)). En el mejor caso, la construcción del algoritmo para desarrollar el heap, no se puede obviar (pasa por log2(n) posiciones), es por ello que incluso en este, el coste sigue siendo O(n\*log2(n)).

### Quick Sort (optimizado)
![quick sort gif](https://github.com/JackMerma/proyectoAdaGrupoC/blob/main/P1_Ordenamiento/img/quick.gif)

Este algoritmo de ordenamiento se basa en la idea de dividir y conquistar. Esencialmente, se sostiene en la idea de elegir a un **pivot** (normalmente el primer elemento del problema X) para luego ordenar los demás datos de la forma en que se encuentren a la izquierda los que son menores y a la derecha los mayores (orden de menor a mayor), y hasta que encuentre la posición correcta para este pivot, se podrán intercambiar los elementos de izquierda y de derecha en caso no cumplan esta idea.

Entonces, el mejor caso estaría cuando el **pivot** consigue una posición en la mitad de los datos en el problema X, para cuando se haya ordenado, entonces el pivot ocupara el lugar correspondiente (pivot ordenado), y el problema se subdivida en 2 subproblemas que al igual que este, cada uno tendrá un **pivot** y desarrollará el mismo procedimiento; esto entonces genera un coste de O(n\*log2(n)) siempre y cuando los casos se subdividan en 2 partes o el pivot siempre ocupe la posición media de cada subproblema. Se detalla en la siguiente figura el mejor caso:

![quick general partition](https://github.com/JackMerma/proyectoAdaGrupoC/blob/main/P1_Ordenamiento/img/quick.png)

Básicamente, se observa que los problemas se subdividen en la mitad (caso esencial); entonces habrá **c** divisiones, lo cual en general, lo hace en un coste de O(log2(n)) y multiplicada por los datos que recorre, se convierte en una complejidad de O(n\*log2(n)).

En el peor caso, se tiene a un arreglo ordenado de forma ascendente o descendente, esto ya que el **pivot**, siempre estará en la posición 1 o en la n-ésima, entonces el problema se subdivida en 2 particiones de 0 y n-1, deduciendo que si esto se repite en las siguientes sub-particiones, tendrá que partir n veces el problema y por la cantidad de datos que recorre (n-1), en general lo hace tener un coste de O(n^2); sin embargo, la probabilidad de que este ordenado ascendentemente o viceversa es de 2/n!, es por ello que se toma como uno de los ordenamientos más efectivos.

#### Quick Sort Hibrido

Lo dicho anteriormente, se implementa perfectamente en un Quick Sort, sin embargo hay una forma de optimizar este proceso aún mas. Como se sabe un método por Insercion, implica generar menos comparaciones para casos pequeños, por lo cual esta metodología se implementó mediante la restriccion de uso de un **THRESHOLD** (umbral), que basicamente indica la maxima cantidad a la que pueden llegar las subdivisiones para desde ese punto poder usar el algoritmo de Insertion Sort y no la de Quick Sort, por ejemplo, en esta implementación se define al **umbral** como una constante que vale **11**, esto ya que se desea que si la longitud de los subarreglos generados en las subdivision llega a ser menor que **11**, entonces se ordenen estos elementos mediante Insercion.

## Bibliografía
+ [Hybrid Quicksort: An empirical Study](https://journal.binus.ac.id/index.php/commit/article/view/582/560)
+ [Advanced Quick Sort (Hybrid Algorithm)](https://www.geeksforgeeks.org/advanced-quick-sort-hybrid-algorithm/)
