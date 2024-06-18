# Algoritmos y Estructuras de Datos TP1

**Metodología-DP-ECP-Módulos-ED: Registro, Arreglo y Archivo texto.**

Se requiere de un proceso que realice los pedidos de compra de artículos de los clientes. Para ello, se cuenta con los siguientes archivos de datos:

#####Clientes.txt
Desordenado, máx. 100 clientes, conteniendo los siguientes datos:
* Id.Cliente (máx. 8 díg.)
* Raz.Soc. (str20)
* Domicilio (str20)
* Localidad (str20)
* Cod.Pos. (1000:9999)
* Fec.Alta (sFec)
* Saldo (9(7).99)

>El tipo sFec es un registro con 3 campos c/u. de tipo short dia, mes, agno, en ese orden.

#####Articulos.txt
Sin orden, máx. 100 articulos, cada linea representa un articulo:
* Cód.Artículo (1:100)
* Descripción (str20)
* Stock Actual (máx. 4 díg.)
* Pre.Uni (máx. 9(7).99)

#####Articulos.txt
Ordenado por **Id.Cliente** + **Cód.Artículo**, cada una de las líneas contiene los siguientes datos:
* Id.Cliente
* Cód.Artículo
* Cant.Pedida (máx. 4 díg.)

###Consigna
1. Volcar a la memoria **RAM** en estructuras estáticas:
	1a. _Clientes.Txt_: la clave y su posición ordenado por la **clave del cliente.**
	1b. _Articulos.Txt_: todos los datos, existe una relación 1 a 1, es decir, **clave = posición.** 

2. Procesar _Pedidos.Txt_ para generar las facturas a cada Cliente las cuales se graban en el archivo de salida _Facturas.Txt_. El diseño de las facturas obedece al siguiente formato de salida, ordenado por **Id.Cliente** + **Cód.Artículo**:

	![](http://imgfz.com/i/w8ZOWrx.png)

	>El nro. de la factura debe comenzar con el nro. legajo del líder del grupo.
	Los rótulos grisáceos no deben emitirse, solo indican la zona de la Factura.

3. Grabar en el archivo de _MvtosPedidos_.Txt un resumen de cada factura ordenado por **IdCliente**, con los siguientes datos:

	Id.Cliente	Nro.Factura (6 díg.)	Fecha (aaaammdd)	Imp.Neto(9(8).99)

En el bloque principal, solo se establecen las invocaciones a los módulos, y declarar las variables pertenecientes a este módulo y sus tipos de datos.
El bloque principal debe contener las siguientes acciones:

```c++
main()   {   
      Declarar las variables utilizadas en el bloque main().
	
      Abrir (Clientes,Articulos,Pedidos,Facturas,MvtosPedidos);
      ProcClientes(Clientes,vrClientes);
      ProcArticulos(Articulos,vrArticulos);
      ProcPedidos(Pedidos,Clientes,vrClientes,vrArticulos,Facturas,MvtosPedidos);
      Cerrar (Clientes,Articulos,Pedidos,Facturas,MvtosPedidos);
      return 0;
}
``` 

###Observaciones, restricciones y recursos disponibles

Utilizar las siguientes funciones, invocando en donde sea necesario:
* *bool* **LeerSuf** (*ifstream* &id, sid &id), el cual **lee una componente de datos** del archivo y los almacena en una estructura interna. La función retorna un boolean, verdadero, si la lectura fue exitosa, caso contrario, falso; *sid* indica un tipo de estructura de datos. Crear una función de lectura para cada archivo que se lee. Suf luego de Leer en el nombre de la función es un sufijo para el archivo que se lee, el cual debe ser reemplazado Suf por el nombre apropiado, p.e. *LeerCli, LeerArt…*
* *void* **InsertarEnOrden** (*tid1* tbl, *tid2* id, *tid3* card), ordena tbl *Clientes* por *id.Cli.*
* *void* **OrdxBur** (*tid *tbl, *tid* card), ordena tbl *Clientes* por *id.Cli.*
* *void* **IntCmb** (*id* &elem1,*id* &elem2), intercambia ambos elementos. 
* *char* ***Space**(*short* n), retorna una cadena con n espacios.
* *string* **Replicate**(*char* car, *unsigned* n), retorna una cadena con n veces car.
* *long* **GetDate**(*int* year,*int* mes,*int* dia,*int* diaSem). La función retorna la fecha larga, como un solo número en el formato aaaammdd. Esta función se encuentra en OBTENER LA FECHA Y HORA DEL SISTEMA del apunte del prof. Hugo Cuello Teoría y Práctica del Lenguaje C/C++ pág. 603.

**Espacio en disco**: Solo para generar los archivos de salida **Facturas** y **MvtosPedidos** en formato texto.
**Espacio para arreglos y registros**: Lo necesario que requiera este proyecto.
**Espacio en memoria dinámica**: 0 bytes.
**Accesos a los archivos**: un solo recorrido secuencial, para leer en Clientes, Artículos, Pedidos. Además acceso al azar para leer en Clientes. Acceso secuencial para grabar en Facturas y en MvtosPedidos.
**Bloque Principal**: sólo invocaciones a módulos, según lo establecido anteriormente.
**Paradigma de Programación**: Solo se aceptará el Paradigma Imperativo, Programación Estructurada y Modular.
**Optimización**: dado que el uso de ciclos afecta el tiempo de ejecución de un proceso, se evaluará la eficiencia en el uso de los mismos.
Utilizar nombres significativos para los identificadores, dibujos para las estructuras de datos a utilizar, rotulando cada elemento, tamaño, breve leyenda de cómo se generan y estado inicial, respetar esos nombres para utilizarlos en el algoritmo. Preparar una muestra de datos para los archivos de datos e imprimirla, para ejecutar el programa. En el disco solo contendrán los archivos “**TP1V_K1_ _ _G_-Apellido Nombre.cpp**”,  y los archivos de datos indicados anteriormente como así también el archivo de salida todos ubicados en la carpeta raíz del disco. Ejemplo: *TP1V1_K1023G3-PEREZ JUAN.CPP*
**Cada grupo debe crear su propia muestra de datos para los archivos, (pensar un rubro).**
Se deben utilizar constantes con nombres para indicar cantidades.
El Trabajo Práctico deberá ser entregado de acuerdo a las pautas indicadas más abajo, el cual se aprobará si reúne los requerimientos solicitados en **tiempo y forma (tres fechas máximas)**: A: Aprobado, N: No Aprobado.  **(Se debe respetar el orden indicado a continuación)**:

1. Entregar en carpeta tamaño A4 de tapa transparente y con sujetador de gancho perfectamente alineadas para las hojas lo siguiente: (no se aceptan hojas sueltas ni otro tipo de carpeta) 

2. Carátula con los datos de los integrantes del TP, la cantidad de alumnos por grupo del mismo curso se determinará en clase no superando 5 grupos como máximo.

3. Esta misma hoja que establece el enunciado del problema a resolver. Cada grupo elegirá un líder del proyecto, que será el responsable de realizar las entregas del TP. Si un líder abandona la cursada, se deberá elegir otro líder.

4. Diseñar las estructuras de Datos graficándolas indicando con rótulos apropiados, cada elemento, su tamaño en bytes y las variables utilizadas. Las estructuras de datos a graficar son: 
	a. El diseño de los registros de cada uno de los archivos.
	b. Otras estructuras de datos que considere necesarias para poder realizar el proceso 	solicitado. Algunas serán explicadas en clase, como complemento a este documento.

5. Graficar el Bloque Principal. 

6. Graficar cada uno de los módulos –funciones- a utilizar, cabecera y cuerpo.

7. Construir una muestra de datos, para los archivo de datos, la cual se la utilizará para probar el Algoritmo. En la hoja impresa a entregar debe haber rótulos apropiados, pero, NO en los archivos de Datos, el cual contendrán solamente, los datos. Ver detalle del formato más abajo.

8. Emitir según la muestra establecida, los resultados esperados, siempre acompañada de los rótulos apropiados, según formato de salida indicados anteriormente.

9. Codificación del Algoritmo completo en el Lenguaje C++, emitiendo números de líneas. Usar Code-Blocks. Las primeras líneas serán de comentario indicando: Nombre del programa, fecha entrega, Nro. versión, breve comentario del objetivo del programa, datos del curso, nombre del día, turno, nro. del grupo e integrantes (Apellido, Nombre). Nombre del compilador: Borland C++ V.5.5

###Formato del archivo de datos Clientes.Txt

Se deberá ajustar la escritura de los datos respetando a raja tabla este formato en donde cada columna representa un dato y su tipo de dato y ancho:

Cada columna representa de izquierda a derecha lo siguiente: 

|  idCli | Raz.Soc.   |  Domic. | Local.  | Cód.Pos.   | Fec.alta          |  Saldo |
| ------------ | ------------ | ------------ | ------------ | ------------ | ------------ | ------------ |
|  9(8)    |  X(20)       |  X(20)     | X(20)      |  9999  |  99 99 9999    |   99 99 9999   |

Los números enteros o reales ajustado a la derecha, las cadenas ajustadas a la izquierda. Si una cadena tiene menos caracteres de los indicados, se deberá rellenar con espacios en blanco a derecha.


