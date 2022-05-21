#include<stdlib.h>
#include<stdio.h>
#include<math.h>


void rotas(){
    FILE *f = fopen("tourar9152.tour", "r");
    int a, b;
    fscanf(f, "%d", &a);
    fscanf(f, "%d", &b);
    while (!feof(f)){
        printf("Rotas %d %d\n", a, b);
        a = b;
        fscanf(f, "%d", &b);
    }
    fclose(f);
}

int main(){
    FILE *arquivo = fopen("ar9152.tsp", "r");
    int c;
    float la;
    float lg;
    int N = 9152;
    double cidLa[N];
    double cidLg[N];

    double *grafo;
    grafo = (double*)malloc(N*N*sizeof(double));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            grafo[i*N + j] = 0.;
        }
    }
    

    int k=0;
    while (!feof(arquivo))
    {
        fscanf(arquivo, "%d %f %f", &c, &la, &lg);
        cidLa[k] = la;
        cidLg[k] = lg;
        k++;
    }
    fclose(arquivo);
  float dgrande=0,dpequen;
  float ptodo;
  float ptotal=0;
  float pgrande=1;
  float p;
  int contro=0;
    for (int i = 0; i < N; i++){
        for (int j = i+1; j < N; j++){
          dpequen=sqrt(pow(cidLa[0] - cidLa[1], 2) + pow(cidLg[0] - cidLg[1], 2));
            grafo[i*N + j] = sqrt(pow(cidLa[i] - cidLa[j], 2) + pow(cidLg[i] - cidLg[j], 2));
          pgrande = sqrt(pow(cidLa[i] - cidLa[j], 2) + pow(cidLg[i] - cidLg[j], 2));
          if(grafo[i*N+j]  != 0){
            contro++;
            ptodo+=grafo[i*N+j];
          }
          else if (grafo[i*N+j] > 0){
            pgrande=grafo[i*N+j];
            ptodo+=grafo[i*N+j];
          }
        }
      ptotal++;
      p=ptotal/2;
    }
    rotas();
  printf("cidades diferentes de zero  =  %d\n",contro);
  printf(" distancia media  =  %f\n",ptodo);
  printf("maiores distancias entre si  =  %f\n",pgrande);
  printf("total cidades  =  %f\n",ptotal);
  printf("menores distancia entre si %f\n",dpequen);
  printf("80 do percurso %f\n",ptotal/7.322);
  printf("percurso total %f\n",p);
}