#include "CreditsMenu.h"

CreditsMenu::CreditsMenu()
{

}

CreditsMenu::~CreditsMenu()
{

}

void CreditsMenu::initMap(sf::RenderWindow &window, TextureManager &textureManager)
{
	//hardcoded positions

	backgroundSprite.setTexture(*textureManager.getResource("Config/Content/Images/Menus/Backgrounds/creditsBackground.png"));
	backgroundSprite.setScale((float)window.getSize().x / backgroundSprite.getTexture()->getSize().x, (float)window.getSize().y / backgroundSprite.getTexture()->getSize().y);

	sf::RectangleShape backButton;
	backButton.setSize(sf::Vector2f(140.0f, 72.0f));
	backButton.setTexture(textureManager.getResource("Config/Content/Images/Menus/Buttons/backButton.png"));
	backButton.setPosition(window.getSize().x / 2 - backButton.getSize().x / 2, 525);

	menuItems[BACK] = backButton;
}

void CreditsMenu::Load()
{
	
}

void CreditsMenu::Update(sf::RenderWindow& window, InputHandler &input)
{
	for(it = menuItems.begin(); it != menuItems.end(); it++)
	{
		if(isInRect(input.getMousePos(window),it->second) &&  input.clicked(window))
		{
			menuValue = it->first;
			break;
		}
	}
}

void CreditsMenu::Draw(sf::RenderWindow& window)
{
	window.draw(backgroundSprite);
	for(it = menuItems.begin(); it != menuItems.end(); it++)
	{
		window.draw(it->second);
	}
}

bool CreditsMenu::isInRect(sf::Vector2i position, sf::RectangleShape menuItemRect)
{
	return(menuItemRect.getPosition().y < position.y && 
			menuItemRect.getPosition().y + menuItemRect.getSize().y > position.y &&
			menuItemRect.getPosition().x < position.x &&
			menuItemRect.getPosition().x + menuItemRect.getSize().x > position.x);
}

Menu::MenuResult CreditsMenu::changeScreen(sf::RenderWindow& window, InputHandler &input)
{
	menuValue = NOTHING;
	Update(window, input);
	return menuValue;
}