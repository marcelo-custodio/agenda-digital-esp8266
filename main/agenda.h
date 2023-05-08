#ifndef __AGENDA__
#define __AGENDA__

#include <stdint.h>

typedef struct {
    char nome[20];
    char telefone[14];
    char endereco[30];
}tipo_registro;

void inicializa_agenda(void);
void le_registro (uint16_t numero_do_registro, tipo_registro &R);
void salva_registro(uint16_t numero_do_registro, tipo_registro R);
void lista_todos_os_registros();

#endif