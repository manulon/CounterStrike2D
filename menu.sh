#!/bin/bash

function ejecutar_menu() {
	echo -e "Menu de instalacion.\n"
	echo -e "\t1. Instalar dependencias."
	echo -e "\t2. Instalar Counter-Strike2D."
	echo -e "\t3. Desinstalar Counter-Strike2D."
}

function controlar_entrada() {
	read -p "Ingrese un numero con la opcion a ejecutar: " opcion
	if [ $opcion -eq 1 ] 
	then
		instalar_dependencias
	elif [ $opcion -eq 2 ]
	then
		instalar_counter_strike
	elif [ $opcion -eq 3 ]
	then
		desinstalar_counter_strike
	else
		echo -e "\e[0;31mOpcion inválida.\e[0m"
	fi
}

function instalar_dependencias() {
	echo -e "\e[1;33m\nInstalando dependencias... \e[0m"
	instalar_dependencias_cmake
	instalar_dependencias_sdl
	instalar_dependencias_box2d
	echo -e "\e[0;32mInstalacion de dependencias completada\e[0m"
}

function instalar_dependencias_cmake() {
	echo -e "\e[0;32m\nInstalando biblioteca de CMake...\e[0m"
	sudo apt-get install cmake
}

function instalar_dependencias_sdl() {
	echo -e "\e[0;32m\nInstalando biblioteca Sdl...\e[0m"
	sudo apt-get install libsdl2-dev
	echo -e "\e[0;32mInstalando biblioteca Sdl-Mixer ...\e[0m"
	sudo apt-get install libsdl2-mixer-dev
	echo -e "\e[0;32mInstalando biblioteca Sdl-TTF ...\e[0m"
	sudo apt-get install libsdl2-ttf-dev
}

function instalar_dependencias_box2d() {
	echo -e "\e[0;32m\nInstalando biblioteca de Box2D ...\e[0m"
	sudo apt-get install libbox2d-dev
}

function instalar_counter_strike() {
	if [ ! -d "build" ]
	then	
		echo -e "\e[1;33m\nInstalado Counter-Strike2D... \e[0m"
		mkdir build
		cd build
		cmake ..
		cmake --build .
		echo -e "\e[0;32mInstalacion completada.\e[0m"
	else 
		echo -e "\e[1;33m\nEl juego ya se encuentra instalado."
		echo -n "En caso de existencia de daños en la instalacion, "
		echo -e "proceda a desinstalar y volver a instalar.\e[0m"
	fi
}

function desinstalar_counter_strike() {
	if [ -d "build" ]
	then 
		echo -n -e "\e[1;33m\nDesinstalado Counter-Strike2D... \e[0m"
		rm -rf "build"
		echo -e "\e[0;32mCompletado.\e[0m"

	else 
		echo -e "\e[1;33mEl juego ya se encuentra desinstalado. \e[0m"
	fi
}

function init() {
	ejecutar_menu
	controlar_entrada
}

init
