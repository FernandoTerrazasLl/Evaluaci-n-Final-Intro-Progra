# Base de Datos
Nuestra empresa necesita desarrollar una aplicación de calendario que maneje una base de datos extensa con millones de eventos, fechas y usuarios de la empresa. Por cuestiones de seguridad de nuestra informacion clasificada y privacida vemos necesario comenzar dicho proyecto.

Para desarrollar la base de datos necesitaremos:
- La base de datos debe manejar la creación, eliminacion y consulta de eventos en ciertas fechas en el menor tiempo posible.
- La base de datos debe tener una considerable capacidad de almacenamiento en el sistema.
- Debe ser capaz de recibir eventos y fechas personalizadas del calendario y almacenarlas como datos para contar con suficeinte seguridad y confianza.
- Debe ser capaz de encontrar datos especificos que estemos buscando entre todos los datos almacenados.

## Comparativa de Bases de Datos Existentes
- MySQL es una base de datos muy popular y ampliamente utilizada, lo que facilita encontrar soluciones a problemas y obtener soporte. Funciona en múltiples plataformas y es compatible con muchos lenguajes de programación. Sin embargo es menos flexible en comparación con las bases de datos NoSQL. Al ser tan popular, nos provee de una menor calidad de seguridad que una base de datos propia.

- PostgreSQL es muy extensible y permite crear tipos de datos personalizados y funciones. Además garantiza la confiabilidad de las transacciones, y está optimizado para manejar consultas complejas y grandes volúmenes de datos. Sin emabargo, al ser tan personalizable requiere más tiempo y esfuerzo para la configuración y mantenimineto. Por lo que podriamos solucionar este problema al crear nuestro propia base de datos controlada, personalizada y gestionada por nuestra empresa.

- MongoDB es una base de datos no relacional, por lo que es muy flexible y no requiere un esquema fijo. Está diseñado para trabajar con un gran volúmen de datos. También es muy rápido y se integra fácilmente con aplicaciones modernas. Lastimosamente suele necesitar niveles exagerados de memoria considerando la cantidad de datos introducidos.

- Redis es una base de datos extremadamente rápida, lo que lo hace ideal para lectura y escritura. Soporta múltiples estructuras de datos como cadenas, listas y conjuntos. Sin embargo, está limitado por la cantidad de RAM disponible y sus estrucutras no son tan solidas. Además, es más utlizado para caché y almacenamiento temporal (RAM) de datos que para bases de datos a largo plazo.

## Justificación del Nuevo Desarrollo
Al ver diferentes opciones de bases de datos del mercado, encontramos que ninguna satisface nuestras rigidas demandas. Necesitamos una base de datos de confianza, que no este regulada por entidades internacionales, debido a que necesitamos almacenar datos confidenciales. Ninguna base de datos existente cumple todos nuestros requisitos simultáneamente. Por eso, justificamos crear una nueva base de datos que maneje eventos y fechas en tiempo real con características personalizadas del calendario, cumpliendo asi con los requisitos de seguridad de la empresa.


## Estructura del repositorio
El repositorio esta dividido en 4 documentos esenciales. El primero es la explicacion del proyecto, el README.md. El cual explciara a detalle el proyecto del repositorio designado. Los otros 3 documentos son parte del codigo fuente del proyecto el cual esta dividido a nivel modular. Primeramente tenemos el header.h, donde podras encontrar todas las bibliotecas y funciones usadas en el codigo. Despues podras encontrar el main.cpp, aqui podras encontrarlas llamdas de las diferentes funciones, ademas de la organizacion de entrada de datos de las funciones. Por ultimo esta el source.cpp, aqui veras como funciona las diferentes funciones del codigo analizando el cuerpo de cada una.