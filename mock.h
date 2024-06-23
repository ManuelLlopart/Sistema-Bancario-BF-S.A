#ifndef MOCK_H_INCLUDED
#define MOCK_H_INCLUDED

void getName(char name []);
void getLastName(char lastName []);
void getDni(char dni[]);
void getEmailCliente(stCliente* cliente);
void getTelefonoRandom(char telefono[]);
void getCliente2ArchivoRandom(char nombreArchivo[]);
void getCalle(char calle []);
void getLocalidad (char localidad []);
void getProvincia (char provincia []);
void getCpos (char cpos []);
void getNumDomicilio (char numeroDomicilio []);
stDomicilio getDomicilioRandom();


#endif // MOCK_H_INCLUDED
