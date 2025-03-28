#include<stdio.h>
#include<SDL2/SDL.h>

Uint32 WHITE_COLOUR=0xffffffff;
int SURFACE_WIDTH=900;
int SURFACE_HEIGHT=600;
int CELL_WIDTH=25;
int LINE_WIDTH=2;

int draw_grid(SDL_Surface* surface,int n_rows,int n_columns){
    for (int i=0; i<n_rows; i++){
    SDL_Rect line=(SDL_Rect) {0,i*CELL_WIDTH,SURFACE_WIDTH,LINE_WIDTH};
    SDL_FillRect(surface,&line,WHITE_COLOUR);
           }
    for (int i=0; i<n_columns; i++){
    SDL_Rect line=(SDL_Rect) {i*CELL_WIDTH,0,LINE_WIDTH,SURFACE_HEIGHT};
    SDL_FillRect(surface,&line,WHITE_COLOUR);
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

    SDL_Rect rect =(SDL_Rect) {30,30,30,30};
    SDL_FillRect(surface,&rect,WHITE_COLOUR);


    draw_grid(surface,n_rows,n_columns);

    SDL_UpdateWindowSurface(window);
    SDL_Delay(5000);
}









































