#pragma once

#include <string>
#include <iostream>
#include <rapidxml-1.13\rapidxml.hpp>
#include <rapidxml-1.13\rapidxml_utils.hpp>
#include <SFML\Graphics.hpp>
#include "Assets.h"

class Level
{
public:
	Level();

	~Level();

	/** Parses the xml file. */
	bool Load(std::string levelFilepath);

	/** Parses through the foreground layer for interactive objects. */
	bool ParseEntities(rapidxml::xml_node<> *node);

	/** Parses through the bounds layer to fill the collisionBounds vector. */
	bool ParseBounds(rapidxml::xml_node<> *node);

	/** Returns the bounds variable. */
	sf::Rect<float> GetBounds();

	/** Returns the collisionBounds variable. */
	std::vector<sf::Rect<float>> GetCollisionBounds();

	std::vector<bool> GetCollisionBoundsLethality();

	/** Returns the spawnPoints variable. */
	std::vector<sf::Vector2f> GetSpawnPoints();

private:
	/** Stores the level which the server is hosting. */
	std::string levelFilepath;

	/** Stores the collision bound data for collision detection. */
	std::vector<sf::Rect<float>> collisionBounds;

	/** Stores the lethal data of the collision bounds. */
	std::vector<bool> collisionBoundsLethality;

	/** Stores the level bounds - the area in which players can move. */
	sf::Rect<float> bounds;

	/** Stores the level spawn points. */
	std::vector<sf::Vector2f> spawnPoints;
};