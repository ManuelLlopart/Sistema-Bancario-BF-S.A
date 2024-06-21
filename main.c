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
int selectOption(int cantOpciones);


int main()
{
    srand(time(NULL));

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
    int op;
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
    printf("CLIENTES");
    y=y+2;
    gotoxy(x,y);
    printf("CUENTAS");
    y=y+2;
    gotoxy(x,y);
    printf("SALIR");
    op=selectOption(3);
    printf("\n La opcion es %d", op);
}

int selectMenuPpal()
{
    int opcion=0;
    int x;
    int y;

    getConsoleSize(&x, &y);
    y=3;
    x=x-18;
    gotoxy(x,y);

//    do
//    {
//        switch(opcion)
//        {
//
//        }
//    }while();


    return opcion;
}

int selectOption(int cantOpciones)
{
    char opcion;
    int elegido=1;
    int x;
    int y;
    char c = '.';
    int fin=0;
    getConsoleSize(&x, &y);
    y=3;
    x=(x/2)-18;
    gotoxy(x,y);
    do
    {
        opcion=getch();
        switch(opcion)
        {
        case 72://arriba
            if(y>3){
                    y=y-2;
                    gotoxy(x,y);
                    printf("");
                    elegido--;
                }else{
                    y=1+cantOpciones*2;
                    gotoxy(x,y);
                    printf("");
                    elegido=cantOpciones;
                }

                break;
        case 80://abajo
            if(y<cantOpciones*2){
                    y=y+2;
                    gotoxy(x,y);
                    printf("");
                    elegido++;
                }else{
                    y=3;
                    gotoxy(x,y);
                    printf("");
                    elegido=1;
                }
            break;
        case 13:
            fin=1;
            break;

        }
    }while(fin==0);
    return elegido;
}
