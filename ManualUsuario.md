# Manual de usuario #

## Requerimientos ##  

1. **Sistema operativo**  
Se debe utilizar un sistema operativo derivador de UNIX. Por ejemplo: Ubuntu.

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
TODO: ¿ Hay ?

## Ejecución del cliente ##
TODO: Aun no esta la aplicacion cliente. ¿Que colocamos?

## Ejecución del servidor ##
TODO: Aun no esta la aplicacion servidor. ¿Que colocamos?

## Controles del juego ##
TODO: Las teclas seria mas comodo awsd (discutirlo)
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
TODO: Explicar.


