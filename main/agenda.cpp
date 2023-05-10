#include "agenda.h"
#include "memoria.h"

void convert_buffer(){  //Converte o vetor uint8_t* buffer_memoria que é lido da memória para um buffer do tipo do registro para que a manipulação seja mais fácil 
    uint8_t i;
    for(i = 0; i < 20; i++){    //Os primeiros 20 char são correspondentes ao nome
        buffer.nome[i]= buffer_memoria[i];
    }
    for(i = 20; i < 34; i++){   //Os próximos 14 char são correspondentes ao telefone
        buffer.telefone[i]= buffer_memoria[i];
    }
    for(i = 34; i < 64; i++){   //Os próximos 30 char são correspondentes ao endereço
        buffer.endereco[i]= buffer_memoria[i];
    }

    return;
}

void inicializa_agenda(void) {
    Memoria.escreve(0, {0 0}, sizeof(uint16_t));   //Zera quantidade de registros no índice da memória
    return;
}
void le_registro (uint16_t numero_do_registro, tipo_registro &R) {
    return;
}
void salva_registro(uint16_t numero_do_registro, tipo_registro R) {
    return;
}

void pesquisa_registro_nome(char nome_registro[20]){
    uint8_t num[2];

    Memoria.le(0, &num, 2*sizeof(uint8_t));  //Lê a quantidade de registros

    if((uint16_t*)num == 0){   //Checa quantidade de registros
        printf("Não há registros para pesquisar!");
    }
    else{
        for(uint16_t i = 1; i <= (uint16_t*)num; i++){
            Memoria.le(2+i*sizeof(tipo_registro), buffer_memoria, sizeof(tipo_registro));   //Lê o endereço na memória de cada registro 

            convert_buffer();

            if(buffer->nome == nome_registro){  //Verifica se o nome fornecido é igual a algum nome registrado
                printf("Registro %d \n", i+1);
                printf("Nome: %s \n", buffer.nome);
                printf("Telefone: %s \n", buffer.telefone);
                printf("Endereco: %s \n", buffer.endereco);

                return;
            }
        }

    }

    return;
}

void pesquisa_registro_telefone(char telefone_registro[20]){
    uint8_t num[2];

    Memoria.le(0, &num, 2*sizeof(uint8_t));  //Lê a quantidade de registros

    if((uint16_t*)num == 0){   //Checa quantidade de registros
        printf("Não há registros para pesquisar!");
    }
    else{
        for(uint16_t i = 1; i <= (uint16_t*)num; i++){
            Memoria.le(2+i*sizeof(tipo_registro), buffer_memoria, sizeof(tipo_registro));   //Lê o endereço na memória de cada registro 

            convert_buffer();

            if(buffer->telefone == telefone_registro){  //Verifica se o nome fornecido é igual a algum telefone registrado
                printf("Registro %d \n", i);
                printf("Nome: %s \n", buffer.nome);
                printf("Telefone: %s \n", buffer.telefone);
                printf("Endereco: %s \n", buffer.endereco);

                return;
            }
        }

    }

    return;
}

void remove_registro(char& telefone_registro){
    uint8_t num[2];
    uint16_t pos;   //Posição do registro a ser excluído

    Memoria.le(0, &num, 2*sizeof(uint8_t));  //Lê a quantidade de registros

    if((uint16_t*)num == 0){   //Checa quantidade de registros
        printf("Não há registros para pesquisar!");
    }
    else{
        for(uint16_t i = 1; i <= (uint16_t*)num; i++){
            Memoria.le(2+i*sizeof(tipo_registro), buffer_memoria, sizeof(tipo_registro));   //Lê o endereço na memória de cada registro 

            convert_buffer();

            if(buffer->telefone == telefone_registro){  //Verifica se o nome fornecido é igual a algum nome registrado
                pos = i;    //Guarda a posição do registro a ser removido

                Memoria.le(2+(uint16_t*)num*sizeof(tipo_registro), buffer_memoria, sizeof(tipo_registro));  //Guarda o último registro da agenda

                Memoria.escreve(2+pos, buffer_memoria, sizeof(tipo_registro));  //Escreve o último registro da agenda sobre o registro removido

                (uint16_t*)num-=1;
                Memoria.escreve(0, &num, sizeof(uint16_t)); //Atualiza a o índice da agenda

                return;
            }
        }
    }

    return;
}

void lista_todos_os_registros() {
    uint8_t num[2];

    Memoria.le(0, &num, 2*sizeof(uint8_t));   //Acho que dá pra passar o valor para o num por referência ao chamar a função Memoria.le()

    //printf("%d", (int*)num);  //Testa valor lido no índice da agenda

    if((uint16_t*)num == 0){   //Checa quantidade de registros
        printf("Não há registros!");
    }
    else{
        for(uint16_t i = 1; i <= (uint16_t*)num; i++){
            Memoria.le(1+i*sizeof(tipo_registro), buffer_memoria, sizeof(tipo_registro));   //Lê o endereço na memória de cada registro 

            convert_buffer();

            printf("Registro %d \n", i);
            printf("Nome: %s \n", buffer.nome);
            printf("Telefone: %s \n", buffer.telefone);
            printf("Endereco: %s \n", buffer.endereco);
        }

    }

    return;
}
