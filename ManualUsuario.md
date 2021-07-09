# Manual de usuario #

## Requerimientos ##  

1. **Sistema operativo**  
Se debe utilizar un sistema operativo derivados de UNIX. Por ejemplo: Ubuntu.

2. **Dependencias**  
Se deberan instalar las siguientes aplicaciones para moder compilar el proyecto, el interprete de comandos
del sistema operativo e ingrese los siguientes comandos de cada dependencia.
   - **SDL**  
      - sudo apt-get install libsdl2-dev
      - sudo apt-get install libsdl2-image-dev
      - sudo apt-get install libsdl2-mixer-dev
      - sudo apt-get install libsdl2-ttf-dev
   - **Box2D**
      - sudo apt-get install libbox2d-dev
   - **Yaml**
      - sudo apt-get install libyaml-cpp-dev
   - **CMake**
      - sudo apt-get install cmake

## Descarga ##
**Opción 1**
1. Hacer click en la pestaña code.
2. Descargar el zip.
3. Descomprimir el zip.

**Opción 2**
1. Abra el intérprete de línea de comandos del sistema operativo.
2. Dirigirse hacia un directorio en donde se quieran descargar los archivos del repositorio.
3. Ingrese el comando git clone https://github.com/manulon/CounterStrike2D.git para descargar el proyecto.

## Compilación ##
En el directorio en que se encuentra la descarga del proyecto ejecutar los siguientes comandos:
1. mkdir build
2. cd build
3. cmake ..
4. cmake --build .

## Configuraciones adicionales ##
No hay.

## Ejecución del cliente ##
Falta implementacion
## Ejecución del servidor ##
Falta implementacion

## Controles del juego ##
- **Movimiento del jugador: Usar las siguientes teclas**
   - Arriba: ↑ (Tecla UP)
   - Abajo: ↓ (Tecla DOWN)
   - Izquierda: ← (Tecla LEFT)
   - Derecha: → (Tecla RIGHT)
- **Movimiento de la vista**
   - Mouse
- **Disparo:**
   - Mouse: Click izquierdo.
## Editor ##
Una vez iniciado el programa editor, aparecerá un menú con dos opciones: "Seleccionar mapa" y Salir. El segundo, obviamente, al presionarlo, realiza un cierre ordenado del programa. Y el restante, al presionarlo hace aparecer otras tres opciones con los tres tipos de mapa disponibles para este juego. 
Una vez que se seleccione un modo de mapa, aparecerá una nueva ventana en la cual se puede elegir el tamaño de mapa. Hay tres disponibles.
Finalmente, luego de seleccionar el tamaño del terreno a editar, en la esquina inferior derecha de la pantalla apareceran cinco opciones de tipos de parcelas para elegir y poner en el mapa. Según se vayan seleccionando estas aparecerán en la esquina inferior izquierda las parcelas que representan al tipo seleccionado y al mapa que se eligió anteriormente. Si se presiona cualquiera de estas, aparecerán marcadas como seleccionadas en el cuadrado blanco central que hay en la pantalla. 
Para comenzar con la edición del mapa lo único que hay que hacer es realizar "point and click" en las grillas que ya estan determinadas en el mapa. Una vez finalizado el proceso de edición, hay que cerrar la ventana con la cruz de cierre en la esquina superior derecha y automáticamente se generará un archivo .yaml que representará al mapa creado.


