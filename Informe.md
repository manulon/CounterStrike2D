
# CounterStrike2D
# Trabajo pratico Final 

Nombres: 
-Federico Burman
-Manuel Longo Elia
-Daniel Lovera

## Introducci贸n

En este trabajo se desarroll贸 un juego multijugador. Para el desarrollo del juego se utilizaron los paradigmas de la programacion orientada a objetos y la programacion orientada a eventos. Para la comunicaci贸n entre los programas (client-servidor) se utilizo comunicaci贸n por Sockets bajo el protocolo TCP-IP.

## Estructura de Clases ## 

### Server ###
En el servidor principalmente se desarrollo toda la parte física del juego, haciendo uso de la biblioteca externa Box2D. Se encuentra además el protocolo de comunicación del servidor con el cliente y las clases relacionadas con este. A continuación se detallan las clases más importante en el desarrollo del juego.

**Entity**  
Es la clase que contiene los cuerpos reales en las colisiones de box2D. Todos los objetos físicos que deban participar en colisiones deberan heredar de esta clase e implementar los métodos necesarios para controlar las colisiones (collideWith). Con esto los objetos del juego reaccionaran de manera diferente en cada colisión segun sea su tipo por polimorfismo, esto obligara a que por cada nueva clase heredada de Entity, sus clases hermanas debe implementar un nuevo comportamiento para esa colisión.

**World**  
El mundo fue creado para wrapear el mundo de box2D y agregar nuevas funcionalidades según los nuevos requerimientos del juego. Contiene de atributos objetos que pueden perder su scope en el game, y se encarga de gestionar destrucción y creación de nuevos objetos para evitar que sean destruidos al momento en que box2D esta haciendo calculos reales de colisiones.

**Game**
Esta es la clase en donde se encuentra la lógica del juego y de comunicación con el cliente a traves de colas protegidas. Para esto utiliza implementa métodos que son utilizados por los hilos enviadores y receptores para transmitirle información al cliente.





  


