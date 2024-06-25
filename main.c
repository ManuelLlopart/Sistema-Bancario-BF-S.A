#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "domicilio.h"
#include "cliente.h"
#include "mock.h"
#include "gotoxy.h"
#include "cuenta.h"
#include "movimientos.h"

#define AR_CLIENTES "clientes.dat"
#define AR_CUENTAS "cuentas.dat"
#define AR_MOVIMIENTOS "movimientos.dat"


int menuPpal();
int menuCliente();
void opcionesCliente();
int menuBuscaCliente();
void opcionesBuscaCliente(int pos);
int menuCuenta();
void opcionesCuenta();
int menuCuentaElegida();
void opcionesCuentaElegida(stCuenta cuenta);

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
            opcionesCuenta();
            break;
        case 3://movimiento
            opcionesMovimientos();
            break;
        case 4://salir
            fin=1;
            break;

        }
    }
    while(fin==0);





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
    printf("Clientes");
    y=y+2;
    gotoxy(x,y);
    printf("Cuentas");
    y=y+2;
    gotoxy(x,y);
    printf("Movimientos");
    y=y+2;
    gotoxy(x,y);
    printf("Salir");
    op=selectOption(4);
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
            if(y>3)
            {
                y=y-2;
                gotoxy(x,y);
                printf("");
                elegido--;
            }
            else
            {
                y=1+cantOpciones*2;
                gotoxy(x,y);
                printf("");
                elegido=cantOpciones;
            }

            break;
        case 80://abajo
            if(y<cantOpciones*2)
            {
                y=y+2;
                gotoxy(x,y);
                printf("");
                elegido++;
            }
            else
            {
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
    }
    while(fin==0);
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
                system("pause");
            }
            else
            {
                printf("\n Cliente encontrado: \n");
                muestraClientePos(AR_CLIENTES,pos);
                opcionesBuscaCliente(pos);
            }

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
    }
    while(fin==0);
}


int menuBuscaCliente()
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
    printf("Modificar datos de cliente");
    y=y+2;
    gotoxy(x,y);
    printf("Ver cuentas del cliente");
    y=y+2;
    gotoxy(x,y);
    printf("Seleccionar cuenta");
    y=y+2;
    gotoxy(x,y);
    printf("Crear Cuenta");
    y=y+2;
    gotoxy(x,y);
    printf("Volver");

    return selectOption(5);
}

void opcionesBuscaCliente(int pos)
{
    int fin=0;
    int opcion;
    int numCuentas=0;
    int elegido;
    int flag=0;
    stCliente cliente=clientePos(AR_CLIENTES, pos);
    stCuenta cuenta;
    do
    {
        system("cls");
        gotoxy(0, 10);
        printf("\n Cliente encontrado: \n");
        muestraCliente(cliente);
        opcion=menuBuscaCliente();
        numCuentas=cantidadCuentasCliente(AR_CUENTAS, cliente.id);//que no muestre los clientes
        switch(opcion)
        {
        case 1://Modificar
            system("cls");
            reemplazaClientePos(AR_CLIENTES,modificarCliente(clientePos(AR_CLIENTES, pos)), pos);
            system("cls");
            printf("\n Cliente modificado con exito\n");
            break;
        case 2://Ver Cuentas del cliente
            system("cls");
            listadoCuentasPorCliente(AR_CUENTAS, cliente.id);//que no devuelva nada
            printf("\nEl cliente tiene %d cuentas\n", numCuentas);
            system("pause");
            break;
        case 3://Seleccionar cuenta
            if(numCuentas>0)
            {
            do
            {
                system("cls");
                printf("\nIngrese el numero de cuenta a seleccionar\n");
                scanf("%d", &elegido);
                if(elegido<=numCuentas&&elegido>=1)
                {
                    flag=1;

                }else{
                printf("\n Error, la cuenta seleccionada no existe, intente nuevamente\n");
                system("pause");
                    }
            }while(flag==0);
            cuenta=buscaCuentaPorIdClienteNroCuenta(AR_CUENTAS,cliente.id, elegido); //funcion que devuelve cuenta buscada por idCliente y nro de cuenta
            opcionesCuentaElegida(cuenta);
            //Modificar cuenta
            //dar de baja
            //dar de alta
            //Menu para movimientos
            //Ver movimientos
            //crear un movimiento
            //crear movimiento random
            printf("\n");
            system("pause");
            }else{
            printf("\nEl cliente no posee ninguna cuenta\n");
            }
            break;
        case 4://Cargar Cuenta
            system("cls");
            cargaCuenta(AR_CUENTAS, cliente);
            system("pause");
            break;
        case 5://salir
            fin=1;
            break;
        }
    }
    while(fin==0);
}

int menuCuenta()
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
    printf("Ver todas las cuentas");
    y=y+2;
    gotoxy(x,y);
    printf("Ver las cuentas activas");
    y=y+2;
    gotoxy(x,y);
    printf("Ver las cuentas inactivas");
    y=y+2;
    gotoxy(x,y);
    printf("Salir");

    return selectOption(4);

}
void opcionesCuenta()
{
    int fin=0;
    int opcion;
    int cant=0;
    do
    {
        system("cls");
        opcion=menuCuenta();
        switch(opcion)
        {
        case 1://Ver todas las cuentas
            system("cls");
            muestraArchivoCuentas(AR_CUENTAS);
            printf("\n");
            system("pause");
            break;
        case 2://Ver las cuentas activas
            system("cls");
            cant=mostrarTodasLasCuentasActivas(AR_CUENTAS);
            printf("\n Hay %d cuentas activas\n", cant);
            system("pause");
            break;
        case 3://Ver las cuentas inactivas
            system("cls");
            cant=mostrarTodasLasCuentasInactivas(AR_CUENTAS);
            printf("\n Hay %d cuentas activas\n", cant);
            system("pause");
            break;

        case 4://salir
            fin=1;
            break;
        }
    }
    while(fin==0);
}

int menuMovimiento()
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
    printf("Ver todos los movimientos");
    y=y+2;
    gotoxy(x,y);
    printf("Cargar mil movimientos random");
    y=y+2;
    gotoxy(x,y);
    printf("Buscar movimiento por fecha");
    y=y+2;
    gotoxy(x,y);
    printf("Salir");

    return selectOption(4);

}
void opcionesMovimientos()
{
    stMovimientos mov;
    int opcion;
    int fin=0;
    do
    {
        opcion=menuMovimiento();
        switch(opcion)
        {
        case 1://Ver todos los mov
            system("cls");
            muestraVariosMovimientos(AR_MOVIMIENTOS);
            system("pause");
            break;
        case 2://cargar mil mov
            system("cls");
            cargaMilMovimientosRandomEnArchi(AR_MOVIMIENTOS,AR_CUENTAS);
            printf("\nSe cargaron mil movimientos\n");
            system("pause");
            break;
        case 3:
            system("cls");
            mov=cargaFechaMovimiento(mov);
            printf("Movimientos correspondientes al dia %d/%d/%d:\n",mov.dia,mov.mes,mov.anio);
            buscaMovimientosPorFecha(AR_MOVIMIENTOS,mov.dia,mov.mes,mov.anio);
            system("pause");
            break;
        case 4://salir
            fin=1;
            break;

        }
    }
    while(fin==0);



}

int menuCuentaElegida()
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
    printf("Modificar cuenta");
    y=y+2;
    gotoxy(x,y);
    printf("Dar de baja a la cuenta");
    y=y+2;
    gotoxy(x,y);
    printf("Dar de alta a la cuenta");
    y=y+2;
    gotoxy(x,y);
    printf("Ver movimientos");
    y=y+2;
    gotoxy(x,y);
    printf("Crear movimiento");
    y=y+2;
    gotoxy(x,y);
    printf("Crear movimiento random");
    y=y+2;
    gotoxy(x,y);
    printf("Dar de alta un movimiento");
    y=y+2;
    gotoxy(x,y);
    printf("Dar de baja un movimiento");
    y=y+2;
    gotoxy(x,y);
    printf("Modificar movimiento");
    y=y+2;
    gotoxy(x,y);
    printf("Volver");

    return selectOption(10);
}

void opcionesCuentaElegida(stCuenta cuenta)
{
    int idMovAModificar=0;
    int posMov=0;
    float importeMov=0;
    char detalleMov[50];
    int fin=0;
    int opcion;
    int pos;
    int idMov;
    stMovimientos mov;
    int cant=0;
    int cantMov=0;
    pos=buscaPosCuentaPorId(AR_CUENTAS,cuenta.idCliente, cuenta.nroCuenta);
    do
    {
        system("cls");
        gotoxy(0,18);
        printf("\nCuenta seleccionada:\n");
        mostrarCuentaIndividual(cuentaPos(AR_CUENTAS,pos));
        opcion=menuCuentaElegida();
        switch(opcion)
        {
        case 1://Modificar cuenta
            system("cls");
            cuenta=modificaPorSeccion(cuenta);
            reemplazaCuentaPos(AR_CUENTAS, cuenta, pos);
            system("pause");
            break;
        case 2://dar de baja
            system("cls");
            cuenta=bajaCuenta(cuenta);
            reemplazaCuentaPos(AR_CUENTAS, cuenta, pos);
            printf("\nCuenta dada de baja exitosamente\n");
            system("pause");
            break;
        case 3://dar de alta
            system("cls");
            cuenta=altaCuenta(cuenta);
            reemplazaCuentaPos(AR_CUENTAS, cuenta, pos);
            printf("\nCuenta dada de alta exitosamente\n");
            system("pause");
            break;
        case 4://Ver movimientos
            system("cls");
            listadoMovimientosPorIdCuenta(AR_MOVIMIENTOS, cuenta.id);
            printf("\n");
            system("pause");
            break;
        case 5://crear movimiento
            system("cls");
            mov=crearMovimiento(cuenta.id);
            guardaMovimientoEnArchi(AR_MOVIMIENTOS, mov);
            muestraMovimiento(mov);
            actualizarSaldo2(AR_CUENTAS,mov);
            printf("\nMovimiento cargado correctamente\n");
            system("pause");
            break;
        case 6://Crear movimiento random
            system("cls");
            cant=cargaMovimientosRandomEnArchi(AR_MOVIMIENTOS,AR_CUENTAS,cuenta.id);
            printf("\n Se cargaron %d movimientos\n", cant);
            break;
        case 7://dar alta movimiento
            system("cls");
            printf("\nIngrese el id del movimiento que quiere eliminar\n");
            scanf("%d", &idMov);
            if(idMov<=cuentaRegistros(AR_MOVIMIENTOS, sizeof(stMovimientos)))
            {
                 mov=altaMovimiento(AR_MOVIMIENTOS, idMov, cuenta.id);
            }else
            {
                printf("\nEl id ingresado no existe\n");
            }
            system("pause");
            break;
        case 8://dar baja movimiento
            system("cls");
            printf("\nIngrese el id del movimiento que quiere dar de alta\n");
            scanf("%d", &idMov);
            if(idMov<=cuentaRegistros(AR_MOVIMIENTOS, sizeof(stMovimientos)))
            {
                 mov=eliminaMovimiento(AR_MOVIMIENTOS, idMov, cuenta.id);
            }else
            {
                printf("\nEl id ingresado no existe\n");
            }
            system("pause");
            break;
        case 9://Modifica movimiento
            system("cls");
            printf("\nIngrese el id del movimiento a modificar:");
            scanf("%d",&idMovAModificar);
            posMov=posMovimiento(AR_MOVIMIENTOS, cuenta.id, idMovAModificar);
            if (posMov==-1)
                {
                    printf("El id ingresado es incorrecto. Intente nuevamente..\n");
                }
                else
                {
                    printf("\nIngrese el detalle del movimiento a modificar: ");
                    fflush(stdin);
                    gets(detalleMov);
                    printf("Ingrese el importe del movimiento a modificar:");
                    fflush(stdin);
                    scanf("%f",&importeMov);
                    mov=fechaActualModificacionMov(mov);
                    mov=modificaMovimiento(AR_MOVIMIENTOS,posMov,detalleMov,importeMov,mov.dia,mov.mes,mov.anio);
                    muestraMovimiento(mov);
                }

            break;
        case 10://salir
            fin=1;
            break;
        }
    }
    while(fin==0);
}
