#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "domicilio.h"
#include "cliente.h"
#include "mock.h"




stDomicilio cargaDomicilio ()
{

    stDomicilio d;
    int cPos=0;

    printf ( "\n ---   DOMICILIO ----\n");

    printf ("\n");

    printf ("Ingrese calle:  ");
    fflush (stdin);
    gets (d.calle);

    printf ("Ingrese numero:  ");
    fflush (stdin);
    gets (d.nro);

    printf ("Ingrese Localidad:  ");
    fflush (stdin);
    gets (d.localidad);

    printf ("Ingrese Provincia:  ");
    fflush (stdin);
    gets (d.provincia);

    while(cPos==0)
    {
        printf ("Ingrese Codigo postal:  ");
        fflush (stdin);
        gets (d.cPos);

        if (validarCodigoPostal (d.cPos))
        {
            cPos=1;

        }
        else
        {
            printf("\n Numero no valido, debe poseer 4 digitos\n");
            system("pause");
            system("cls");
        }

    }
    return d;
}


void muestraDomicilio (stDomicilio d) /////mostrar domicilio, sirve para consulta
{

    printf("\n Calle:................. %s", d.calle);
    printf("\n Numero:................ %s", d.nro);
    printf("\n Localidad:............. %s", d.localidad);
    printf("\n Provincia:............. %s", d.provincia);
    printf("\n Codigo Postal:......... %s\n", d.cPos);

}

int menuModifDom()
{
    int opcion;

    printf("\n Ingrese 1 para cambiar calle");
    printf("\n Ingrese 2 para cambiar numero");
    printf("\n Ingrese 3 para cambiar localidad");
    printf("\n Ingrese 4 para cambiar provincia");
    printf("\n Ingrese 5 para cambiar Codigo postal");

    printf("\n Escape para salir");
    fflush(stdin);
    opcion=getch();
    system("cls");
    return opcion;
}

stDomicilio modificarDomicilio (stDomicilio d)
{
    int opcion=0;
    int fin=0;
    int cPos=0;
    do
    {
        system("cls");
        int opcion=menuModifDom();
        switch(opcion)
        {


        case 49:
            printf("\nIngrese nueva Calle:\n");
            fflush(stdin);
            gets(d.calle);
            printf("\n Calle actualizada correctamente\n");
            system("pause");
            break;
        case 50:
            printf("\n Ingrese nuevo numero:\n");
            fflush(stdin);
            gets(d.nro);
            printf("\n Numero actualizado correctamente\n");
            system("pause");
            break;
        case 51:

            printf("\nIngrese nueva localidad:\n");
            fflush(stdin);
            gets(d.localidad);
            printf("\n Localidad actualizada correctamente\n");
            system("pause");
            break;
        case 52:
            printf("\n Ingrese nueva provincia:");
            fflush(stdin);
            gets(d.provincia);
            printf("\n Provincia actualizada correctamente\n");
            system("pause");
            break;
        case 53:
            while(cPos==0)
            {
                printf ("Ingrese nuevo Codigo postal:  ");
                fflush (stdin);
                gets (d.cPos);

                if (validarCodigoPostal (d.cPos))
                {
                    cPos=1;

                }
                else
                {
                    printf("\n Numero no valido, debe poseer 4 digitos\n");
                    system("pause");
                    system("cls");
                }

            }
            printf("\n Codigo postal actualizado correctamente\n");
            system("pause");
            system("cls");
            break;

        case 27:

            fin=1;
            break;
        default:
            printf("\n Opcion no valida");
            system("pause");
            break;

        }
    }
    while(fin==0);


    return d;
}



int validarCodigoPostal(char codigoPostal [])
{

    int flag=0;
    int cantNum=strlen(codigoPostal);

    if (cantNum<5&&cantNum>3)
    {
        flag=1;
    }

    return flag;


}



