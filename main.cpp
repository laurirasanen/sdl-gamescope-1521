#include <format>
#include <iostream>
#include <ostream>
#include <stdexcept>

#include <SDL.h>
#include <SDL_events.h>
#include <SDL_mouse.h>

class Window
{
  public:
    Window();
    ~Window();

    bool Update();

  private:
    SDL_Window* m_window;
};

Window::Window()
{
    std::cout << std::format(
        "Creating window, SDL version: {}.{}.{}",
        SDL_MAJOR_VERSION,
        SDL_MINOR_VERSION,
        SDL_PATCHLEVEL
    ) << std::endl;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << std::format("SDL could not initialize. SDL_Error: {}", SDL_GetError())
                  << std::endl;
        throw std::runtime_error("Failed to create window");
    }

    m_window = SDL_CreateWindow(
        "sdl-gamescope-1521",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        800,
        600,
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
    );

    if (m_window == nullptr)
    {
        std::cout << std::format("Window could not be created. SDL_Error: {}", SDL_GetError())
                  << std::endl;
        throw std::runtime_error("Failed to create window");
    }

    SDL_SetRelativeMouseMode(SDL_TRUE);

    std::cout << "Window created" << std::endl;
}

Window::~Window()
{
    std::cout << "Destroying window" << std::endl;
    if (m_window != nullptr)
    {
        SDL_DestroyWindow(m_window);
    }
    SDL_Quit();
}

bool Window::Update()
{
    for (SDL_Event event; SDL_PollEvent(&event) != 0;)
    {
        if (event.type == SDL_QUIT)
        {
            return false;
        }

        if (event.type == SDL_MOUSEMOTION)
        {
            std::cout << std::format("SDL_MOUSEMOTION {} {}", event.motion.xrel, event.motion.yrel)
                      << std::endl;
        }

        if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.scancode == SDL_SCANCODE_SPACE)
            {
                SDL_SetRelativeMouseMode(
                    SDL_GetRelativeMouseMode() == SDL_TRUE ? SDL_FALSE : SDL_TRUE
                );
            }
        }
    }

    return true;
}

int main(int argc, char** argv)
{
    auto window = Window();
    while (window.Update())
    {
    }
    return 0;
}
