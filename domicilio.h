#ifndef DOMICILIO_H_INCLUDED
#define DOMICILIO_H_INCLUDED

// Definicion de la estructura de Domicilio
typedef struct {

    char calle[30]; //carga calle de direccion
    char nro[6];//carga numero de direccion
    char localidad[50];//carga localidad de direccion
    char provincia[40];//carga provinica de direccion
    char cPos [5];//carga codigo postal de direccion - solo 4 digitos


}stDomicilio;


void muestraDomicilio (stDomicilio d);
stDomicilio cargaDomicilio ();
stDomicilio modificarDomicilio (stDomicilio d);
int menuModifDom();
stDomicilio altaDomicilio (stDomicilio d);
int validarCodigoPostal(char codigoPostal []);

#endif // DOMICILIO_H_INCLUDED
