#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define WIDTH 800
#define HEIGHT 600

#define FPS 30
#define FRAME_TARGET_TIME (1000 / FPS)

/* Global variable */
SDL_Window *window;
SDL_Renderer *renderer;
int game_is_running;
int last_frame_time = 0;

/* function protype */
int initialize_window();
int setup();
int process_input();
int update();
int render();
int destroy_window();

/* Main function*/
int main(int argc, char *argv[])
{
    game_is_running = initialize_window();

    setup();

    while (game_is_running)
    {
        process_input();
        update();
        render();
    }

    destroy_window();

    printf("Hello World\n");
    return 0;
}

int initialize_window()
{
    if (0 != SDL_Init(SDL_INIT_EVERYTHING))
    {
        fprintf(stderr, "Error initialzing SDL!\n");
        return FALSE;
    }
    window = SDL_CreateWindow(
        "UARTerminal",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH, HEIGHT,
        SDL_WINDOW_RESIZABLE);

    if (NULL == window)
    {
        fprintf(stderr, "Error creating SDL Window!\n");
        return FALSE;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (NULL == renderer)
    {
        fprintf(stderr, "Error creating SDL Renderer!\n");
        return FALSE;
    }
    return TRUE;
}

int setup()
{
    return TRUE;
}

int process_input()
{
    SDL_Event windowEvent;

    SDL_PollEvent(&windowEvent);

    switch (windowEvent.type)
    {
    case SDL_QUIT:
        game_is_running = FALSE;
        break;
    case SDL_KEYDOWN:
        if (SDLK_ESCAPE == windowEvent.key.keysym.sym)
            game_is_running = FALSE;
        break;
    default:
        break;
    }

    return TRUE;
}

int update()
{
    // Wait (Sleep) some time until we reach the frame target time 
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), last_frame_time + FRAME_TARGET_TIME));

    last_frame_time = SDL_GetTicks();

    return TRUE;
}

int render()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect rect = {
        30,
        30,
        40,
        40
    };
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderPresent(renderer);
    return TRUE;
}

int destroy_window()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return TRUE;
}