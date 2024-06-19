#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "mock.h"

#define AR_CLIENTES "clientes.dat"
#define AR_CUENTAS "cuentas.dat"

int main()
{
    srand(time(NULL));
    int pos=0;

    getCliente2ArchivoRandom(AR_CLIENTES);
    printf("Listado\n");
    listadoClientes(AR_CLIENTES);
    printf("\n ingrese el pos del cliente que desea buscar:");
    scanf("%d", &pos);
    muestraCliente(clientePos(AR_CLIENTES, pos));



    return 0;
}


