#include<stdio.h>
#include<SDL2/SDL.h>
#include<stdlib.h>
#include<time.h>


Uint32 WHITE_COLOUR=0xffffffff;
Uint32 BLACK_COLOUR=0x00000000;
Uint32 GREY_COLOUR=0x2f2f2f2f;
int SURFACE_WIDTH=900;
int SURFACE_HEIGHT=600;
int CELL_WIDTH=10;
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

void draw_matrix(SDL_Surface* surface,int n_rows,int n_columns,int game_matrix []){

    for(int i=0;i<n_rows;i++){

        for(int j=0;j<n_columns;j++){
           int cell_value=game_matrix[j+i*n_columns];
            draw_cell(surface,j,i,cell_value);
          }

      }

}

void init_game_matrix(int n_rows,int n_columns,int game_matrix []){
    for(int i=0;i<n_rows;i++){
        for(int j=0;j<n_columns;j++){
           game_matrix[j+i*n_columns]= rand() > RAND_MAX * 9.0/10.0 ;  

          }

      }
 }

//logic for finding n_neigbors:
int count_neighbors(int i,int j,int n_rows,int n_columns,int game_matrix []){
    int n_neighbour=0;
    //left neg:
    if(j>0)
        n_neighbour+=game_matrix[j-1+i*n_columns];
    //right neg:
    if(j<n_columns-1)
        n_neighbour+=game_matrix[j+1+i*n_columns];
    //top neg:
    if(i>0)
        n_neighbour+=game_matrix[j+(i-1)*n_columns];
    //bottom neg:
    if(j<n_rows-1)
        n_neighbour+=game_matrix[j+(i+1)*n_columns];
    //top lef neg:   
    if(j>0&&i>0)
        n_neighbour+=game_matrix[j-1+(i+1)*n_columns];
    //top right neg:
    if(j<n_columns-1&&i>0)
       n_neighbour+=game_matrix[j+1+(i+1)*n_columns];
    //bott lef neg:   
    if(j>0&&i<n_rows-1)
         n_neighbour+=game_matrix[j-1+(i-1)*n_columns];
    //bott right neg:
    if(j<(n_columns-1)&&i<n_rows-1)
        n_neighbour+=game_matrix[j+1+(i-1)*n_columns];
       
    return n_neighbour;


}

//simulation for game:
void simulation(int n_rows,int n_columns,int game_matrix []){
    int new_game_matrix [n_rows*n_columns];
    for(int i=0;i<n_rows;i++){
        for(int j=0;j<n_columns;j++){
           game_matrix[j+i*n_columns];
            int n_neighbors=count_neighbors(i,j,n_rows,n_columns,game_matrix);
            int current_cell_val=game_matrix[j+i*n_columns];
           //--conways game of life 4 rules-- 
            //rule 1:
            if(current_cell_val!=0 && n_neighbors<2)
                new_game_matrix[j+i*n_columns]=0;
            //rule 2:
            else if (current_cell_val!=0 && (n_neighbors==2||n_neighbors==3))
                new_game_matrix[j+i*n_columns]=1;             
            //rule 3:
            else if (current_cell_val!=0 && n_neighbors > 3)
                new_game_matrix[j+i*n_columns]=0;
           //rule 4:
            else if (current_cell_val==0 && n_neighbors==3)
                new_game_matrix[j+i*n_columns]=1;
            else 
                new_game_matrix[j+i*n_columns]=current_cell_val;

          }

      }

    for(int i=0;i<n_rows*n_columns;i++)
    game_matrix[i]=new_game_matrix[i];


}




int main(){
    printf("conways_game_of_life..\n");
    //seeding the random number generator
    srand(time(NULL));

    SDL_Init(SDL_INIT_VIDEO);
    char* title ="Conway Game Of LIfe\n";

    int n_rows=SURFACE_HEIGHT/CELL_WIDTH;
    int n_columns=SURFACE_WIDTH/CELL_WIDTH;

    SDL_Window* window = SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SURFACE_WIDTH,SURFACE_HEIGHT,0);
    SDL_Surface* surface= SDL_GetWindowSurface(window);
    int game_matrix [n_rows * n_columns];

    init_game_matrix(n_rows,n_columns,game_matrix);    
    SDL_Event event;
    int ongoing_simulation=1;
    while(ongoing_simulation){
        while(SDL_PollEvent(&event)){
                if(event.type==SDL_QUIT){ongoing_simulation=0;}
        }
    simulation(n_rows,n_columns,game_matrix);    
    draw_matrix(surface,n_rows,n_columns,game_matrix);
    draw_grid(surface,n_rows,n_columns);
    SDL_UpdateWindowSurface(window);
    SDL_Delay(100);
    }
}









































