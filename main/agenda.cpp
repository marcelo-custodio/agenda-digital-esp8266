#include "agenda.h"
#include "memoria.h"

void inicializa_agenda(void) {
    memoria.escreve(0, {0 0}, sizeof(uint16_t));
    return;
}
void le_registro (uint16_t numero_do_registro, tipo_registro &R) {
    return;
}
void salva_registro(uint16_t numero_do_registro, tipo_registro R) {
    return;
}

void lista_todos_os_registros() {
    uint16_t num;
    tipo_registro* buffer;

    Memoria.le(0, &num, sizeof(uint16_t));   //Acho que dá pra passar o valor para o num por referência ao chamar a função Memoria.le()

    //printf("%d", (int*)num);  //Testa valor lido no índice da agenda

    if(num == 0){   //Checa quantidade de registros
        printf("Não há registros!");
    }
    else{
        for(uint8_t i = 0; i < num; i++){
            Memoria.le(1+i*sizeof(tipo_registro), buffer, sizeof(tipo_registro));   //Lê o endereço na memória de cada registro 

            printf("Registro %d /n", i+1)
            printf("Nome: %s /n", buffer->nome);
            printf("Telefone: %s /n", buffer->telefone);
            printf("Endereco: %s /n", buffer->endereco);
        }

    }
}