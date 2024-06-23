#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "domicilio.h"
#include "cliente.h"
#include "mock.h"
#include "gotoxy.h"


#define AR_CLIENTES "clientes.dat"
#define AR_CUENTAS "cuentas.dat"

int menuPpal();
int menuCliente();
int menuBuscaCliente();
void opcionesCliente();


int selectOption(int cantOpciones);


int main()
{
    srand(time(NULL));

    int opcion;
    int fin=0;
    do
    {
        opcion=menuPpal();
        switch(opcion)
        {
        case 1://cliente
            opcionesCliente();

            break;
        case 2://cuenta

            break;
        case 3://salir
            fin=1;
            break;

        }
    }while(fin==0);





    return 0;
}


int menuPpal()
{
    system("cls");
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
    return op;
}



int selectOption(int cantOpciones)//Devuelve una opcion elegida
{
    char opcion;
    int elegido=1;
    int x;
    int y;
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


int menuCliente()
{
    system("cls");
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
    printf("Ver todos los clientes");
    y=y+2;
    gotoxy(x,y);
    printf("Ver clientes activos");
    y=y+2;
    gotoxy(x,y);
    printf("Ver clientes inactivos");
    y=y+2;
    gotoxy(x,y);
    printf("Buscar un cliente");
    y=y+2;
    gotoxy(x,y);
    printf("Cargar un cliente");
    y=y+2;
    gotoxy(x,y);
    printf("Cargar un cliente Random");
    y=y+2;
    gotoxy(x,y);
    printf("Volver");

    return selectOption(7);
}

void opcionesCliente()
{
    int opcion;
    int fin=0;
    char busqueda[20];
    int pos;
    char modifica=0;
    do
    {
        system("cls");
         opcion=menuCliente();
        switch(opcion)
        {
        case 1://Lista de cliente
            system("cls");
            listadoClientes(AR_CLIENTES);
            printf("\n");
            system("pause");
            break;
        case 2://Ver Clientes activos
            printf("Lista de clientes activos:\n");
            listadoClientesActivos(AR_CLIENTES);
            system("pause");
            break;
        case 3://Ver Clientes inactivos
            system("cls");
            printf("Lista de clientes inactivos:\n");
            listadoClientesInactivos(AR_CLIENTES);
            system("pause");
            break;
        case 4://Buscar Cliente
            system("cls");
            printf("\n Ingrese Dni de cliente para realizar la busqueda:\n");
            fflush(stdin);
            gets(busqueda);
            pos=buscaPosClientePorDni(AR_CLIENTES, busqueda);
            if(pos==-1)
            {
                printf("\n El dni ingresado no corresponde a ningun cliente del sistema\n");
            }else{
            printf("\n Cliente encontrado: \n");
            muestraClientePos(AR_CLIENTES,pos);
            printf("\n Para modificar el cliente presione enter. \n Para volver al menu anterior presione cualquier tecla\n");
            fflush(stdin);
            modifica=getch();
            if(modifica == 13)
            {
                reemplazaClientePos(AR_CLIENTES,modificarCliente(clientePos(AR_CLIENTES, pos)), pos);
                system("cls");
                printf("\n Cliente modificado con exito\n");

            }
            }
            system("pause");
            break;
        case 5://cargar Cliente
            system("cls");
            muestraCliente(cargaCliente(AR_CLIENTES));
            system("pause");
            break;
        case 6://cargar Cliente Random
            getCliente2ArchivoRandom(AR_CLIENTES);
            printf("\n Carga exitosa");
            break;
        case 7://salir
            fin=1;
            break;
        }
    }while(fin==0);
}


int menuBuscaCliente()
{
    system("cls");
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
    printf("Modificar datos de cliente");
    y=y+2;
    gotoxy(x,y);
    printf("Ver cuentas del cliente");
    y=y+2;
    gotoxy(x,y);
    printf("Dar alta cliente");
    y=y+2;
    gotoxy(x,y);
    printf("Dar baja cliente");
    y=y+2;
    gotoxy(x,y);
    printf("Volver");

    return selectOption(5);
}

void opcionesBuscaCliente()
{
    int fin=0;
    int opcion;
    do
    {
        system("cls");
         opcion=menuBuscaCliente();
        switch(opcion)
        {
        case 1://
            listadoClientes(AR_CLIENTES);
            printf("\n");
            system("pause");
            break;
        case 2://Ver Clientes activos
            printf("Lista de clientes activos:\n");
            listadoClientesActivos(AR_CLIENTES);
            system("pause");
            break;
        case 3://Ver Clientes inactivos
            system("cls");
            printf("Lista de clientes inactivos:\n");
            listadoClientesInactivos(AR_CLIENTES);
            system("pause");
            break;
        case 4://Buscar Cliente

            system("pause");
            break;
        case 5://salir
            fin=1;
            break;
        }
    }while(fin==0);
}
