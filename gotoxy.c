#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void color(int x){                                                              /// Cambia la combinacion de color de fondo y frente
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
}

void gotoxy(int X,int Y){                                                       /// Cambia las coordenadas del cursor
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X=X;
      dwPos.Y=Y;
      SetConsoleCursorPosition(hcon,dwPos);
}

int whereX(){                                                                     /// Devuelve la posicion de X
    CONSOLE_SCREEN_BUFFER_INFO sbi;
    GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &sbi);
    return sbi.dwCursorPosition.X;
}

int whereY(){                                                                   /// Devuelve la posicion de Y
    CONSOLE_SCREEN_BUFFER_INFO sbi;
    GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &sbi);
    return sbi.dwCursorPosition.Y;
}

void hidecursor(int ver){                                                       /// funcion para mostrar o esconder el cursor
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 1;
   info.bVisible = ver;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void getConsoleSize(int* width, int* height) {                                   ///funcion para obtener el tamaño de la consola
    CONSOLE_SCREEN_BUFFER_INFO csbi; // Estructura para almacenar la información de la consola
    // Obtener la información del búfer de la consola
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    // Calcular el ancho de la consola
    *width = csbi.srWindow.Right - csbi.srWindow.Left + 1;//le suma 1 para no contar el cero

    // Calcular el alto de la consola
    *height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1; //el csbi.srWindow nos indica la posicion dependiendo que le pongamos, bottom por ej es la parte mas baja de la consola

}
