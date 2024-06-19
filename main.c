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
    char dniBuscado[10];
    int idBuscado;
    getCliente2ArchivoRandom(AR_CLIENTES);
    printf("Listado\n");
    listadoClientes(AR_CLIENTES);
    printf("\n ingrese el id del cliente que desea buscar:");
    scanf("%d", &idBuscado);
    printf("\n ingrese el dni del cliente que desea buscar:");
    fflush(stdin);
    gets(&dniBuscado);
    muestraClientePos(AR_CLIENTES, buscaPosClientePorDni(AR_CLIENTES, dniBuscado));
    printf("\n Hay %d clientes", cuentaCantidadClientes(AR_CLIENTES));
    printf("\n Id buscado por pos : \n");
    muestraClientePos(AR_CLIENTES, buscaPosClientePorId(AR_CLIENTES, idBuscado));

    return 0;
}


