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
Para la ejecucion del cliente, en la terminal se debe de ejecutar ./client PORT, siendo PORT el puerto en el cual se quiera conectar. Por ejemplo el 7777.
Una vez que se ejecute el siguiente comando, aparecerea un menu con dos opciones. "Unirse partida" y "Salir". La segunda opcion, claramente hara un cierre ordenado del programa. Y la primera mostrara cuatro opciones distintas. Las primeras tres represetan a los mapas iniciales del juego ( Small Dust, Big Aztec y Huge Inferno ). La ultima representa a todos los mapas que fueron creados por el editor por usuarios anteriores. Si esta opcion se presiona, en la terminal aparecera todos los nombres de todos los mapas creados con un numero ID distintivo, lo que se debe hacer para iniciar dicho mapa es ingresar el digito identificatorio en la terminal y el juego comenzara.

## Ejecución del servidor ##
Para la ejecucion del servidor, en la terminal se debe de ejecutar ./server HOST PORT, siendo HOST el servidor a conectarse. Por ejemplo localhost. Al igual que en el cliente, el PORT es el puerto al que se quiere conectar.
Para dejar de aceptar conexiones al servidor, debe ingresarse la letra 'q' la cual hara que el hilo aceptador deje de escuchar conexiones y esperara que todos los clientes terminen su tarea para cerrarse.

## Controles del juego ##
- **Movimiento del jugador: Usar las siguientes teclas**
   - Arriba: ↑ (Tecla UP)
   - Abajo: ↓ (Tecla DOWN)
   - Izquierda: ← (Tecla LEFT)
   - Derecha: → (Tecla RIGHT)
- **Movimiento de la vista**
   - Mouse
- **Ataque (disparo o acuchillada)**
   - Mouse: Click izquierdo.
- **Agarrar arma del suelo**  
   - Tecla q
- **Cambio de arma**  
   - Arma principal:  ( Tecla 1 )
   - Arma secundaria: ( Tecla 2 )

## Editor ##
Una vez iniciado el programa editor, aparecerá un menú con dos opciones: "Seleccionar mapa" y Salir. El segundo, obviamente, al presionarlo, realiza un cierre ordenado del programa. Y el restante, al presionarlo hace aparecer otras tres opciones con los tres tipos de mapa disponibles para este juego. 
Una vez que se seleccione un modo de mapa, aparecerá una nueva ventana en la cual se puede elegir el tamaño de mapa. Hay tres disponibles.
Finalmente, luego de seleccionar el tamaño del terreno a editar, en la esquina inferior derecha de la pantalla apareceran cinco opciones de tipos de parcelas para elegir y poner en el mapa. Según se vayan seleccionando estas aparecerán en la esquina inferior izquierda las parcelas que representan al tipo seleccionado y al mapa que se eligió anteriormente. Si se presiona cualquiera de estas, aparecerán marcadas como seleccionadas en el cuadrado blanco central que hay en la pantalla. 
Para comenzar con la edición del mapa lo único que hay que hacer es realizar "point and click" en las grillas que ya estan determinadas en el mapa. 
Hay dos aclaraciones importantes. Para asegurar el correcto funcionamiento del programa, deben ponerse 5 (cinco) soldados terroristas y 5 (cinco) soldados antiterroristas en cualquier parte del mapa. Estas posiciones de los soldados representaran las posiciones iniciales en las cuales los jugadores spawnean en la partida segun a que bando pertenezcan. Luego, es una recomendacion poner armas en el terreno de juego para que los jugadores puedan recogerlas y asi no quedarse sin balas.
Una vez finalizado el proceso de edición, hay que cerrar la ventana con la cruz de cierre en la esquina superior derecha, luego ir a la terminal y se le pedira un nombre de mapa, ingresarlo, presionar enter y automáticamente se generará un archivo .yaml que representará al mapa creado.
