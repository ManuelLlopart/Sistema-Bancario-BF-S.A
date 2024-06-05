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
    getName(a.nombre);
    getLastName(a.apellido);

    getEmailCliente(&a);
    muestraCliente(a);

    return 0;
}
