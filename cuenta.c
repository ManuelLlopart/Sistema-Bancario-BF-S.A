#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "cuenta.h"


///Alta de cuenta (cargar_cuenta)
///Consulta de cuenta (mostrar_cuenta)
///Baja de cuenta (baja_cuenta)
///Modificación de cuenta (modificacion_cuenta)

stCuenta cargar_cuenta ()///alta de cuenta
{
    stCuenta cuenta;

    ///id
    printf("\nIngrese el id del cliente: ");
    scanf("%d",&cuenta.idCliente);
    printf("\nIngrese el numero de cuenta: ");
    scanf("%d",&cuenta.nroCuenta);
    printf("\nIngrese el tipo de cuenta (1. Caja de Ahorro en Pesos, 2. Caja de Ahorro en Dólares, 3. Cta Cte en $)");
    scanf("%d",&cuenta.tipoDeCuenta);
    printf("\nIngrese el costo mensual: ");
    scanf("%f",&cuenta.costoMensual);

    cuenta.saldo=0.0;///inicialice el saldo en 0
    ///se debe actualizar con el movimiento
    cuenta.eliminado=0;

    return cuenta;
}

///carga de cuenta con archivo
void cargar_cuenta_archivo(char NombreArchivo [])
{

    FILE*archi=fopen(NombreArchivo,"ab");
    stCuenta cuenta;
    int continuar=1;

    if(archi)
    {
        while(continuar)
        {
            cuenta=cargar_cuenta();
            fwrite(&cuenta,sizeof(stCuenta),1,archi);

            printf("presione 1 si quiere cargar otra cuenta, si no 0 para salir"),
            scanf("%d",&continuar);
        }
        fclose(archi);
    }
}


void mostrar_cuenta (stCuenta cuenta) ///mostrar cuenta, sirve para consulta
{
    printf("\nid del cliente: %d",cuenta.idCliente);
    printf("\nNumero de la cuenta: %d",cuenta.nroCuenta);
    printf("\nTipo de cuenta: %d",cuenta.tipoDeCuenta);
    printf("\nCosto mensual: %.2f",cuenta.costoMensual);
    printf("\nSaldo: %.2f",cuenta.saldo);
    printf("\nEstado: %s\n", cuenta.eliminado ? "Eliminado" : "Activo");
    printf("\n---------------------------------------------------------------------------------------");
}

///mostrar listado de cuenta con archivos
void listado_de_cuenta(char NombreArchivo[])
{
    FILE *archi = fopen(NombreArchivo, "rb");
    stCuenta cuenta;

    if (archi)
    {
        while (fread(&cuenta, sizeof(stCuenta), 1, archi) > 0)
        {
            mostrar_cuenta(cuenta);
        }

        fclose(archi);
    }
    else
    {
        printf("No se pudo abrir el archivo %s\n", NombreArchivo);
    }
}

void actualizar_saldo(stCuenta *cuenta, float monto) { ///verlo o corregirlo
    cuenta->saldo += monto;
}

void baja_cuenta(stCuenta cuenta[], int BuscarCuenta, int CantidadCuentas) ///elimina una cuenta, osea la da de baja
{
    int i;
    int CuentaEncontrada=0;

    for(i=0; i<CantidadCuentas&& CuentaEncontrada == 0; i++)
    {
        if(cuenta[i].id == BuscarCuenta) ///se podria comparar con .idcliente
        {
            cuenta[i].eliminado = -1;
            printf("\nla cuenta con el id %d fue eliminada",BuscarCuenta);
            CuentaEncontrada=1;
        }
    }
}

void modificacion_cuenta (stCuenta cuenta[], int CantidadCuentas,int BuscarId)
{
    int i;
    int CuentaEncontrada=0;

    for(i=0; i<CantidadCuentas && CuentaEncontrada==0; i++)
    {
        if(cuenta[i].id== BuscarId) ///se podria comparar con idcliente
        {
            printf("\nCuenta encontrada:");
            mostrar_cuenta(cuenta[i]);

            printf("\nModifique la cuenta: ");
            cuenta[i]=cargar_cuenta();

            CuentaEncontrada=1;
        }
    }
}
