#ifndef __AGENDA__
#define __AGENDA__

#include <stdint.h>
#include <string.h>

typedef struct {
    char nome[20];
    char telefone[14];
    char endereco[30];
}tipo_registro;

tipo_registro* buffer;
char pesquisa_nome[20];

void inicializa_agenda(void);
void le_registro (uint16_t numero_do_registro, tipo_registro &R);
void salva_registro(uint16_t numero_do_registro, tipo_registro R);
void pesquisa_registro_nome(char& nome_registro);
void lista_todos_os_registros();

#endif