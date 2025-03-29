#include<stdio.h>
#include<SDL2/SDL.h>

Uint32 WHITE_COLOUR=0xffffffff;
Uint32 BLACK_COLOUR=0x00000000;
Uint32 GREY_COLOUR=0x2f2f2f2f;
int SURFACE_WIDTH=900;
int SURFACE_HEIGHT=600;
int CELL_WIDTH=25;
int LINE_WIDTH=1;

int draw_cell(SDL_Surface* surface,int cell_x,int cell_y,int cell_value){
    int pxl_x=cell_x*CELL_WIDTH;
    int pxl_y=cell_y*CELL_WIDTH;
    Uint32 colour=cell_value==0?BLACK_COLOUR:WHITE_COLOUR;
    
    SDL_Rect cell =(SDL_Rect) {pxl_x,pxl_y,CELL_WIDTH,CELL_WIDTH};
    SDL_FillRect(surface,&cell,colour);
}

int draw_grid(SDL_Surface* surface,int n_rows,int n_columns){
    for (int i=0; i<n_rows; i++){
    SDL_Rect line=(SDL_Rect) {0,i*CELL_WIDTH,SURFACE_WIDTH,LINE_WIDTH};
    SDL_FillRect(surface,&line,GREY_COLOUR);
           }
    for (int i=0; i<n_columns; i++){
    SDL_Rect line=(SDL_Rect) {i*CELL_WIDTH,0,LINE_WIDTH,SURFACE_HEIGHT};
    SDL_FillRect(surface,&line,GREY_COLOUR);
           }
}

void draw_matrix(SDL_Surface* surface,int n_rows,int n_columns,int* game_matrix){

    for(int i=0;i<n_rows;i++){

        for(int j=0;j<n_columns;j++){
           int cell_value=*(game_matrix+ i*n_columns +j);
            draw_cell(surface,j,i,cell_value);
          }

      }

}

void init_game_matrix(int n_rows,int n_columns,int* game_matrix){
    for(int i=0;i<n_rows;i++){

        for(int j=0;j<n_columns;j++){
           *(game_matrix+i*n_columns+j)= rand()%2;  

          }

      }
 }







int main(){
    printf("conways_game_of_life..\n");
    SDL_Init(SDL_INIT_VIDEO);
    char* title ="Conway Game Of LIfe\n";

    int n_rows=SURFACE_HEIGHT/CELL_WIDTH;
    int n_columns=SURFACE_WIDTH/CELL_WIDTH;

    SDL_Window* window = SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SURFACE_WIDTH,SURFACE_HEIGHT,0);
    SDL_Surface* surface= SDL_GetWindowSurface(window);









    int game_matrix [n_rows][n_columns];
    init_game_matrix(n_rows,n_columns,game_matrix[0]);
    draw_matrix(surface,n_rows,n_columns,game_matrix[0]);


    draw_grid(surface,n_rows,n_columns);
    SDL_UpdateWindowSurface(window);
    SDL_Delay(5000);
}









































