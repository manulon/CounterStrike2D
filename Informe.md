
# CounterStrike2D
# Trabajo pratico Final 

Nombres: 
-Federico Burman
-Manuel Longo Elia
-Daniel Lovera

## Introducción

En este trabajo se desarrolló un juego multijugador. Para el desarrollo del juego se utilizaron los paradigmas de la programacion orientada a objetos y la programacion orientada a eventos. Para la comunicación entre los programas (client-servidor) se utilizo comunicación por Sockets bajo el protocolo TCP-IP.

## Estructura de Clases ## 

### Server ###
En el servidor principalmente se desarrollo toda la parte f��sica del juego, haciendo uso de la biblioteca externa Box2D. Se encuentra adem��s el protocolo de comunicaci��n del servidor con el cliente y las clases relacionadas con este. A continuaci��n se detallan las clases m��s importante en el desarrollo del juego.

**Entity**  
Es la clase que contiene los cuerpos reales en las colisiones de box2D. Todos los objetos f��sicos que deban participar en colisiones deberan heredar de esta clase e implementar los m��todos necesarios para controlar las colisiones (collideWith). Con esto los objetos del juego reaccionaran de manera diferente en cada colisi��n segun sea su tipo por polimorfismo, esto obligara a que por cada nueva clase heredada de Entity, sus clases hermanas debe implementar un nuevo comportamiento para esa colisi��n.

**World**  
El mundo fue creado para wrapear el mundo de box2D y agregar nuevas funcionalidades seg��n los nuevos requerimientos del juego. Contiene de atributos objetos que pueden perder su scope en el game, y se encarga de gestionar destrucci��n y creaci��n de nuevos objetos para evitar que sean destruidos al momento en que box2D esta haciendo calculos reales de colisiones.

**Game**
Esta es la clase en donde se encuentra la l��gica del juego y de comunicaci��n con el cliente a traves de colas protegidas. Para esto utiliza implementa m��todos que son utilizados por los hilos enviadores y receptores para transmitirle informaci��n al cliente.





  


