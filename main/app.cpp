/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "serial.h"
#include "memoria.h"
#include "agenda.h"
#include <inttypes.h> 


 
extern "C" void app_main() ;
int v=0;

void app_main()
{

  /*char leitura[100];

  serial.begin(9600);
  printf("Entre com o nome: ");
  
  serial.readString((uint8_t *)leitura,10);
  printf("%s\n",leitura);
  
  printf("Entre com o Endereco: ");
  serial.readString((uint8_t *)leitura,10);
  printf("%s\n",leitura);
  
  printf("Entre com o telefone: ");
  serial.readString((uint8_t *)leitura,10);
  printf("%s\n",leitura);*/

  serial.begin(9600);
  
  printf("MENU\n");
  printf("[1] - Lista todos os registros\n");
  printf("[2] - Pesquisa registro por nome\n");
  printf("[3] - Pesquisa registro por telefone\n");
  printf("[4] - Remove registro baseado no telefone\n");
  printf("[5] - Mostra a quantidade de registros atualmente armazenados\n");
  printf("[6] - Inicializa o banco de dados (todas as informacões armazenadas serão perdidas)\n");
  char opcao = serial.readChar();

  switch (opcao)
  {
  	case '1':
  		printf("Opcao 0 selecionada\n");

      lista_todos_os_registros();

  		break;
  	case '2':
  		printf("Digite o nome a ser pesquisado: \n");
      scanf("%s", pesquisa_nome);

      pesquisa_registro_nome(pesquisa_nome);

  		break;
    case '3':
      printf("Opcao 2 selecionada\n");
      break;
    case '4':
      printf("Opcao 3 selecionada\n");
      break;
    case '5':
      printf("Opcao 4 selecionada\n");
      break;
    case '6':
      printf("Opcao 5 selecionada\n");
      break;
    default:
      printf("Opcao invalida\n");
      break;
  }
}
