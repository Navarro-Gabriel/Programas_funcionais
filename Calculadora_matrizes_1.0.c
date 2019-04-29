#include <stdio.h>
#include <stdlib.h>

void leitura_de_tamanho_das_matrizes();
void leitura_de_numeros_das_matrizes();
void menu_operacoes();
void menu_identificacao();
void soma_matrizes();
void mostrar_resultado_da_soma();
void subtracao_matrizes();
void mostrar_resultado_da_subtracao();
void multiplicacao_matrizes();
void mostrar_resultado_da_multiplicacao();
void identificar_tipos_especiais_de_matrizes();

int main()
{
  int opcao;

  printf("Selecione uma das opções abaixo: \n");
  printf("1 - Realizar operações matematicas com matrizes \n");
  printf("");
  leitura_de_tamanho_das_matrizes();
  printf("Desenvolvido por: Gabriel Navarro.");
  return 0;
}

void leitura_de_tamanho_das_matrizes(int quantidade_linhas_matriz_a, int quantidade_colunas_matriz_a, int quantidade_linhas_matriz_b, int quantidade_colunas_matriz_b)
{
    printf("Insira as dimensões da matriz A: \n");
    printf("Quantidade de linhas = ");
    scanf("%d", &quantidade_linhas_matriz_a);
    printf("Quantidade de colunas = ");
    scanf("%d", &quantidade_colunas_matriz_a);
    printf("----------------------------------------");
    printf("\nInsira as dimensões da matriz B: \n");
    printf("Quantidade de linhas = ");
    scanf("%d", &quantidade_linhas_matriz_b);
    printf("Quantidade de colunas = ");
    scanf("%d", &quantidade_colunas_matriz_b);
    printf("\n\n****************************************\n");

    leitura_de_numeros_das_matrizes(quantidade_linhas_matriz_a, quantidade_linhas_matriz_b, quantidade_colunas_matriz_a, quantidade_colunas_matriz_b);
}

void leitura_de_numeros_das_matrizes(int quantidade_linhas_matriz_a, int quantidade_linhas_matriz_b, int quantidade_colunas_matriz_a, int quantidade_colunas_matriz_b)
{
  int linha_matriz_a, linha_matriz_b, coluna_matriz_a, coluna_matriz_b;
  int matriz_a[quantidade_linhas_matriz_a][quantidade_colunas_matriz_a], matriz_b[quantidade_linhas_matriz_b][quantidade_colunas_matriz_b];

  printf("Insira os valores da matriz A: \n");
  for(linha_matriz_a = 0; linha_matriz_a < quantidade_linhas_matriz_a; linha_matriz_a ++)
  {
    for(coluna_matriz_a = 0; coluna_matriz_a < quantidade_colunas_matriz_a; coluna_matriz_a ++)
    {
      scanf("%d", &matriz_a[linha_matriz_a][coluna_matriz_a]);
    }
  }

  printf("----------------------------------------\n");

  printf("Insira os valores da matriz B: \n");
  for(linha_matriz_b = 0; linha_matriz_b < quantidade_linhas_matriz_b; linha_matriz_b ++)
  {
    for(coluna_matriz_b = 0; coluna_matriz_b < quantidade_colunas_matriz_b; coluna_matriz_b ++)
    {
      scanf("%d", &matriz_b[linha_matriz_b][coluna_matriz_b]);
    }
  }
  printf("****************************************\n\n");
  /*
    Colocar para ler os numeros em forma de matrizes
  */

  menu_operacoes(quantidade_linhas_matriz_a, quantidade_linhas_matriz_b, quantidade_colunas_matriz_a, quantidade_colunas_matriz_b, matriz_a, matriz_b);
}

void menu_operacoes(int quantidade_linhas_matriz_a, int quantidade_linhas_matriz_b, int quantidade_colunas_matriz_a, int quantidade_colunas_matriz_b, int matriz_a[][quantidade_colunas_matriz_a], int matriz_b[][quantidade_colunas_matriz_b])
{
  int opcao;
  printf("----------------------------------------\n");
  printf("Selecione a operação que deseja realizar: \n");
  printf("1 - Soma de matrizes \n");
  printf("2 - Subtração de matrizes \n");
  printf("3 - Multiplicação de matrizes \n");
  printf("4 - Sair do programa ");
  printf("\n----------------------------------------\n");
  scanf("%d", &opcao);


  switch(opcao)
  {
    case 1:
      if(quantidade_linhas_matriz_a == quantidade_linhas_matriz_b && quantidade_colunas_matriz_a == quantidade_colunas_matriz_b)
      {
        soma_matrizes(quantidade_linhas_matriz_a, quantidade_linhas_matriz_b, quantidade_colunas_matriz_a, quantidade_colunas_matriz_b, matriz_a, matriz_b);
        //printf("O resultado da Soma das matrizes A e B é: \n");
      }
        else
        {
          printf("Para ser realizada a Soma das matrizes A e B é nescessario que ambas tenham a mesma quantidade de linhas e colunas\n");
          printf("Reinicie o programa e tente novamente. \n");
        }
      break;
    case 2:
      if(quantidade_linhas_matriz_a == quantidade_linhas_matriz_b && quantidade_colunas_matriz_a == quantidade_colunas_matriz_b)
      {
        subtracao_matrizes(quantidade_linhas_matriz_a, quantidade_linhas_matriz_b, quantidade_colunas_matriz_a, quantidade_colunas_matriz_b, matriz_a, matriz_b);
        //printf("O resultado da Subtração das matrizes A e B é \n");
      }
        else
        {
          printf("Para ser realizada a Subtração das matrizes A e B é nescessario que ambas tenham a mesma quantidade de linhas e colunas\n");
          printf("Reinicie o programa e tente novamente. \n");
        }
      break;
    case 3:
      if(quantidade_colunas_matriz_a == quantidade_linhas_matriz_b)
      {
        multiplicacao_matrizes(quantidade_linhas_matriz_a, quantidade_linhas_matriz_b, quantidade_colunas_matriz_a, quantidade_colunas_matriz_b, matriz_a, matriz_b);
        //printf("O resultado da Multiplicação das matrizes A e B é \n");
      }
        else
        {
          printf("Para ser realizado o Produto das matrizes A e B é nescessario que o numero de colunas da matriz A seja igual ao numero de linhas da matriz B\n");
          printf("Reinicie o programa e tente novamente. \n");
        }
      break;
    case 4:
      printf("\n\n----------------------------------------\n");
      printf("Obrigado por usar o nosso software.");
      printf("\n----------------------------------------\n");
      break;
    default:
      printf("\n\n----------------------------------------\n");
      printf("Opção invalida!");
      printf("\nReinicie o programa e tente novamente.");
      printf("\n----------------------------------------\n");
      break;
  }
}

void soma_matrizes(int quantidade_linhas_matriz_a, int quantidade_linhas_matriz_b, int quantidade_colunas_matriz_a, int quantidade_colunas_matriz_b, int matriz_a[][quantidade_colunas_matriz_a], int matriz_b[][quantidade_colunas_matriz_b])
{
  int matriz_c[quantidade_linhas_matriz_a][quantidade_colunas_matriz_a], posicao_linha, posicao_coluna;

  for(posicao_linha = 0; posicao_linha < quantidade_linhas_matriz_a; posicao_linha ++)
  {
    for(posicao_coluna = 0; posicao_coluna < quantidade_colunas_matriz_a; posicao_coluna ++)
    {
      matriz_c[posicao_linha][posicao_coluna] = matriz_a[posicao_linha][posicao_coluna] + matriz_b[posicao_linha][posicao_coluna];
    }
  }

  mostrar_resultado_da_soma(quantidade_linhas_matriz_a, quantidade_colunas_matriz_a, matriz_c);
}

void mostrar_resultado_da_soma(int quantidade_linhas_matriz_a, int quantidade_colunas_matriz_a, int matriz_c[][quantidade_colunas_matriz_a])
{
  int posicao_linha, posicao_coluna;

  printf("****************************************\n");
  printf("O resultado da soma das matrizes é: \n\n");
  printf("\n");
  for(posicao_linha = 0; posicao_linha < quantidade_linhas_matriz_a; posicao_linha ++)
  {
    for(posicao_coluna = 0; posicao_coluna < quantidade_colunas_matriz_a; posicao_coluna ++)
    {
      printf("%d", matriz_c[posicao_linha][posicao_coluna]);
      printf("\t");
    }
    printf("\n");
  }
  printf("****************************************\n\n");

  /*
    1. Falta colocar para a matriz ser impressa na frente da frase " O resultado da soma das matrizes e:"
    2. Falta dividir todas as seçoes do programa com '-' ou '*'
  */
}

void subtracao_matrizes(int quantidade_linhas_matriz_a, int quantidade_linhas_matriz_b, int quantidade_colunas_matriz_a, int quantidade_colunas_matriz_b, int matriz_a[][quantidade_colunas_matriz_a], int matriz_b[][quantidade_colunas_matriz_b])
{
  int matriz_c[quantidade_linhas_matriz_a][quantidade_colunas_matriz_a], posicao_linha, posicao_coluna;

  for(posicao_linha = 0; posicao_linha < quantidade_linhas_matriz_a; posicao_linha ++)
  {
    for(posicao_coluna = 0; posicao_coluna < quantidade_colunas_matriz_a; posicao_coluna ++)
    {
      matriz_c[posicao_linha][posicao_coluna] = matriz_a[posicao_linha][posicao_coluna] - matriz_b[posicao_linha][posicao_coluna];
    }
  }

      mostrar_resultado_da_subtracao(quantidade_linhas_matriz_a, quantidade_colunas_matriz_a, matriz_c);
}

void mostrar_resultado_da_subtracao(int quantidade_linhas_matriz_a, int quantidade_colunas_matriz_a, int matriz_c[][quantidade_colunas_matriz_a])
{
  int posicao_linha, posicao_coluna;

  printf("\n\n****************************************\n");
  printf("O resultado da subtração das matrizes é: \n\n");
  printf("\n");
  for(posicao_linha = 0; posicao_linha < quantidade_linhas_matriz_a; posicao_linha ++)
  {
    for(posicao_coluna = 0; posicao_coluna < quantidade_colunas_matriz_a; posicao_coluna ++)
    {
      printf("%d", matriz_c[posicao_linha][posicao_coluna]);
      printf("\t");
    }
    printf("\n");
  }
  printf("****************************************\n\n");

}

void multiplicacao_matrizes(int quantidade_linhas_matriz_a, int quantidade_linhas_matriz_b, int quantidade_colunas_matriz_a, int quantidade_colunas_matriz_b, int matriz_a[][quantidade_colunas_matriz_a], int matriz_b[][quantidade_colunas_matriz_b])
{
  int posicao_linha, posicao_coluna, dimensao_comum, somaproduto, matriz_c[quantidade_linhas_matriz_a][quantidade_colunas_matriz_b];

  for(posicao_linha = 0; posicao_linha < quantidade_linhas_matriz_a; posicao_linha ++)
  {
    for(posicao_coluna = 0; posicao_coluna < quantidade_colunas_matriz_b; posicao_coluna ++)
    {
      somaproduto = 0;
      for(dimensao_comum = 0; dimensao_comum < quantidade_colunas_matriz_a; dimensao_comum ++)
      {
        somaproduto += matriz_a[posicao_linha][dimensao_comum] * matriz_b[dimensao_comum][posicao_coluna];
      }
      matriz_c[posicao_linha][posicao_coluna] = somaproduto;
    }
  }

  mostrar_resultado_da_multiplicacao(quantidade_linhas_matriz_a, quantidade_colunas_matriz_b, matriz_c);
}

void mostrar_resultado_da_multiplicacao(int quantidade_linhas_matriz_a, int quantidade_colunas_matriz_b, int matriz_c[][quantidade_colunas_matriz_b])
{
  int posicao_linha, posicao_coluna;

  printf("\n\n****************************************\n");
  printf("O produto das matrizes é: \n\n");
  printf("\n");
  for(posicao_linha = 0; posicao_linha < quantidade_linhas_matriz_a; posicao_linha ++)
  {
    for(posicao_coluna = 0; posicao_coluna < quantidade_colunas_matriz_b; posicao_coluna ++)
    {
      printf("%d", matriz_c[posicao_linha][posicao_coluna]);
      printf("\t");
    }
    printf("\n");
  }
  printf("****************************************\n\n");
}

void identificar_tipos_especiais_de_matrizes()
{

}
