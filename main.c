#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
int main()
{
    stCliente cliente;
    cliente=cargaCliente();
    muestraCliente(cliente);
    char *prueba = validarEmail(cliente.email);
    printf("\n %s", prueba);
    return 0;
}
