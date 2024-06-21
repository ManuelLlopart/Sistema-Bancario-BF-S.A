
#endif // PROYECTOFINAL_H_INCLUDED


stDomicilio muestraDomicilio (stDomicilio, domicilio1);
stDomicilio cargaDomicilio ();
stDomicilio modificarDomicilio (stDomicilio d);
int menuModif();
stDomicilio altaDomicilio (stDomicilio d);
int validarCodigoPostal(char* cPos);

// Definición de la estructura de Domicilio
typedef struct
{

    char calle[30];
    char nro[6];
    char localidad[50];
    char provincia[40];
    char CPos [5];


} stDomicilio;
