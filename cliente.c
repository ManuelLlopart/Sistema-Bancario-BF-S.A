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
    int telefono=0;

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


        while(telefono==0)
        {
        printf("\n Ingrese Nro de telefono del cliente: ");
        fflush(stdin);
        gets(cliente.telefono);
        if(validarTelefono(cliente.telefono))
        {
            telefono=1;
        }else
        {
            printf("\n Numero no valido, intente nuevamente");
            system("pause");
        }
        }
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

int validarTelefono(char telefono[])
{
    int flag=0;
    int cantCaract = strlen(telefono);//evito abrir la funcion 2 veces
    flag=(cantCaract<11&&cantCaract>8);

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
    (cliente.eliminado==0)?strcpy(estado, "Activo"):strcpy(estado, "Eliminado");//ternario
    printf("\n Estado de cliente:..... %s\n", estado);

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
            printf("\n Error \n El Cliente ya se encuentra dado de baja\n");
            system("pause");
        }
        else
        {
            a->eliminado=-1;
            printf("\n Cliente dado de baja\n");
            system("pause");
        }
}
void altaCliente(stCliente *a)
{
    if(a->eliminado==0)
        {
            printf("\n Error \n El Cliente ya se encuentra dado de alta\n");
            system("pause");
        }
        else
        {
            a->eliminado=0;
            printf("\n Cliente dado de alta\n");
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
    printf("\n Escape para salir\n");
    fflush(stdin);
    opcion=getche();
    system("cls");
    return opcion;
}

stCliente modificarCliente(stCliente a)
{

    int dni=0;
    int email=0;
    int opcion;
    int telefono=0;
    do
    {
        opcion=menuModif();

        switch(opcion)
    {
    case 49:
        printf("\nIngrese nuevo nombre:\n");
        fflush(stdin);
        gets(a.nombre);
        printf("\n Nombre actualizado correctamente\n");
        system("pause");
        break;
    case 50:
        printf("\nIngrese nuevo apellido:\n");
        fflush(stdin);
        gets(a.apellido);
        printf("\n Apellido actualizado correctamente\n");
        system("pause");
        break;
    case 51:
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
        printf("\n Dni actualizado correctamente\n");
        system("pause");
        break;
    case 52:
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
        printf("\n Email actualizado correctamente\n");
        system("pause");
        break;
    case 53:
         while(telefono==0)
        {
        printf("\n Ingrese nuevo Nro de telefono del cliente: ");
        fflush(stdin);
        gets(a.telefono);
        if(validarTelefono(a.telefono))
        {
            telefono=1;
        }else
        {
            printf("\n Numero no valido, intente nuevamente\n");
            system("pause");
        }
        }
        break;
    case 54://stDomicilio
        break;
    case 55:
        bajaCliente(&a);
        break;
    case 56:
        altaCliente(&a);
        break;
    case 27:
        printf("\n Saliendo de modificacion\n");
        system("pause");
        break;
    default:
        printf("\nOpcion no valida\n");
        system("pause");
        break;

    }
    }while(opcion != 27);

    return a;
}


void reemplazaClientePos(char nombreArchivo[],stCliente a, int pos)
{
    FILE* archi=fopen(nombreArchivo, "r+b");
    if(archi)
    {
        fseek(archi,pos*sizeof(stCliente), SEEK_SET);
        fwrite(&a,sizeof(stCliente),1, archi);
        fclose(archi);
    }
}

stCliente clientePos(char nombreArchivo[], int pos)
{
    FILE* archi=fopen(nombreArchivo, "rb");
    stCliente a;
    if(archi)
    {
        fseek(archi,pos*sizeof(stCliente), SEEK_SET);
        fread(&a,sizeof(stCliente),1,archi);
        fclose(archi);
    }
    return a;
}


int getIdCliente(stCliente a)
{
    int id=a.id;
    return id;
}


void listadoClientesActivos(char nombreArchivo[])
{
    FILE* archi = fopen(nombreArchivo, "rb");
    stCliente a;
    if(archi)
    {
        while(fread(&a,sizeof(stCliente),1, archi)>0)
        {
            if(a.eliminado==0)
            {
                muestraCliente(a);
                printf("\n ===========================\n");
            }
        }
    }
}

void listadoClientesInactivos(char nombreArchivo[])
{
    FILE* archi = fopen(nombreArchivo, "rb");
    stCliente a;
    if(archi)
    {
        while(fread(&a,sizeof(stCliente),1, archi)>0)
        {
            if(a.eliminado==-1)
            {
                muestraCliente(a);
                printf("\n ===========================\n");
            }
        }
    }
}
