# CounterStrike2D
# Trabajo pratico Final 

Nombres: 
-Federico Burman
-Manuel Longo Elia
-Daniel Lovera




## Introducción

En este trabajo se desarrolló un juego multijugador. Para el desarrollo del juego se utilizaron los paradigmas de la programacion orientada a objetos y la programacion orientada a eventos. Para la comunicación entre los programas (client-servidor) se utilizo comunicación por Sockets bajo el protocolo TCP-IP.

## Estructura de Clases
### Server

### Cliente

El programa del cliente cuenta con una clase ```Client``` que tiene un unico método público que corre el programa, en este método se llama al metodo privado ```gameLoop``` lleva a cabo la actualización del modelo y el renderizado del mismo.

Es en ese método que se spawnean 2 hilos, un hilo recibidor y un hilo enviador. De esta forma, el hilo principal no se bloquea al enviar y recibir informacion y puede renderizar el modelo sin problema.

Para la comunicacion entre hilos se utilizaron colas para evitar cualquier tipo de race conditions. La clase  ```Client``` tiene como atributo una cola bloqueante la cual el hilo enviador hace "pop" para enviar al servidor, y una cola no bloqueante llenada por el hilo recibidor que en cada iteracion del ```gameLoop``` se vacía. 

La cola Bloqueante es una cola de ```ClientMessage```, una clase abstracta que tiene el metodo abstracto send, que hace que cada tipo de mensaje que envia el cliente hacia el servidor sepa como mandarse.

La cola no bloqueante esta compuesta por objetos de la clase abstracta ```Info``` que contiene siempre información que llega desde el servidor. Tiene el método ```handle``` abstracto que recibe como parametro una referencia del TileMap y dependiendo del tipo de informacion que llega llama a un metodo diferente del TileMap.

El modelo del juego en el cliente esta en la clase TileMap. Esta clase se encarga de almacenar todos los objetos del juego con su informacion y tambien de renderizarlos.
Los objetos renderizables (personajes, armas, balas) heredan de la clase DynamicObject que tiene el metodo que renderiza al objeto en el lugar de la pantalla acorde a posicion del jugador del cliente.



# Cosas que faltaron

El tiempo fue la principal razón por la que no pudimos desarrollar todos los puntos pedidos en el enunciado por lo que hay bastantes features que nos faltaron implementar.
Algunos de ellos son:
-Sonidos en el juego, música de fondo, y sonidos acordes a los eventos(disparos, heridas,apuñaladas).
-Modo pantalla completa. La versión actual esta hecha sobre una pantalla de 800x600.
-Bombas.
-Diferentes tipos de armas, con diferentes daños.
-El renderizado de la cantidad de balas que tiene cada jugador.
-Tienda de armas. 
-Multiples partidas