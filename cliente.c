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
        cliente.nroCliente=cliente.id;
        fwrite(&cliente,sizeof(stCliente),1, archi);
        fclose(archi);
        printf("\n Carga exitosa\n");
        system("pause");
        system("cls");
    }
    else
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
        while(fread(&a,sizeof(stCliente),1, archi)>0)
        {
            muestraCliente(a);
            printf("\n ===========================\n");
        }
    }
}
void bajaCliente(stCliente *a)
{
    if(a->eliminado==1)
        {
            printf("\n Error \n El Cliente ya se encuentra dado de baja");
            system("pause");
        }
        else
        {
            a->eliminado=-1;
            printf("\n Cliente dado de baja");
            system("pause");
        }
}
void altaCliente(stCliente *a)
{
    if(a->eliminado==0)
        {
            printf("\n Error \n El Cliente ya se encuentra dado de alta");
            system("pause");
        }
        else
        {
            a->eliminado=0;
            printf("\n Cliente dado de alta");
            system("pause");
        }
}




int buscaPosClientePorDni(char nombreArchivo[], char dniBuscado[])
{
    int pos = -1;
    FILE* archi = fopen(nombreArchivo, "rb");
    stCliente a;
    int flag = 0;
    if(archi)
    {
        while(flag==0 && fread(&a, sizeof(stCliente),1, archi)>0)
        {

            if(strcmp(dniBuscado, a.dni)==0)
            {
                flag=1;
                pos=ftell(archi)/sizeof(stCliente)-1;
            }
        }
        fclose(archi);
    }


    return pos;
}

void muestraClientePos(char nombreArchivo[], int pos)
{
    stCliente a;
    if(pos <= cuentaCantidadClientes(nombreArchivo))
    {
        FILE* archi =  fopen(nombreArchivo, "rb");
        if(archi)
        {
            fseek(archi, pos*sizeof(stCliente),SEEK_SET);
            fread(&a, sizeof(stCliente),1, archi);
            muestraCliente(a);
            fclose(archi);
        }
    }
}

int cuentaCantidadClientes(char nombreArchivo[])
{
    int pos=0;
    stCliente a;
    FILE* archi = fopen(nombreArchivo, "rb");
    if(archi)
    {
        while(fread(&a, sizeof(stCliente), 1, archi))
        {
            pos++;
        }
    }
    return pos;
}

int buscaPosClientePorId(char nombreArchivo[], int idBuscado)
{
    FILE* archi = fopen(nombreArchivo, "rb");
    int flag = 0;
    int pos = 0;
    stCliente a;
    if(archi)
    {
        while(flag==0 && fread(&a, sizeof(stCliente),1, archi)>0)
        {
            if(a.id==idBuscado)
            {
                flag=1;
                pos=ftell(archi)/sizeof(stCliente)-1;
            }

        }
        fclose(archi);
    }

    return pos;
}

int menuModif()
{
    int opcion;
    printf("\n Ingrese 1 para cambiar nombre");
    printf("\n Ingrese 2 para cambiar apellido");
    printf("\n Ingrese 3 para cambiar dni");
    printf("\n Ingrese 4 para cambiar email");
    printf("\n Ingrese 5 para cambiar telefono");
    printf("\n Ingrese 6 para cambiar domicilio");
    printf("\n Ingrese 7 para dar de baja al cliente");
    printf("\n Ingrese 8 para dar de alta al cliente");
    printf("\n Escape para salir");
    opcion=getch();
    system("cls");
    return opcion;
}

stCliente modificarCliente(stCliente a)
{
    int opcion=menuModif();
    int dni=0;
    int email=0;
    do
    {
        switch(opcion)
    {
    case 1:
        printf("\nIngrese nuevo nombre:\n");
        fflush(stdin);
        gets(a.nombre);
        printf("\n Nombre actualizado correctamente");
        system("pause");
        break;
    case 2:
        printf("\nIngrese nuevo apellido:\n");
        fflush(stdin);
        gets(a.apellido);
        printf("\n Apellido actualizado correctamente");
        system("pause");
        break;
    case 3:
        while(dni==0)
        {
        printf("\nIngrese nuevo dni:\n");
        fflush(stdin);
        gets(a.dni);
        dni=validarDni(a.dni);
            if(dni==0)
            {
                printf("\n dni no valido\n");
                system("pause");
                system("cls");
            }
        }
        printf("\n Dni actualizado correctamente");
        system("pause");
        break;
    case 4:
         while(email==0)
        {
            printf("\n Ingrese nuevo email del cliente:");
            fflush(stdin);
            gets(a.email);
            email=validarEmail(a.email);
            if(email==0)
            {
                printf("\n email no valido\n");
                system("pause");
                system("cls");
            }
        }
        printf("\n Email actualizado correctamente");
        system("pause");
        break;
    case 5:
         printf("\n Ingrese nuevo Nro de telefono del cliente: ");
        fflush(stdin);
        gets(a.telefono);
        printf("\n Telefono actualizado correctamente");
        system("pause");
        break;
    case 6://stDomicilio
        break;
    case 7:
        bajaCliente(&a);
        break;
    case 8:
        altaCliente(&a);
        break;
    default:
        printf("\nOpcion no valida");
        system("pause");
        break;

    }
    }while(opcion != 27);

    return a;
}


void reemplazaClientePos(stCliente a, char nombreArchivo)
{

}
