#include "../include/menu.h"
#define BUTTON_FONT "/Users/pierce/Documents/programming/projects/chess/assets/fonts/Pacifico.ttf"

void Chess::Menu::initButtons()
{
	m_PlayButton = new Button(m_Renderer, "Play", BUTTON_FONT);
	m_QuitButton = new Button(m_Renderer, "Quit", BUTTON_FONT);
}

void Chess::Menu::setButtonProperty()
{
	m_PlayButton->setFontSize(50);
	m_QuitButton->setFontSize(50);
	// Play button 
	m_PlayButton->setPosition(100,100);
	// Quit button
	m_QuitButton->setPosition(100,400);

}

Chess::Menu::Menu(SDL_Renderer* p_Renderer)
	: m_Renderer(p_Renderer)
{
	initButtons();
	setButtonProperty();
	// later add texture to the Background and button 
}

void Chess::Menu::DisplayMenu()
{
	SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_Renderer);

	m_PlayButton->render();
	m_QuitButton->render();


	SDL_RenderPresent(m_Renderer);
}
// window for Gameover
void Chess::Menu::DisplayGameOver(std::string p_Winner)
{
	// do it later f


}

/*void Chess::Menu::Update()
{
}
*/

const Menu_State Chess::Menu::getMenuState() const
{
	SDL_Event event;
	if (SDL_WaitEvent(&event))
	{
		if (m_PlayButton->IsButtonClick(&event))
		{
			return Menu_State::PLAY;
		}
		else if (m_QuitButton->IsButtonClick(&event))
		{
			return Menu_State::QUIT;
		}
		if (event.type == SDL_QUIT)
			return Menu_State::QUIT;
	}
	return Menu_State::NONE;
}