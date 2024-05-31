#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "cliente.h"

stCliente cargaCliente()//Falta validacion de datos, y libreria de Domicilio
{
    int dni=0;
    stCliente cliente;
    //asignar id random a cliente
    //asignar nro random
    printf("\n Ingrese nombre del cliente:");
    fflush(stdin);
    gets(cliente.nombre);
    printf("\n Ingrese apellido del cliente:");
    fflush(stdin);
    gets(cliente.apellido);
    while(dni==0)
    {
    printf("\n Ingrese dni del cliente:");
    fflush(stdin);
    gets(cliente.dni);
    dni=validarDni(cliente.dni);
    if(dni==0)
    {
        printf("\n dni no valido\n");
        system("pause");
    }
    }
    printf("\n Ingrese email del cliente:");
    fflush(stdin);
    gets(cliente.email);
    printf("\n Ingrese Nro de telefono del cliente: ");
    fflush(stdin);
    gets(cliente.telefono);
    //cargaDomicilio(cliente);
    cliente.eliminado = 0;
    printf("\n Carga exitosa\n");
    system("pause");
    system("cls");
    return cliente;
}

int validarDni(char dni[])
{
    int flag=0;
    int cantCaract = strlen(dni);//evito abrir la funcion 2 veces
    flag=(cantCaract<9&&cantCaract>6);

    return flag;
}

void muestraCliente(stCliente cliente)
{
    char estado[10];
    printf("\n Nro de cliente:........ %d", cliente.nroCliente);
    printf("\n Nro de id:............. %d", cliente.id);
    printf("\n Nombre:................ %s", cliente.nombre);
    printf("\n Apellido:.............. %s", cliente.apellido);
    printf("\n Nro de telefono:....... %s", cliente.telefono);
    printf("\n Nro de DNI:............ %s", cliente.dni);
    printf("\n Email:................. %s", cliente.email);
    (cliente.eliminado==0)?strcpy(estado, "Activo"):strcpy(estado, "Eliminado");
    printf("\n Estado de cliente:..... %s", estado);

}

int validarEmail(char email[])
{
    char *ptr;
    char emailValidos[4][30];
    emailValidos[0]="@hotmail.com";
    emailValidos[1]="@gmail.com";
    emailValidos[2]="@yahoo.com";
    emailValidos[3]="@hotmail.com.ar";

    ptr = strchr(email, '@');
    while(flag==0 && i<5)
    {

    }


    return ptr;
}

