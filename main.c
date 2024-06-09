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
    char algo[20];
    getTelefonoRandom(algo);
    printf("%s \n", algo);

    getCliente2ArchivoRandom(AR_CLIENTES);
    printf("Listado\n");
    listadoClientes(AR_CLIENTES);

    return 0;
}
