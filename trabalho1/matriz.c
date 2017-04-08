#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriz.h"

int ALGARISMOS[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //0 - 9


void zeraArrayDeAlgarismos() {

  int i = 0;

  for ( i = 0; i < 10; i++ ) {
    ALGARISMOS[i] = 0;
  }

}

void mostraMatriz(tipo_matriz v[100] [8]) {

  int i = 0, j = 0;

  for (i = 0; i < 100; i++) {

    for (j = 0; j < 8; j++) {

      printf("%d", v[i][j]);

    }

    printf("\n");

  }

}

int geraValor() {

  return rand() % 10;

}

void criaVetorIndividuos(tipo_matriz v[100] [8]) {

  int i = 0, j = 0, valorRando = 0, buscaAlgarismo = 0;

  while(i < 100) {

    for (j = 0; j < 9; j++) {

      valorRando = geraValor();

      if ( ALGARISMOS[valorRando] == 1 ) {

        while ( ALGARISMOS[valorRando] == 1 ) {

          if ( valorRando == 9) {

            valorRando = 0;

          } else {

            valorRando++;

          }

        }

      }

      v[i][j] = valorRando;
      ALGARISMOS[valorRando] = 1;


    }

    zeraArrayDeAlgarismos();

    i++;

  }

  mostraMatriz(v);

}
