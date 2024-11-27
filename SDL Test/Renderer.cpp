#include "Renderer.h"
#include "SDLCLasses.h"
#include "SDL.h"
#include "Image.h"
Renderer* Renderer::s_instance = nullptr;

Renderer::Renderer()
{
    // creates a renderer if it doesnt exist
    SDLClasses::GetRenderer();
    SDLClasses::GetWindow();
}

Image* Renderer::AddImage(const char* Path)
{
	m_StoredImages.insert({ Path, new Image(Path) });
    return m_StoredImages.at(Path);
}

void Renderer::DrawImage(Image* img, SDL_Rect* rect)
{
	SDL_RenderCopy(SDLClasses::GetRenderer(), img->GetTexture(), NULL, rect);
}

Renderer* Renderer::Get()
{
    return s_instance != nullptr ? s_instance : s_instance = new Renderer();
}
