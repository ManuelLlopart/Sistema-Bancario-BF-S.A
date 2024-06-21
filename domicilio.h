
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "domiclio.h"
#include "mock.h"


stDomicilio cargaDomicilio ()
{

    stDomicilio d;

    printf ( " ---   DOMICILIO ----\n");

    printf ("\n");

    printf ("Ingrese calle:  ");
    fflush (stdin);
    gets (d.calle);

    printf ("Ingrese número:  ");
    fflush (stdin);
    gets (d.numero);

    printf ("Ingrese Localidad:  ");
    fflush (stdin);
    gets (d.localidad);

    printf ("Ingrese Codigo postal:  ");
    fflush (stdin);
    gets (d.cPos);

    int validarCodigoPostal(char* cPos) {
    stDomicilio cPos;

    if (strlen(cPos) == 4) {
        printf ("codigo válido\n");
        cPos=d.

        // Código postal válido
    } else {
       printf (" Valor inválido, pruebe nuevamente\n") 0; // Código postal inválido
    }
}
}

return d;

}

}

stDomicilio muestraDomicilio (stDomicilio, domicilio1) /////mostrar domicilio, sirve para consulta
{

    printf("\n Calle: %s\n", domicilio.calle);
    printf("\n Número: %s\n", domicilio.nro);
    printf("\n Localidad: %s\n", domicilio.localidad);
    printf("\n Provincia: %s\n", domicilio.provincia);
    printf("\n Código Postal: %s\n", domicilio.cpos);


    printf ( "-DIRECCION CARGADA EXITOSAMENTE- \n");
}

int menuModif()
{
    int opcion;

    printf("\n Ingrese 1 para cambiar calle");
    printf("\n Ingrese 2 para cambiar numero");
    printf("\n Ingrese 3 para cambiar localidad");
    printf("\n Ingrese 4 para cambiar provincia");
    printf("\n Ingrese 5 para cambiar Codigo postal");

    printf("\n Escape para salir");
    opcion=getch();
    system("cls");
    return opcion;
}

stDomicilio modificarDomicilio (stDomicilio d)
{
    int opcion=0;

    do
    {
        int opcion=menuModif();
        switch(opcion)
        {


        case 49:
            printf("\nIngrese nueva Calle:\n");
            fflush(stdin);
            gets(d.calle);
            printf("\n Calle actualizada correctamente");
            system("pause");
            break;
        case 50:
            printf("\n Ingrese nuevo numero:\n");
            fflush(stdin);
            gets(a.numero);
            printf("\n Numero actualizado correctamente");
            system("pause");
            break;
        case 51:

            printf("\nIngrese nueva localidad:\n");
            fflush(stdin);
            gets(a.localidad);
            printf("\n Localidad actualizada correctamente");
            system("pause");
            break;

        case 52:
            printf("\n Ingrese nuevo Codigo postal:");
            fflush(stdin);
            gets(a.cpos);
            printf("\n Codigo postal correctamente");
            system("pause");
            break;


        default:
            printf("\n Opcion no valida");
            system("pause");
            break;

        }
        while(opcion != 27);

        return d;
    }

    stDomicilio altaDomicilio (stDomicilio d)
    {

        stDomicilio d=cargaDomicilio ();

        return d;
    }

    int validarCpos ( char cPos [])
    {


    }


