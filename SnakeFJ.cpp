// SnakeFJ.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cstdio>
#include <Windows.h>

#include "Map.h"

using namespace std;



void posicion(int i, int j)
{

	COORD coord;
	coord.X = i;
	coord.Y = j;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void pintar() {
	//Lineas horizontales
	for (int i = 2; i < 194; i++) {
		posicion(i, 3); printf("%c", 205);
		posicion(i, 50); printf("%c", 205);
	}

	//Lineas verticales
	for (int i = 4; i < 50; i++) {
		posicion(2, i); printf("%c", 186);
		posicion(193, i); printf("%c", 186);
	}

	//Esquinas
	posicion(2, 3); printf("%c", 201);
	posicion(2, 50); printf("%c", 200);
	posicion(193, 3); printf("%c", 187);
	posicion(193, 50); printf("%c", 188);
}

void titulo() {

	fflush(stdin);
	posicion(60, 9); cout << "      ::::::::  ::::    :::     :::     :::    ::: :::::::::: "; Sleep(100);
	posicion(60, 10); cout << "    :+:    :+: :+:+:   :+:   :+: :+:   :+:   :+:  :+:         "; Sleep(100);
	posicion(60, 11); cout << "   +:+        :+:+:+  +:+  +:+   +:+  +:+  +:+   +:+          "; Sleep(100);
	posicion(60, 12); cout << "  +#++:++#++ +#+ +:+ +#+ +#++:++#++: +#++:++    +#++:++#      "; Sleep(100);
	posicion(60, 13); cout << "        +#+ +#+  +#+#+# +#+     +#+ +#+  +#+   +#+            "; Sleep(100);
	posicion(60, 14); cout << "#+#    #+# #+#   #+#+# #+#     #+# #+#   #+#  #+#             "; Sleep(100);
	posicion(60, 15); cout << "########  ###    #### ###     ### ###    ### ##########       "; Sleep(100);

	posicion(60, 25); cout << "                   ~*************O       \n"; Sleep(100);
	posicion(60, 26); cout << "         WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW\n"; Sleep(100);

	posicion(90, 33); cout << "~~BIENVENIDO~~\n";
	posicion(87, 34); printf("%c", 254);
	posicion(89, 34); cout << "ENTER PARA INICIAR\n";
	system("pause>null");
}

void cargando() {
	//Pausar actividad y ante un tecleo limpiar pantalla/	
	system("pause");
	system("cls");

	int x, y, a;

	posicion(65, 18);     cout << "Cargando...0%\n";
	for (x = 80; x <= 120; x++)
	{
		posicion(x, 18);
		printf("%c", 219);
		Sleep(6);
	}

	for (y = 18; y <= 28; y++)
	{
		posicion(120, y);
		printf("%c", 219);
		Sleep(6);
	}

	for (x = 120; x >= 80; x--)
	{
		posicion(x, 28);
		printf("%c", 219);
		Sleep(6);
	}

	for (y = 28; y >= 20; y--)
	{
		posicion(80, y);
		printf("%c", 219);
		Sleep(6);
	}

	//2 vuelta 
	for (x = 80; x <= 118; x++)
	{
		posicion(x, 20);
		printf("%c", 219);
		Sleep(6);
	}

	for (y = 20; y <= 26; y++)
	{
		posicion(118, y);
		printf("%c", 219);
		Sleep(6);
	}

	for (x = 118; x >= 82; x--)
	{
		posicion(x, 26);
		printf("%c", 219);
		Sleep(6);
	}

	for (y = 26; y >= 23; y--)
	{
		posicion(82, y);
		printf("%c", 219);
		Sleep(6);
	}

	for (x = 82; x <= 98; x++)
	{
		posicion(x, 23);
		printf("%c", 219);
		Sleep(6);
		cout << "...100% Completado";

	}
}

void GameOver() {
	system("cls");
	fflush(stdin);
	posicion(60, 10); cout << "      ::::::::      :::       :::   :::   ::::::::::          ::::::::  :::     ::: :::::::::: ::::::::: "; Sleep(100);
	posicion(60, 11); cout << "    :+:    :+:   :+: :+:    :+:+: :+:+:  :+:                :+:    :+: :+:     :+: :+:        :+:    :+: "; Sleep(100);
	posicion(60, 12); cout << "   +:+         +:+   +:+  +:+ +:+:+ +:+ +:+                +:+    +:+ +:+     +:+ +:+        +:+    +:+  "; Sleep(100);
	posicion(60, 13); cout << "  :#:        +#++:++#++: +#+  +:+  +#+ +#++:++#           +#+    +:+ +#+     +:+ +#++:++#   +#++:++#:    "; Sleep(100);
	posicion(60, 14); cout << " +#+   +#+# +#+     +#+ +#+       +#+ +#+                +#+    +#+  +#+   +#+  +#+        +#+    +#+    "; Sleep(100);
	posicion(60, 15); cout << "#+#    #+# #+#     #+# #+#       #+# #+#                #+#    #+#   #+#+#+#   #+#        #+#    #+#     "; Sleep(100);
	posicion(60, 16); cout << "########  ###     ### ###       ### ##########          ########      ###     ########## ###    ###      "; Sleep(100);

	posicion(60, 22); cout << "Presione cualquier tecla para salir...";
	//_getch();

}


int main()
{

	Map mapa;

	system("color 02");
	cout << "Primero deberas poner tu terminal en pantalla completa, presiona cualquier tecla cuando ya la hayas puesto asi...";
	_getch();
	fflush(stdin);
	pintar();




	titulo();
	system("pause>null");
	//	fflush(stdin);
	pintar();
	cargando();
	system("pause>null");
	system("cls");
	pintar();
	posicion(50, 10); printf("%c", 223);	cout << " BIENVENIDO A NUESTRO JUEGO SNAKE\n";
	posicion(50, 11); printf("%c", 223);  cout << " SIGUE CORRECTAMENTE LOS SIGUIENTES PASOS Y DISFRUTA DEL JUEGO.";
	posicion(50, 15); printf("%c", 223);  cout << " INSTRUCCIONES: La mision es aumentar lo mayor posible el tamaño de la serpiente.";
	posicion(50, 16); printf("%c", 254);  cout << " - Si comes una manzana, se aumenta una unidad el tamaño de la serpiente.\n";
	posicion(50, 17); printf("%c", 254);  cout << " - Si comes una pera, se aumenta dos unidades el tamaño de la serpiente.\n";
	posicion(50, 18); printf("%c", 254);  cout << " - El juego termina cuando la serpiente colisione con alguna barrera o consigo misma.\n\n";


	system("cls");
	pintar();
	posicion(95, 10); cout << " QUE COMIENCE EL JUEGO\n\n";
	posicion(95, 11); cout << " Presiona 'w' para deslizarte hacia arriba";
	posicion(95, 12); cout << " Presiona 's' para deslizarte hacia abajo";
	posicion(95, 13); cout << " Presiona 'a' para deslizarte hacia la izquierda";
	posicion(95, 14); cout << " Presiona 'd' para deslizarte hacia la derecha";
	posicion(95, 15); cout << " Presiona 'x' para terminar el juego";
	posicion(95, 17); cout << " Presiona cualquier tecla para continuar...";
	_getch();

	system("color A0");

	fflush(stdin);


	while (!mapa.getGameOver()) {
		mapa.drawMap();
		mapa.sk.getMove();
		mapa.sk.applyMovement();
		mapa.setGameOver(mapa.sk.getMGO());
		Sleep(50);
	}
	mapa.setScore(mapa.sk.getLength());
	

	GameOver();
	posicion(95, 19); cout << "Tu puntuacion final fue: " << mapa.getScore();
	system("pause>NULL");
	fflush(stdin);
	






}
