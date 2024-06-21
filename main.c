#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "mock.h"
#include "gotoxy.h"

#define AR_CLIENTES "clientes.dat"
#define AR_CUENTAS "cuentas.dat"

void menuPpal();


int main()
{
    srand(time(NULL));
    int pos=0;

    //getCliente2ArchivoRandom(AR_CLIENTES);
//    printf("Listado\n");
//    listadoClientes(AR_CLIENTES);
    menuPpal();




    return 0;
}


void menuPpal()
{
    color(6);
    int x;
    int y;
    getConsoleSize(&x, &y);//ancho y alto de consola
    x=x/2;
    y=0;//Centro de consola
    x=x-17;//Mitad de caracteres del titulo
    gotoxy(x,y);
    printf("Sistema Bancario ""Bicicleta Facil"" ");
    y++;
    gotoxy(x,y);
    printf("================================", x, y);
    y=y+2;
    gotoxy(x,y);
    printf("OPCION 1");
    y=y+2;
    gotoxy(x,y);
    printf("OPCION 2");
    y=y+2;
    gotoxy(x,y);
    printf("OPCION 3");
    y=y+2;
    gotoxy(x,y);
    printf("OPCION 4");
    printf("\n");
    printf("\n");
}
