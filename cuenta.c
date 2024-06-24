#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "cuenta.h"
#include "cliente.h"

int existeNumeroDeCuenta(stCuenta cuenta[], int v, int numCuenta)
{
    int flag=0;
    for (int i = 0; i < v && flag==0; i++)
    {
        if (cuenta[i].nroCuenta == numCuenta)
        {
            flag=1;
        }
    }
    return flag;
}


int cargarCuenta (stCuenta cuenta[],int v, int dim)///alta de cuenta
{
    char opcion=0;
    int IdCliente=0;

    while(v<dim && opcion!=27)
    {
        printf("\nIngrese el id del cliente: ");
        scanf("%d",&cuenta[v].idCliente);
         int numCuenta;
        int numCuentaValido = 0;
        while (!numCuentaValido)
        {
            printf("Ingrese el numero de cuenta: ");
            scanf("%d", &numCuenta);

            if (existeNumeroDeCuenta(cuenta, v, numCuenta))
            {
                printf("El numero de cuenta ya existe. Ingrese otro numero de cuenta.\n");
            }
            else
            {
                cuenta[v].nroCuenta = numCuenta;
                numCuentaValido = 1;
            }
        }
        printf("\nIngrese el tipo de cuenta (1. Caja de Ahorro en Pesos, 2. Caja de Ahorro en Dólares, 3. Cta Cte en $)");
        scanf("%d",&cuenta[v].tipoDeCuenta);
        printf("\nIngrese el costo mensual: ");
        scanf("%f",&cuenta[v].costoMensual);

        cuenta[v].saldo=0.0;///inicialice el saldo en 0
        ///se debe actualizar con el movimiento
        cuenta[v].eliminado=0;

        v++;

        printf("\nsi quiere ingresar otra cuenta presione cualquier tecla y si no quiere cargar mas presione ESC");
        opcion=getch();
        system("cls");
    }
    return v;
}

stCuenta cargarCuentaIndividual (stCuenta cuenta)
{


    printf("\nIngrese el tipo de cuenta (1. Caja de Ahorro en Pesos, 2. Caja de Ahorro en Dólares, 3. Cta Cte en $)");
    scanf("%d",&cuenta.tipoDeCuenta);
    printf("\nIngrese el costo mensual: ");
    scanf("%f",&cuenta.costoMensual);
    cuenta.saldo=0.0;
    cuenta.eliminado=0;

    return cuenta;
}

void cargaCuenta (char NombreArchivo [], stCliente cliente)
{
    FILE *archi = fopen(NombreArchivo,"ab");
    stCuenta cuenta;

    if (archi)
    {
        cuenta.idCliente=cliente.id;
        cuenta.nroCuenta= cuentaCuentasCliente(NombreArchivo,cliente.id)+1;
        //Buscar y contar la cantidad de cuentas del cliente
        cuenta=cargarCuentaIndividual(cuenta);
        fseek(archi,0,SEEK_END);
        cuenta.id= (ftell(archi)/sizeof(stCuenta)+1);
        fwrite(&cuenta,sizeof(stCuenta),1,archi);
        printf("\nCarga Exitosa\n");
        fclose(archi);
    }

}


///carga de cuenta con archivo
void arreglo2archivo (char NombreArchivo[], int v,stCuenta cuenta[])
{
    FILE*archi=fopen(NombreArchivo,"ab");

    int i;

    if(archi)
    {
        for(i=0; i<v; i++)
        {
                fwrite(&cuenta[i],sizeof(stCuenta),1,archi);
        }
        fclose(archi);
    }
}


void mostrarCuenta (stCuenta cuenta[],int validos) ///mostrar cuenta, sirve para consulta
{
    int i;

    for(i=0; i<validos; i++)
    {
        printf("\nid del cliente: %d",cuenta[i].idCliente);
        printf("\nNumero de la cuenta: %d",cuenta[i].nroCuenta);
        printf("\nTipo de cuenta: %d",cuenta[i].tipoDeCuenta);
        printf("\nCosto mensual: %.2f",cuenta[i].costoMensual);
        printf("\nSaldo: %.2f",cuenta[i].saldo);
        printf("\nEstado: %s\n", cuenta[i].eliminado ? "Eliminado" : "Activo");
        printf("\n---------------------------------------------------------------------------------------");
    }

}
void mostrarCuentaIndividual(stCuenta cuenta) {///mostrar cuenta, sirve para consulta
    printf("\nID:................... %d",cuenta.id);
    printf("\nid del cliente:....... %d", cuenta.idCliente);
    printf("\nNumero de la cuenta:.. %d", cuenta.nroCuenta);
    printf("\nTipo de cuenta:....... %s", (cuenta.tipoDeCuenta == 1) ? "Caja de Ahorro en Pesos" :(cuenta.tipoDeCuenta == 2) ? "Caja de Ahorro en Dolares" : "Cta Cte en $");
    printf("\nCosto mensual:........ %.2f", cuenta.costoMensual);
    printf("\nSaldo:................ %.2f", cuenta.saldo);
    printf("\nEstado:............... %s\n", (cuenta.eliminado) ? "Eliminado" : "Activo");
    printf("\n---------------------------------------------------------------------------------------");
}

void muestraArchivoCuentas(char nombreArchivo[])
{
    stCuenta cuenta;
    FILE* archi = fopen(nombreArchivo, "rb");

    if(archi)
    {
        while(fread(&cuenta, sizeof(stCuenta), 1, archi)>0)
        {
            mostrarCuentaIndividual(cuenta);
        }
        fclose(archi);
    }
}

///mostrar listado de cuenta con archivos
///que busque por id la cuenta y muestre todas hasta las eliminadas. de una cuenta en especifica hasta las eliminadas

int cantidadCuentasCliente (char NombreArchivo[], int BuscarId)
{
    FILE *archi = fopen(NombreArchivo, "rb");
    stCuenta cuenta;
    int numCuentasEncontradas = 0;

    if (archi) {
        while (fread(&cuenta, sizeof(stCuenta), 1, archi) > 0) {
            if (cuenta.idCliente == BuscarId) {
                numCuentasEncontradas++;
            }
        }
        fclose(archi);
    } else {
        printf("Error al abrir el archivo.\n");
    }

    return numCuentasEncontradas;
}

int cuentaCuentasCliente (char NombreArchivo[], int BuscarId)
{
    FILE *archi = fopen(NombreArchivo, "rb");
    stCuenta cuenta;
    int numCuentasEncontradas = 0;

    if (archi) {
        while (fread(&cuenta, sizeof(stCuenta), 1, archi) > 0) {
            if (cuenta.idCliente == BuscarId) {
                numCuentasEncontradas++;
            }
        }
        fclose(archi);
    } else {
        printf("Error al abrir el archivo.\n");
    }

    return numCuentasEncontradas;
}

int mostrarTodasLasCuentasActivas (char NombreArchivo[], int BuscarId)
{
    FILE *archi = fopen(NombreArchivo, "rb");
    stCuenta cuenta;
    int numCuentasEncontradas = 0;

    if (archi) {
        while (fread(&cuenta, sizeof(stCuenta), 1, archi) > 0) {
            if (cuenta.eliminado == 0) {
                numCuentasEncontradas++;
                printf("\nOpcion: %d\n", numCuentasEncontradas);
                mostrarCuentaIndividual(cuenta);
            }
        }

        if (numCuentasEncontradas == 0) {
            printf("\nEl cliente no tiene ninguna cuenta activa.\n");
        }

        fclose(archi);
    } else {
        printf("Error al abrir el archivo.\n");
    }

    return numCuentasEncontradas;
}

int mostrarTodasLasCuentasInactivas (char NombreArchivo[], int BuscarId)
{
    FILE *archi = fopen(NombreArchivo, "rb");
    stCuenta cuenta;
    int numCuentasEncontradas = 0;

    if (archi) {
        while (fread(&cuenta, sizeof(stCuenta), 1, archi) > 0) {
            if (cuenta.eliminado == -1) {
                numCuentasEncontradas++;
                printf("\nOpcion: %d\n", numCuentasEncontradas);
                mostrarCuentaIndividual(cuenta);
            }
        }

        if (numCuentasEncontradas == 0) {
            printf("\nEl cliente no tiene ninguna cuenta activa.\n");
        }

        fclose(archi);
    } else {
        printf("Error al abrir el archivo.\n");
    }

    return numCuentasEncontradas;
}

///CONSULTA CUENTA
int consultaCuenta(char NombreArchivo[], int BuscarId)
{
    FILE *archi = fopen(NombreArchivo, "rb");
    stCuenta cuenta;
    int numCuentasEncontradas = 0;

    if (archi) {
        while (fread(&cuenta, sizeof(stCuenta), 1, archi) > 0) {
            if (cuenta.idCliente == BuscarId && cuenta.eliminado == 0) {
                numCuentasEncontradas++;
                printf("\nOpcion %d:\n", numCuentasEncontradas);
                mostrarCuentaIndividual(cuenta);
            }
        }

        if (numCuentasEncontradas == 0) {
            printf("\nEl cliente no tiene ninguna cuenta activa.\n");
        }

        fclose(archi);
    } else {
        printf("Error al abrir el archivo.\n");
    }

    return numCuentasEncontradas;
}


void actualizarSaldo2(char nombreArchivo[], stMovimientos mov)
{
    FILE* archi=fopen(nombreArchivo, "r+b");
    stCuenta cuenta;
    int flag=0;
    if(archi)
    {
//        fseek(archi,0,SEEK_SET);
        while(flag==0&&fread(&cuenta,sizeof(stCuenta),1,archi)>0)
        {
            if(cuenta.id==mov.idCuenta)
            {
                flag=1;
                cuenta.saldo =cuenta.saldo+mov.importe;
                fseek(archi,-sizeof(stCuenta),SEEK_CUR);
                fwrite(&cuenta,sizeof(stCuenta),1,archi);

            }
        }
        fclose(archi);
    }
}

int tipoCuentas ()
{
int tipoCuenta=0;
        printf("\nSeleccione la opción correspondiente para modificar esta cuenta:");
        printf("\n1 - Caja de Ahorro en Pesos");
        printf("\n2 - Caja de Ahorro en Dólares");  ///funcion aparte
        printf("\n3 - Cuenta Corriente en Pesos");
        printf("\n0 - Cancelar\n");
        scanf("%d",&tipoCuenta);

    return tipoCuenta;
}
///hacer funcion elegirtipodecuenta y que retorne el tipo de cuenta


stCuenta bajaCuenta(stCuenta cuenta)
{

    cuenta.eliminado=-1;

    return cuenta;

}


///funcion de menu de opcion para modificacion de cuenta
int modificarCuenta()
{
    int modificar = 0;
    system("cls");
    printf("\nSeleccione el campo que desea modificar:");
    printf("\n1 - Modificar tipo de cuenta");
    printf("\n2 - Modificar costo mensual");
    printf("\n3 - Modificar la cuenta entera");
    printf("\n0 - Salir de la modificacion\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &modificar);


    return modificar;
}

stCuenta modificaPorSeccion (stCuenta cuenta)
{
    int flag=0;
    while(flag==0)
    {
        switch (modificarCuenta())
    {
    case 1:
        printf("Ingrese nuevo tipo de cuenta (1. Caja de Ahorro en Pesos, 2. Caja de Ahorro en Dolares, 3. Cta Cte en $): ");
        scanf("%d", &cuenta.tipoDeCuenta);
        break;
    case 2:
        printf("Ingrese nuevo costo mensual: ");
        scanf("%f", &cuenta.costoMensual);
        break;
    case 3:
        printf("Ingrese de nuevo todos los datos de la cuenta: ");
        cuenta = cargarCuentaIndividual (cuenta);
        break;
    case 0:
        printf("\n Saliendo de modificacion\n");
        flag=1;
        break;
    default:
        printf("Opcion no valida. Intente de nuevo.\n");
        system("pause");
    }
    }

    return cuenta;
}

///hacer funcion que si el ususario tiene una caja de ahorro en pesos y doalres que elija cual quiere modificar

int buscaPosCuentaPorId(char nombreArchivo[], int idBuscado,int nroCuenta)
{
    FILE* archi = fopen(nombreArchivo, "rb");
    int flag = 0;
    int pos = -1;
    stCuenta a;
    if(archi)
    {
        while(flag==0 && fread(&a, sizeof(stCuenta),1, archi)>0)
        {
            if(a.idCliente==idBuscado && a.nroCuenta==nroCuenta)
            {
                flag=1;
                pos=ftell(archi)/sizeof(stCuenta)-1;
            }

        }
        fclose(archi);
    }

    return pos;
}
int buscaPosCuentaPorIdModificacion(char nombreArchivo[], int idBuscado, int tipoCuenta, int opcionSeleccionada) {
    FILE* archi = fopen(nombreArchivo, "rb");
    int pos = -1;  // inicializamos en -1 para indicar que no se encontró
    stCuenta a;
    int cuentaActual = 0;

    if (archi) {
        int currentPos = 0;
        while (fread(&a, sizeof(stCuenta), 1, archi) > 0) {
            if (a.idCliente == idBuscado && a.eliminado == 0) {
                cuentaActual++;
                if (cuentaActual == opcionSeleccionada) {
                    pos = currentPos;  // guardamos la posición actual
                }
            }
            currentPos++;
        }
        fclose(archi);
    }
    return pos;
}

void reemplazaCuentaPos(char nombreArchivo[],stCuenta a, int pos)
{
    FILE* archi=fopen(nombreArchivo, "r+b");
    if(archi)
    {
        fseek(archi,pos* sizeof(stCuenta), SEEK_SET);
        fwrite(&a,sizeof(stCuenta),1, archi);
        fclose(archi);
    }
}

void muestraCuentaPos(char NombreArchivo[], int pos)
{
    stCuenta a;

    FILE* archi =  fopen(NombreArchivo, "rb");
    if(archi)
    {
        fseek(archi, pos*sizeof(stCuenta),SEEK_SET);
        fread(&a, sizeof(stCuenta),1, archi);
        mostrarCuentaIndividual(a);
        fclose(archi);
    }
}

stCuenta cuentaPos(char nombreArchivo[], int pos)
{
    FILE* archi=fopen(nombreArchivo, "rb");
    stCuenta a;
    if(archi)
    {
        fseek(archi,pos*sizeof(stCuenta), SEEK_SET);
        fread(&a,sizeof(stCuenta),1,archi);
        fclose(archi);
    }
    return a;
}

int muestraCuentaEspecificaEliminada(char NombreArchivo[], int BuscarId)
{
    FILE *archi = fopen(NombreArchivo, "rb");
    stCuenta cuenta;
    int numCuentasEncontradas = 0;

    if (archi) {
        while (fread(&cuenta, sizeof(stCuenta), 1, archi) > 0) {
            if (cuenta.idCliente == BuscarId && cuenta.eliminado == -1) {
                numCuentasEncontradas++;
                printf("\nOpción %d:\n", numCuentasEncontradas);
                mostrarCuentaIndividual(cuenta);
            }
        }

        if (numCuentasEncontradas == 0) {
            printf("\nEl cliente tiene cuenta/s activa/s.\n");
        }

        fclose(archi);
    } else {
        printf("Error al abrir el archivo.\n");
    }

    return numCuentasEncontradas;
}

stCuenta altaCuenta (stCuenta cuenta)
{
    cuenta.eliminado=0;

    return cuenta;
}

stCuenta buscaCuentaPorIdClienteNroCuenta(char nombreArchivo[], int idCliente, int nroCuenta)
{
    stCuenta cuenta;
    int flag=0;
    FILE* archi=fopen(nombreArchivo, "rb");
    if(archi)
    {
        while(flag==0 && fread(&cuenta,sizeof(stCuenta),1,archi))
        {

            if(cuenta.idCliente==idCliente&&cuenta.nroCuenta==nroCuenta)
            {
                flag=1;
            }
        }
        fclose(archi);
    }
    return cuenta;
}

void listadoCuentasPorCliente (char NombreArchivo[], int BuscarId)
{
    FILE *archi = fopen(NombreArchivo, "rb");
    stCuenta cuenta;
    int numCuentasEncontradas = 0;

    if (archi) {
        while (fread(&cuenta, sizeof(stCuenta), 1, archi) > 0) {
            if (cuenta.idCliente == BuscarId) {
                mostrarCuentaIndividual(cuenta);
                numCuentasEncontradas++;
            }
        }

        if (numCuentasEncontradas == 0) {
            printf("\nEl cliente no tiene ninguna cuenta activa.\n");
        }

        fclose(archi);
    } else {
        printf("Error al abrir el archivo.\n");
    }

}
