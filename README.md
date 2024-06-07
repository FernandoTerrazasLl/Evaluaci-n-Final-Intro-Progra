# Base de Datos
Nuestra empresa necesita desarrollar una aplicación de calendario que maneje una base de datos extensa con millones de eventos, fechas y usuarios de la empresa. Por cuestiones de seguridad de nuestra informacion clasificada y privacida vemos necesario comenzar dicho proyecto.

Para desarrollar la base de datos necesitaremos:
- La base de datos debe manejar la creación, eliminacion y consulta de eventos en ciertas fechas en el menor tiempo posible.
- La base de datos debe tener una considerable capacidad de almacenamiento en el sistema.
- Debe ser capaz de recibir eventos y fechas personalizadas del calendario y almacenarlas como datos para contar con suficeinte seguridad y confianza.
- Debe ser capaz de encontrar datos especificos que estemos buscando entre todos los datos almacenados.

## EL PROBLEMA

Eres un desarrollador C++ en una empresa y se te ha solicitado crear un modelo de base de datos simple. Pero antes te piden investigar sobre todas las bases de datos existentes y hacer una comparativa para justificar esta implementacion.

Entonces, primero se debe realizar dicha comparativa estudiar las existentes y escribir una justificacion del desarrollo de un nuevo manejador de base de datos.

Luego, es necesario analizar el problema y escribir un programa en C++ que implemente el trabajo con una base de datos simple (abreviado «BD»). El programa se comunicará con el usuario a través de la entrada y salida estándar (flujos stdin y stdout).

Almacenaremos en nuestra BD pares del tipo: fecha, evento. Definiremos la fecha como una cadena en el formato Año-Mes-Día, donde Año, Mes y Día son números enteros.

Definiremos el evento como una cadena de caracteres imprimibles arbitrarios sin separadores dentro (espacios, tabulaciones, etc.). Un evento no puede ser una cadena vacía. En una misma fecha pueden ocurrir muchos eventos diferentes, la BD debe ser capaz de almacenarlos todos. No es necesario guardar eventos idénticos que ocurran el mismo día: basta con guardar solo uno de ellos.

Nuestra BD debe entender ciertos comandos para que se pueda interactuar con ella:

agregar evento: Add Fecha Evento
eliminar evento: Del Fecha Evento
eliminar todos los eventos de una fecha específica: Del Fecha
buscar eventos en una fecha específica: Find Fecha
imprimir todos los eventos de todas las fechas: Print
Todos los comandos, fechas y eventos en la entrada están separados por espacios. Los comandos se leen desde la entrada estándar. En una línea puede haber exactamente un comando, pero se pueden ingresar varios comandos en varias líneas. También pueden haber líneas vacías en la entrada, las cuales deben ser ignoradas, y continuar procesando los nuevos comandos en las líneas siguientes.

Agregar evento (Add Fecha Evento)
Al agregar un evento, la BD debe recordarlo y luego mostrarlo durante la búsqueda (comando Find) o impresión (comando Print). Si el evento especificado para una fecha determinada ya existe, se debe ignorar la repetición de su adición. En caso de una entrada correcta, el programa no debe mostrar nada en la pantalla.

Eliminar evento (Del Fecha Evento)
El comando debe eliminar un evento agregado anteriormente con el nombre especificado en la fecha indicada, si existe. Si el evento se encuentra y se elimina, el programa debe mostrar la línea "Deleted successfully" (sin comillas). Si no se encuentra el evento en la fecha especificada, el programa debe mostrar la línea "Event not found" (sin comillas).

Eliminar varios eventos (Del Fecha)
El comando elimina todos los eventos previamente agregados para la fecha indicada. El programa siempre debe mostrar una línea en el formato "Deleted N events", donde N es la cantidad de eventos encontrados y eliminados. N puede ser igual a cero si no hubo ningún evento en la fecha especificada.

Buscar eventos (Find Fecha)
Encuentra e imprime los eventos previamente agregados en la fecha indicada. El programa debe imprimir solo los eventos, uno por línea. Los eventos deben estar ordenados en orden ascendente según la comparación de cadenas (tipo string).

Imprimir todos los eventos (Print)
Con este comando se puede mostrar todo el contenido de nuestra BD. El programa debe imprimir todas las parejas Fecha Evento, una por línea. Todas las parejas deben estar ordenadas por fecha, y los eventos dentro de una misma fecha deben estar ordenados en orden ascendente según la comparación de cadenas (tipo string). Las fechas deben estar formateadas de manera especial: AAAA-MM-DD, donde A, M, D son los dígitos de los números del año, mes y día respectivamente. Si algún número tiene menos dígitos, debe completarse con ceros, por ejemplo, 0001-01-01 es el primero de enero del primer año. No necesitarás imprimir una fecha con un valor de año negativo.

Manejo de errores de entrada
La entrada en esta tarea no siempre es correcta: tu programa debe manejar correctamente algunos errores de entrada.

Qué errores de entrada manejar
Si el usuario ingresa un comando desconocido, el programa debe informar de ello, mostrando la línea "Unknown command: COMMAND", donde COMMAND es el comando que ingresó el usuario. Se considera comando la primera palabra en la línea (hasta el espacio).

Si la fecha no corresponde al formato Año-Mes-Día, donde Año, Mes y Día son números enteros arbitrarios, el programa debe imprimir "Wrong date format: DATE", donde DATE es lo que el usuario ingresó en lugar de la fecha (hasta el espacio). Ten en cuenta que las partes de la fecha están separadas por un guion exacto, y la fecha no debe contener caracteres adicionales ni antes del año ni después del día. Las partes de la fecha no pueden estar vacías, pero pueden ser cero o incluso negativas.

Si el formato de la fecha es correcto, se debe verificar la validez del mes y el día.

Si el número del mes no es un número del 1 al 12, muestra "Month value is invalid: MONTH", donde MONTH es el número de mes incorrecto, por ejemplo, 13 o -1.

Si el mes es correcto, pero el día no está en el rango de 1 a 31, muestra "Day value is invalid: DAY", donde DAY es el número de día incorrecto en el mes, por ejemplo, 39 o 0.

Ten en cuenta que:

No es necesario verificar el valor del año por separado.
No es necesario verificar la corrección del calendario: se considera que el número de
días en cada mes es 31, no se necesita considerar años bisiestos. Si tanto el mes como el día son incorrectos, se debe mostrar solo un mensaje de error sobre el mes.

Ejemplos:

~~~
1-1-1 — fecha correcta
-1-1-1 — fecha correcta (año -1, mes 1, día 1)
1--1-1 — fecha en formato correcto, pero con un mes incorrecto -1
1---1-1 — fecha en formato incorrecto: el mes no puede comenzar con dos guiones
1-+1-+1 — fecha correcta, ya que +1 es un número entero
Después de manejar cualquiera de los errores de entrada descritos y mostrar el mensaje, el programa debe terminar su ejecución.
~~~

Qué errores de entrada no manejar
No se busca romper tu programa de todas las formas posibles, por lo tanto, aparte de lo descrito en el punto anterior, puedes confiar en la corrección de la entrada. En particular, se garantiza que:

Cada comando ocupa exactamente una línea completa, aunque en la entrada puede haber líneas vacías (que deben ser ignoradas).
Los eventos siempre contienen el número indicado de argumentos: después del comando Add siempre siguen la fecha y el evento, después del comando Find siempre sigue la fecha, después del comando Del siempre sigue la fecha y, posiblemente, el evento, y el comando Print no contiene información adicional.
Todos los comandos, fechas y eventos son cadenas no vacías y no contienen espacios u otros caracteres de espacio. (En particular, nuestras pruebas no contienen el comando "Add 2018-02-12", ya que no tiene un nombre de evento después de la fecha). Por otro lado, el comando Del puede no contener un evento después de la fecha: en este caso, se deben eliminar todos los eventos para la fecha especificada (ver sección "Eliminar varios eventos")
Aunque una fecha con un valor de año negativo se considera correcta, las pruebas están diseñadas de tal manera que no necesitarás imprimirla en el comando Print.
Ejemplos

Entrada correcta:

~~~
Add 0-1-2 event1
Add 1-2-3 event2
Find 0-1-2
Del 0-1-2
Print
Del 1-2-3 event2
Del 1-2-3 event2
~~~

Salida:

~~~
event1
Deleted 1 events
0001-02-03 event2
Deleted successfully
Event not found
~~~

Entrada Incorrecta:

~~~
Add 0-13-32 event1
Salida:
Month value is invalid: 13
~~~

Observaciones
Conversión de un número a una cadena Para, teniendo el número MONTH, formar la cadena «El valor del mes no es válido: MONTH», se puede utilizar la función to_string, que convierte el número a una cadena. De esta manera, se puede formar la cadena necesaria de la siguiente manera:

~~~
string error = "Month value is invalid: " + to_string(month); language-cpp
~~~

Búsqueda en un diccionario constante
Al implementar este patrón, es posible que necesites utilizar la búsqueda con corchetes para un diccionario pasado a la función por referencia constante. Como se mostró anteriormente, esto no será posible, ya que el acceso a una clave inexistente con corchetes la agregará al diccionario, lo cual no es permisible para un diccionario constante.

En este caso, en lugar de corchetes, utiliza el método at: en caso de ausencia de la clave, lanzará una excepción y, por lo tanto, puede ser utilizado para un objeto constante.

Por ejemplo, en lugar del código

~~~
void DoSomething(const map<int, int>& m) {
//.
if (m.count(key) > 0) {
value = m[key]; / No compilara
}
//...
}
~~~

Use este codigo:

~~~
void DoSomething(const map<int, int>& m) {
//...
if (m.count(key) > 0) {
value = m.at(key); / Todo bien
}
//...
}
~~~

## Comparativa de Bases de Datos Existentes
- MySQL es una base de datos muy popular y ampliamente utilizada, lo que facilita encontrar soluciones a problemas y obtener soporte. Funciona en múltiples plataformas y es compatible con muchos lenguajes de programación. Sin embargo es menos flexible en comparación con las bases de datos NoSQL. Al ser de codigo abierto no tiene un soporte oficial de alguna empresa de confianza, y nos provee de una menor calidad de seguridad que una base de datos propia.

- PostgreSQL es muy extensible y permite crear tipos de datos personalizados y funciones. Además garantiza la confiabilidad de las transacciones, y está optimizado para manejar consultas complejas y grandes volúmenes de datos. Sin emabargo, al ser tan personalizable requiere más tiempo y esfuerzo para la configuración y mantenimineto. Siendo asi la base de datos mas compleja de manejo inicialmente. Por lo que podriamos solucionar este problema al crear nuestro propia base de datos controlada, personalizada y gestionada por nuestra empresa.

- MongoDB es una base de datos no relacional, por lo que es muy flexible y no requiere un esquema fijo. Está diseñado para trabajar con un gran volúmen de datos. También es muy rápido y se integra fácilmente con aplicaciones modernas. Lastimosamente suele necesitar niveles exagerados de memoria considerando la cantidad de datos introducidos.

- Redis es una base de datos extremadamente rápida, lo que la hace ideal para lectura y escritura. Soporta múltiples estructuras de datos como cadenas, listas y conjuntos. Sin embargo, está limitado por la cantidad de RAM disponible y sus estrucutras no son tan solidas. Además, es más utlizado para caché y almacenamiento temporal (RAM) de datos que para bases de datos a largo plazo.

## Justificación del Nuevo Desarrollo
Al ver diferentes opciones de bases de datos del mercado, encontramos que ninguna satisface nuestras rigidas demandas. Necesitamos una base de datos de confianza, que no este regulada por entidades internacionales, debido a que necesitamos almacenar datos confidenciales. Ninguna base de datos existente cumple todos nuestros requisitos simultáneamente. Por eso, justificamos crear una nueva base de datos que maneje eventos y fechas en tiempo real con características personalizadas del calendario, cumpliendo asi con los requisitos de seguridady privacidad de la empresa.


## Estructura del repositorio
El repositorio esta dividido en 4 documentos esenciales. El primero es la explicacion del proyecto, el README.md. El cual explciara a detalle el proyecto del repositorio designado. Los otros 3 documentos son parte del codigo fuente del proyecto el cual esta dividido a nivel modular. Primeramente tenemos el header.h, donde podras encontrar todas las bibliotecas y funciones usadas en el codigo. Despues podras encontrar el main.cpp, aqui podras encontrarlas llamdas de las diferentes funciones, ademas de la organizacion de entrada de datos de las funciones. Por ultimo esta el source.cpp, aqui veras como funciona las diferentes funciones del codigo analizando el cuerpo de cada una.

## Descripcion de las funciones, estructuras
- struct Fechas: La estructura contiene elementos de ano, mes y dia de tipo de dato entero para su uso a lo largo de todas las funciones. Almacenara los datos introducidos por el usuario en el main.
- void anadiendo_ceros_extra: Se anaden ceros extras para completar el formato de fecha AAAA-MM-DD e introducirlo a la base de datos. Se usa al principio de cada funcion de comando excepto la de Print. 
- void dividir_fecha: En el codigo, necesitaremos dividir la fecha (con tipo de dato string), que almacena el ano, mes y dia separados por un guion medio. Esta funcion extraera estos 3 datos en formato entero.
- void comando_add: La primera funcionalidad del programa, guarda un evento con una fecha en la base de datos. 
- void comando_del_evento: La segunda funcionalidad del programa, borra un evento especifico de una fecha especificada por el usuario.
- void comando_del_fecha: La tercera funcionalidad del programa, borra todos los eventos de una fecha especificada por el usuario.
- void comando_find: La cuarta funcionalidad busca todos los eventos de una fecha especifica y los imprime en orden ascendente.
- void comando_print: La ultima funcionalidad imprime todas las fechas en orden ascendente acompanadas por sus eventos en orden ascendente igualmente.
- void base_datos_principal: Es la funcion principal del codigo, aqui se decide cual de las 5 funcionalidades usar en base al comando introducido por el usuario.

## Diagrama de flujos
![Examen Final intro progra drawio](https://github.com/FernandoTerrazasLl/Evaluaci-n-Final-Intro-Progra/assets/159574670/d00077b8-ec90-4205-ace6-e626540df034)

El diagrama de flujo representa la logica fundamental del programa. En ella podemos ver todo el procesamiento de las diferentes entradas que demanda el programa (comando, fecha y eventos) y su trayecto a lo largo del programa. Incluso vemos las diferentes tomas de decisiones basadas en las funciones programadas del algoritmo las cuales fueron explicadas a detalle. A la derecha del diagrama de flujo podemos ver una ramificacion organizada especialmente para el proceso de entrada de datos. A la izquierda vemos el algoritmo disenado para obtener los resultados deseados. El proposito del diagrama de flujo es proporcionar un analisis logico rapido y eficaz del funcionamiento estructural del codigo disenado en el repositorio.  

## Creditos
El autor de este proyecto es:
- Fernando Terrazas Llanos
Estudiante de primer semestre de Ing. de Software de la Universidad Catolica Boliviana San Pablo.

Bajo la supervision y tutela de:
- Ing. Jose Jesus Cabrera Pantoja
Jefe de carrera de Ing. de Software de la Universidad Catolica Boliviana San Pablo. 

## Herramientas utilizadas
- Editor de texto utilizado en el transcurso del proyecto: Visual Studio Code
- Lenguaje programacion utilizado en todo el proyecto: c++
- Compilador incluido en Visual Studio Code: MinGW 
- Herramienta digital utilizada para el diseno del Diagrama de Flujo: draw.io
