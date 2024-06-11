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
    int idBuscado;
    getCliente2ArchivoRandom(AR_CLIENTES);
    printf("Listado\n");
    listadoClientes(AR_CLIENTES);
    printf("\n ingrese cliente que desea buscar:");
    scanf("%d", &idBuscado);
    muestraCliente(buscaClientePorId(AR_CLIENTES, idBuscado));
    return 0;
}
