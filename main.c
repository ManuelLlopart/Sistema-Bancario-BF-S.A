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
    return 0;
}
