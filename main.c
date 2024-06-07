#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "mock.h"

#define AR_CLIENTES "clientes.dat"

int main()
{
    srand(time(NULL));

    stCliente a;
    a=cargaCliente(AR_CLIENTES);
    muestraCliente(a);
    printf("Listado\n");
    listadoClientes(AR_CLIENTES);

    return 0;
}
