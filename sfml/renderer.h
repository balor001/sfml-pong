#pragma once
#include "game.h"
#include <SFML/Graphics.hpp>

class Renderer {
public:

	void render(sf::RenderWindow* rw, Game* pGame);

private:

	// Update shapes
	void updateShapes(Game* pGame);

	// Shapes
	sf::RectangleShape bgshape;
	sf::RectangleShape grass;

	sf::RectangleShape box;
	sf::RectangleShape box2;
	sf::RectangleShape box3;

	sf::CircleShape moving_circle;
	sf::CircleShape myCircle;

	//sf::RectangleShape airblower;
	//sf::RectangleShape airblower_air;
	//sf::RectangleShape airblower_other;
	//sf::RectangleShape airblower_air_other;

	//sf::CircleShape black_hole;

	sf::Texture ball_texture;
	sf::Sprite ball_sprite;
};
