#include<stdio.h>
#define INF 99999
#define MAX 100

void printMatrix(int d[MAX][MAX],int n){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(d[i][j] == INF){
                printf("%s\t","INF");
            }
            else{
                printf("%d\t",d[i][j]);
            }
        }
        printf("\n");
    }
}

void floydWarshall(int d[MAX][MAX], int n){
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            for(int k = 0;k<n;k++){
                if(d[j][i] + d[i][k] < d[j][k]){
                    d[j][k] = d[j][i] + d[i][k];
                }
            }
        }  
    }

    printf("\nFinal Matrix:\n");
    printMatrix(d,n);
}

int main(){
    int n,d[MAX][MAX];
    printf("Enter the number of vertices(max %d)",MAX);
    if(scanf("%d",&n) !=1 || n<=0 || n>MAX){
        printf("Invalid vertices");
    }
    printf("Enter the weight matrix(use %d for INF)",INF);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            scanf("%d",&d[i][j]);
        }
    }
   
floydWarshall(d,n);
}