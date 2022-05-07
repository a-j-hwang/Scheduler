#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//output structure
int output(int cycle, int N, int status[]){
  int i=0;
  int g=0;


  if (cycle>=10) {
      printf("%d       ",cycle);
  }
  else{
      printf("%d        ",cycle);
  }


  for (i = 0; i < N; i++) {
      if (status[i]==1){
        printf("run         ");
      }
      if (status[i]==2){
        printf("ready       ");
      }
      if (status[i]==3){
        printf("blocked     ");
      }
      if (status[i]==4){
        printf("terminate  ");
      }
      if (status[i]==5){
        printf("            ");
      }


    }

  printf("\n");
  return 0;
}

//sum of arrays function
int sumArray(int arr[], int n){
  int val=0;
   for(int i = 0; i<n ; i++){
      val+=arr[i];
   }
   return val;
}

int sumArray6(int arr[], int first){
  int val=0;
   for(int i = first; i<first+6 ; i++){
      val+=arr[i];
   }
   return val;
}



//fifo function
int fifo(int N, char *pVals[]){

  int *values = (int *) malloc(N*4);


  int status[N];int INtime[N];int OUTtime[N];

  int cycle=1;
  int i=0;int g=0;
  int sum;



  for (g=0; g<N*4; g++) {
  values[g]=atoi(pVals[g]);
  }

  int valuesWT[N*6];
  for (g=0; g<N; g++) {
  for (int u = 0; u < 4; u++) {
    valuesWT[g*6+u]=values[g*4+u];
  }
    valuesWT[g*6+4]=1;
    valuesWT[g*6+5]=0;
}

  for (i = 0; i < N; i++) {
    status[i]=2;
    INtime[i]=0;
    OUTtime[i]=0;
  }

  printf("Cycle    ");

  for (i = 0; i < N; i++) {
    printf("P%d          ", i+1);
  }
  printf("\n");

  sum=N*2;
  int index=0;
  int temp;

while (sum<N*5-1) {



//what status for what

      for(int i = 0; i < N; i++){
        for (int j = 0; j < 6; j++) {
          if (valuesWT[6*i+j]>0) {
            if (j%2==1) {
              status[i]=3;
              valuesWT[6*i+j]--;
                INtime[i]=cycle;
            }
            else{
              status[i]=2;
              temp=j;
            }
            goto jump;
          }
        }
        status[i]=5;
        INtime[i]=cycle;
        jump:;
      }

//
index=99;
for (int i = 0; i < N; i++) {
    if(INtime[i] < INtime[index] && status[i]==2){
        index = i;
      }
}

if (index!=99) {
  status[index]=1;
  OUTtime[index]=cycle;
  valuesWT[6*index+temp]--;
}

int val;
  for (int i = 0; i < N; i++) {
    val=sumArray6(valuesWT, i*6);

    if (status[i]==4){
      status[i]=5;
    }

    if (val==0&&status[i]!=5){
      status[i]=4;
    }

}

  sum=sumArray(status, N);

  output(cycle, N, status);
  cycle++;

}

return 0;
}



//rr function
int rr(int N, int qu, char *pVals[]){
  int Q=qu;
    int *values = (int *) malloc(N*4);
    int status[N];int INtime[N];int OUTtime[N];
    int cycle=1;
    int i=0;int g=0;
    int sum;
    for (g=0; g<N*4; g++) {
    values[g]=atoi(pVals[g]);
    }

    int valuesWT[N*6];
    for (g=0; g<N; g++) {
    for (int u = 0; u < 4; u++) {
      valuesWT[g*6+u]=values[g*4+u];
    }
      valuesWT[g*6+4]=1;
      valuesWT[g*6+5]=0;
  }

    for (i = 0; i < N; i++) {
      status[i]=2;
      INtime[i]=0;
      OUTtime[i]=0;
    }

    printf("Cycle    ");

    for (i = 0; i < N; i++) {
      printf("P%d          ", i+1);
    }
    printf("\n");

    sum=N*2;
    int index=0;
    int temp; int prev=98;

  while (sum<N*5-1) {


  //what status for what

        for(int i = 0; i < N; i++){
          for (int j = 0; j < 6; j++) {
            if (valuesWT[6*i+j]>0) {
              if (j%2==1) {
                status[i]=3;
                valuesWT[6*i+j]--;
                INtime[i]=cycle;
              }
              else{
                status[i]=2;
                temp=j;
              }
              goto jump;
            }
          }
          status[i]=5;
          INtime[i]=cycle;
          jump:;
        }

  //

jump2:
  index=99;
  for (int i = 0; i < N; i++) {
      if(INtime[i] < INtime[index] && status[i]==2){
          index = i;
        }
  }

  if (index!=99) {

    if (prev==index) {
      Q--;
    }
    if (Q==0) {
      INtime[index]=cycle;
      Q=qu;
      goto jump2;
    }

    status[index]=1;
    OUTtime[index]=cycle;
    valuesWT[6*index+temp]--;
  }

  int val;
    for (int i = 0; i < N; i++) {
      val=sumArray6(valuesWT, i*6);

      if (status[i]==4){
        status[i]=5;
      }

      if (val==0&&status[i]!=5){
        status[i]=4;
      }

  }

    sum=sumArray(status, N);
    prev=index;
    output(cycle, N, status);
    cycle++;

  }

  return 0;
}


// main function
int main() {
  char val[999];
  scanf("%[^\n]%*c", val);char *p;int i=0;
  int N = atoi(strtok (val," "));
  int ST = atoi(strtok (NULL," "));
  int Q=0;


  if (ST==2){
    Q=atoi(strtok (NULL," "));
  }
  char *pVals[N*4];
  while(p!=NULL) {
    p=(strtok(NULL," "));
    pVals[i]=p;
    i++;
  }

  if (ST==1){
    fifo(N, pVals);
  }

  if (ST==2){
    rr(N, Q,pVals);
  }

   return 0;
}
