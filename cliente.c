#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "cliente.h"
#include "mock.h"

stCliente cargaCliente(char nombreArchivo[])//Falta  libreria de Domicilio
{
    int dni=0;
    int email=0;
    stCliente cliente;

    FILE* archi= fopen(nombreArchivo, "ab");
    if(archi)
    {

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
        system("cls");
    }
    }
    while(email==0)
    {
        printf("\n Ingrese email del cliente:");
        fflush(stdin);
        gets(cliente.email);
        email=validarEmail(cliente.email);
        if(email==0)
        {
            printf("\n email no valido\n");
            system("pause");
            system("cls");
        }
    }


    printf("\n Ingrese Nro de telefono del cliente: ");
    fflush(stdin);
    gets(cliente.telefono);
    //cargaDomicilio(cliente);
    cliente.eliminado = 0;
        fseek(archi,0,SEEK_END);
        cliente.id= (ftell(archi)/sizeof(stCliente)+1);
        fwrite(&cliente,sizeof(stCliente),1, archi);
        fclose(archi);
        printf("\n Carga exitosa\n");
        system("pause");
        system("cls");
    }else
    {
        printf("error al abrir archivo");
    }


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
    int flag=0;
    int i=0;
    strcpy(emailValidos[0], "@gmail.com");
    strcpy(emailValidos[1], "@hotmail.com");
    strcpy(emailValidos[2], "@yahoo.com");
    strcpy(emailValidos[3], "@hotmail.com.ar");

    ptr = strchr(email, '@');
    if(ptr!=NULL)
    {
    while(flag==0 && i<4)
    {
        if(strcmp(ptr, emailValidos[i])==0)
        {
            flag=1;
        }
        i++;
    }
    }


    return flag;
}

void listadoClientes(char nombreArchivo[])
{
    FILE* archi = fopen(nombreArchivo, "rb");
    stCliente a;
    if(archi)
    {
        while(fread(&a,sizeof(stCliente),1, archi))
        {
            muestraCliente(a);
            printf("\n ===========================\n");
        }
    }
}
void bajaCliente(stCliente a)
{
    a.eliminado=-1;
}
void altaCliente(stCliente a)
{
    a.eliminado=0;
}


