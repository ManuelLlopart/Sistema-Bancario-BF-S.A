#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "movimientos.h"
#include "mock.h"
#include <string.h>
#define ARCHI_DOS "movimientosDos.dat"
const int DIM=100;

stMovimientos crearMovimiento(int idCuenta) ///idCuenta es el nroCuenta
{
        stMovimientos movimiento;
        movimiento.eliminado=0; ///porque al crear el movimiento esta activo
        movimiento.idCuenta = idCuenta;
        printf("Ingrese el detalle del movimiento:");
        fflush(stdin);
        gets(movimiento.detalle);
        printf("\nIngrese el importe del movimiento:");
        fflush(stdin);
        scanf("%f",&movimiento.importe);
        movimiento=cargaFechaMovimiento(movimiento);

    return movimiento;
}


void muestraMovimiento(stMovimientos movimiento)
{
    printf("\nId:%d\n",movimiento.id);
    printf("Id Cuenta:%d\n",movimiento.idCuenta);
    printf("Detalle: %s\n",movimiento.detalle);
    printf("Importe del movimiento:%.2f\n",movimiento.importe);
    printf("Fecha del movimiento:%d/%d/%d\n",movimiento.dia, movimiento.mes, movimiento.anio);
    printf("Estado del movimiento:%d\n",movimiento.eliminado);
    printf("\n=============================================");
}


///crear una funcion para dar de baja (eliminar) un movimiento

stMovimientos eliminaMovimiento(char nombreArchivo[],int idMovimiento)///lo elimino comparando con el id del mov. que quiero eliminar
{
    FILE *archi=fopen(nombreArchivo,"r+b");
    stMovimientos mov;
    int flag=0;
    if (archi)
    {
        while(flag==0 && fread(&mov,sizeof(stMovimientos),1,archi)>0)
        {
            if (mov.id==idMovimiento && mov.eliminado==0) ///si coinciden, cambia el valor de eliminado a verdadero
            {
                flag=1;
                mov.eliminado=1;
                printf("Usted ha dado de baja el siguiente movimiento:\n");
                muestraMovimiento(mov);
            }
            else if (mov.id==idMovimiento && mov.eliminado==1)
            {
                printf("El movimiento ya fue dado de baja\n");
            }
        }
        fseek(archi,-1*sizeof(stMovimientos),SEEK_CUR);///me paro donde esta el cursor y me muevo un registro hacia atras
        fwrite(&mov,sizeof(stMovimientos),1,archi); ///reescribo el movimiento con eliminado=1

        fclose(archi);
    }
    return mov;
}

///crear una funcion para modificar un movimiento

void modificaMovimiento(char nombreArchivo[],int idMovimiento,int idCuenta,char detalleMov[],float importeMov,int diaModif,int mesModif,int anioModif)
{
    ///Ingreso el detalle e importe nuevos y la fecha de modificacion del movimiento
    FILE *archi=fopen(nombreArchivo,"r+b");
    stMovimientos mov;
    int flag=0;

    if (archi)
    {
        while(flag==0 && fread(&mov,sizeof(stMovimientos),1,archi)>0)
        {
            if(idMovimiento==mov.id && idCuenta==mov.idCuenta && mov.eliminado==1)
            {
                printf("El movimiento no se puede modificar porque ya ha sido eliminado\n");
            }
            else if (idMovimiento==mov.id && idCuenta==mov.idCuenta && mov.eliminado==0)
            {
                strcpy(mov.detalle,detalleMov);
                mov.importe=importeMov;
                mov.dia=diaModif;
                mov.mes=mesModif;
                mov.anio=anioModif;
                flag=1;
            }
        }
        fseek(archi,-1*sizeof(stMovimientos),SEEK_CUR);
        fwrite(&mov,sizeof(stMovimientos),1,archi);
        fclose (archi);
    }
}

void listadoMovPorIdCuenta (char NombreArchivo[], int idCuenta)
{
    FILE *archi = fopen(NombreArchivo, "rb");
    stMovimientos mov;
    int numMovEncontrados = 0;

    if (archi) {
        while (fread(&mov, sizeof(stMovimientos), 1, archi) > 0) {
            if (mov.idCuenta == idCuenta) {
                numMovEncontrados++;
                printf("\nOpcion %d:\n", numMovEncontrados);
                muestraMovimiento(mov);
            }
        }

        if (numMovEncontrados == 0) {
            printf("\nEl cliente no tiene ninguna cuenta activa.\n");
        }

        fclose(archi);
    } else {
        printf("Error al abrir el archivo.\n");
    }
}

/*void modificaMov(char nombreArchivo[],int idCuenta,int idMovimiento)
{
   FILE *archi=fopen(nombreArchivo,"r+b");
   stMovimientos mov;
   int flag=0;
   if (archi)
   {
       while(flag==0 && fread(&mov,sizeof(stMovimientos),1,archi)>0)
       {
           if (mov.id==idMovimiento && mov.idCuenta==idCuenta)
           {
               strcpy(mov.detalle,detalleMov);
                mov.importe=importeMov;
                mov.dia=diaModif;
                mov.mes=mesModif;
                mov.anio=anioModif;
                flag=1;
           }
       }


       fclose(archi);
   }
}*/

stMovimientos cargaFechaMovimiento(stMovimientos movimiento)
{

    int anio=0,mes=0,dia=0,flag=0,flag1=0,flag2=0,flag3=0,flag4=0,flag5=0;

    do
    {
        printf("Ingrese el anio del movimiento:");
        fflush(stdin);
        scanf("%d", &anio);
        if (anio<1 || anio>2024)
        {
            flag=1;
            printf("\nEl anio ingresado no es correcto\n");
        }
        else
        {
            flag=0;
        }
    }
    while(flag==1);

    do
    {
        printf("\nIngrese el mes del movimiento del 1 al 12:");
        fflush(stdin);
        scanf("%d",&mes);
        if (mes<1 || mes>12)
        {
            flag1=1;
            printf("\nEl mes ingresado no es correcto\n");
        }
        else
        {
            flag1=0;
        }
    }
    while (flag1==1);

    /*if (anio%4==0)
    {
        printf("\nEs un anio bisiesto");
    }*/


    if (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12)
    {
        do
        {
            printf("\nIngrese el dia del 1 al 31:");
            fflush(stdin);
            scanf("%d",&dia);
            if (dia<1 || dia>31)
        {
            flag2=1;
            printf("\nEl dia ingresado no es correcto\n");
        }
        else
        {
            flag2=0;
        }
        }
        while(flag2==1);

    }

    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        do
        {
            printf("\nIngrese el dia del 1 al 30:");
            fflush(stdin);
            scanf("%d",&dia);
            if (dia<1 || dia>30)
        {
            flag3=1;
            printf("\nEl dia ingresado no es correcto\n");
        }
        else
        {
            flag3=0;
        }
        }
        while (flag3==1);
    }
    if(mes==2 && (anio%4)!=0)
    {
        do
        {
            printf("\nIngrese el dia del 1 al 28:");
            fflush(stdin);
            scanf("%d",&dia);
            if (dia<1 || dia>28)
        {
            flag4=1;
            printf("\nEl dia ingresado no es correcto\n");
        }
        else
        {
            flag4=0;
        }
        }
        while (flag4==1);
    }
    if (mes==2 && anio%4==0)
    {
        do
        {
            printf("\nIngrese el dia del 1 al 29:");
            fflush(stdin);
            scanf("%d",&dia);
             if (dia<1 || dia>29)
        {
            flag5=1;
            printf("\nEl dia ingresado no es correcto\n");
        }
        else
        {
            flag5=0;
        }
        }
        while(flag5==1);
    }


    movimiento.anio = anio;
    movimiento.mes = mes;
    movimiento.dia = dia;

    return movimiento;
}

void listadoMovimientosPorIdCuenta(char nombreArchivo[],int idCuenta)
{
    ///muestra todos los movimientos correspondientes a un idCuenta especifico
    FILE *archi=fopen(nombreArchivo,"rb");
    stMovimientos mov;
    int numeroMov=0;

    if (archi)
    {
        while(fread(&mov,sizeof(stMovimientos),1,archi)>0)
        {
            if (mov.idCuenta==idCuenta)
            {
                muestraMovimiento(mov);
                numeroMov++;
            }
        }
        if (numeroMov==0)
        {
            printf("No se encontraron movimientos");
        }
        fclose(archi);
    }
}

void listadoMovimientosPorMes(char nombreArchivo[],int mes)
{
    ///muestra todos los movimientos correspondientes a un determinado mes

    FILE *archi=fopen(nombreArchivo,"rb");
    stMovimientos mov;
    int numMov=0;
    if (archi)
    {
        while (fread(&mov,sizeof(stMovimientos),1,archi)>0)
        {
            if(mes==mov.mes)
            {
                muestraMovimiento(mov);
                numMov++;
            }
        }
        if (numMov==0)
        {
            printf("No se encontraron movimientos");
        }

        fclose(archi);
    }
}

void buscaMovimientosPorFecha(char nombreArchivo[],int diaBuscado,int mesBuscado, int anioBuscado)
{
    ///devuelve los movimientos correspondientes a una determinada fecha
    FILE *archi=fopen(nombreArchivo,"rb");
    stMovimientos mov;
    int numeroMov=0;

    if (archi)
    {
        while (fread(&mov,sizeof(stMovimientos),1,archi)>0)
        {
            if (anioBuscado==mov.anio && mesBuscado==mov.mes && diaBuscado==mov.dia)
            {
                muestraMovimiento(mov);
                numeroMov++;
            }
        }
        if (numeroMov==0)
        {
            printf("No se encontraron movimientos\n");
        }
        fclose(archi);
    }
}

int cuentaRegistros(char nombreArchivo[],int sizeEstructura)
{
    FILE *archi=fopen(nombreArchivo,"rb");
    int cantidadRegistros;
    if (archi)
    {
        fseek(archi,0,SEEK_END);
        cantidadRegistros=ftell(archi)/sizeEstructura;
        fclose(archi);
    }
    return cantidadRegistros;
}
