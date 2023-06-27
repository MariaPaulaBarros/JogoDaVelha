// Online C compiler to run C program online
#include <stdio.h>

int mat[3][3] ={{0,0,0},
                {0,0,0},
                {0,0,0}};
                
int matriz [3][3] = {{1,2,3},
                     {4,5,6},
                     {7,8,9}}; 
            
static int  codX = 1;
static int  codO = 2;

mostrarTabuleiro(){
    int x,y,valor;
    for(x=0;x<3;x++){
        for(y=0;y<3;y++){
            valor = mat[x][y];
            if(valor == codX){
                printf("_X_");
            }else if(valor == codO){
                printf("_O_");
            }else{
                printf("___");
            }
            
            if(y<2){
                printf(" | ");
            }    
        }       
        printf("\n");   
    }
}


 mostrarPosicaoTabuleiro(){
    int x,y;
    for(x=0;x<3;x++){
        for(y=0;y<3;y++){
            printf("%d " ,matriz[x][y]);
        }       
        printf("\n");   
    }
 }   
 
 int preencherTabuleiro(int decisaoJogador, int codJogador){
    int x,y,valor;
    for(x=0;x<3;x++){
        for(y=0;y<3;y++){
            valor = matriz[x][y];
            
            if(valor == decisaoJogador){
                if(mat[x][y] == 0){
                    mat[x][y] = codJogador;
                    return 1;
                }
                return 0;    
            }
        }
    }
    return 0;
}

int verificarVitoria(){
    if(mat[0][0] == mat[0][1] && mat[0][1] == mat[0][2]){
        return mat[0][0];
    }else if(mat[1][0] == mat[1][1] && mat[1][1] == mat[1][2]){
        return mat[1][0];
    }else if(mat[2][0] == mat[2][1] && mat[2][1] == mat[2][2]){
        return mat[2][0];
    }
    
    
    if(mat[0][0] == mat[1][0] && mat[1][0] == mat[2][0]){
        return mat[0][0];
    }else if(mat[0][1] == mat[1][1] && mat[1][1] == mat[2][1]){
        return mat[0][1];
    }else if(mat[0][2] == mat[1][2] && mat[1][2] == mat[2][2]){
        return mat[0][2];
    }
    
    
    if(mat[0][0] == mat[1][1] && mat[1][1] == mat[2][2]){
        return mat[0][0];
    }else if(mat[2][0] == mat[1][1] && mat[1][1] == mat[0][2]){
        return mat[2][0];
    }
    return 0;
}
 


int main() {

    int decisaoJogador = 0, decisao, rodada=0, retorno=0;
    printf("Jogo da Velha # \n");
    
    do{
        printf("Veja o mapa(posições) do tabuleiro : \n");
        mostrarPosicaoTabuleiro(); 
        
        if(rodada %2 == 0){
            printf("Escolha a posição que deseja colocar o -> X :") ;
            scanf("%d",&decisaoJogador); 
            retorno = preencherTabuleiro(decisaoJogador, codX);
            
            
        }else{
            printf("Escolha a posição que deseja colocar o -> O :") ;
            scanf("%d",&decisaoJogador);
            retorno = preencherTabuleiro(decisaoJogador, codO);
        }
        
       
        if(retorno>0){
            mostrarTabuleiro();
            int decisao = verificarVitoria();
            if(decisao == codX){
                printf("Jogador X ganhou!!");
                break;
            }else if (decisao == codO){
                printf("Jogador O ganhou!!");
                break;
            } 
            rodada++; 
        }else{
            printf("Posição inválida,tente novamente \n");
            
        }
        
        
    }while(rodada<9);
    if(decisao == 0){
    printf(" Empatou!!");
    }
    
    
    return 0;
}