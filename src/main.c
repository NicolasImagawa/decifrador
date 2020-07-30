/* Data de submissao:
 * Nome: Nicolas de Sousa Imagawa
 * RA: 204147
 */

#include <stdio.h>
#include <stdlib.h>

#define TAM_BUFFER 100
char buffer_entrada[TAM_BUFFER];
char buffer_saida[TAM_BUFFER];

const char senha[] = "SENHASECRETA";

char soma_modulo_alfabeto(char c, char b) {

char a0, b0, c0;
//Se o simbolo a ser analisado esta entre A e Z na tabela ASCII
  if (c>='A' && c<='Z') {    
    
//b0, assim como durante a criptografia, eh a letra apontada pelo cursor j subtraida de A, de modo a satisfazer a decodificacao.
    b0 = b -'A';

/*Essa eh uma possivel funcao inversa do modulo. Considerando uma função modulo do da forma: (a + c) % b = d
 Podemos inverter essa equacao para a seguinte forma, com n sendo um inteiro positivo:
 a + c = nb + d => c = nb + d - a
 
 Para o caso em que n eh 0:
 c = (d - a) % b
 
 Fazendo um paralelo com nossa situacao: 
*/ 
    a0 = ((c - 'A') - b0) % ('Z'-'A' + 1);

//Como na codificao a0 eh decrementado de A, devemos incrementa-lo por A.
    a0 = a0 + 'A';

    //printf("a0 = %d\n", a0);

//Ja que existem valores de a0 que estarao abaixo de A, pela maneira como a funcao modulo funciona, devemos somar 26 a a0, para que ele fique dentro do intervalo desejado.
 
    if(a0 < 65)
    {
        a0 = a0 + 26;
    }

    a0 = abs(a0);

    return a0;
  } else return c;
}

int main() {
  int j=0;
  int i=0;

  /* Leitura da string a ser decifrada. */
  fgets(buffer_entrada, TAM_BUFFER, stdin);


  for (i=0; (i<TAM_BUFFER) && (buffer_entrada[i]!='\0') && (buffer_entrada[i]!='\n'); i++) {

    buffer_saida[i] = soma_modulo_alfabeto(buffer_entrada[i], senha[j]);
    j++;
    if (senha[j]=='\0') j=0;
  }
  buffer_saida[i]='\0';


  /* Escrever saida na tela */
  printf("%s\n", buffer_saida);

  return 0;
}
