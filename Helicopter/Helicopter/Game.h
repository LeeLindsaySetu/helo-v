/// <summary>
/// author Lee Lindsay
/// you need to change the above line or lose marks
/// </summary>
#ifndef GAME_HPP
#define GAME_HPP
/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the endif at the bottom
/// </summary>
#include <SFML/Graphics.hpp>

enum class Direction
{
	None,
	Up,
	Down,
	Left,
	Right
};


class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void processMouseBUttonUp(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	
	void setupFontAndText();
	void setupSprite();
	void animateHelicopter();
	void move();

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen
	sf::Texture m_helicopterTexture; // texture used for sfml logo
	sf::Sprite m_helicopterSprite; // sprite used for sfml logo
	bool m_exitGame; // control exiting game

	int m_frameNo{ 0 }; // frame setup of the 0-3 helo images
	float m_frameValue{ 0.0f }; // current frame number
	float m_frameIncrement{ 0.50f }; // the increase of each frame
	sf::Vector2f m_position{ 200.0f,200.0f }; // current helo position
	sf::Vector2f m_desiredPosition{ 0.0f,0.0f }; // position user chooses "direction"
	sf::Vector2f m_velocity{ 0.0f, 0.0f };
	Direction m_direction{ Direction::None };
};

#endif // !GAME_HPP

