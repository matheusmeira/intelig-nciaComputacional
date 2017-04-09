#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriz.h"

int aptidao[100];

void calcAptidao(tipo_matriz v[100] [8]) {

  int i = 0, quartoDigito = 0, terceiroDigito = 0, segundoDigito = 0, primeiroDigito = 0, aux = 0;

  while (i < 100) {

    quartoDigito = v[i][1] + v[i][3];
    if ( quartoDigito >= 10) {
      aux = 1;
      quartoDigito = quartoDigito - 10;
    }

    terceiroDigito = v[i][2] + v[i][6] + aux;
    aux = 0;
    if ( terceiroDigito >= 10 ) {
      aux = 1;
      terceiroDigito = terceiroDigito - 10;
    }

    segundoDigito = v[i][1] + v[i][5] + aux;
    aux = 0;
    if ( segundoDigito >= 10 ) {
      aux = 1;
      segundoDigito = segundoDigito - 10;
    }

    primeiroDigito = v[i][0] + v[i][4] + aux;

    aptidao[i] = (primeiroDigito * 1000) + (segundoDigito * 100) + (terceiroDigito * 10) + quartoDigito;

    i++;

  }

}

int main() {

  srand(time(NULL));

  tipo_matriz individuos[100][8];

  criaVetorIndividuos(individuos);

  calcAptidao(individuos);

}
