#pragma once
#include <SFML/Graphics.hpp>

class DrivableCell;
class NonDrivableCell;
class StructureCell;
class Button;
class Car;

////////////////////////////////////////////////////////////
   /// \brief Reads level sizes of all cells types
   ///
   /// \param lvlpath - path to level file
////////////////////////////////////////////////////////////
void ReadLevelFile(const char lvlpath[], int& roadSize, int& decorSize, int& structSize);

////////////////////////////////////////////////////////////
   /// \brief Checks is point belong to given cell
   ///
   /// \param a - point that needs to be checked
////////////////////////////////////////////////////////////
bool isBelong(sf::Vector2i a, DrivableCell cell);

////////////////////////////////////////////////////////////
   /// \brief Checks is point belong to given button
   ///
   /// \param a - point that needs to be checked
////////////////////////////////////////////////////////////
bool isBelong(sf::Vector2i a, Button bt);

////////////////////////////////////////////////////////////
   /// \brief Sets textures to cells
////////////////////////////////////////////////////////////
void SetDrivablePath(DrivableCell road[], const int roadSize,
	int straight, int turned, int threeway, int fourway);

////////////////////////////////////////////////////////////
   /// \brief Set textures to cells
////////////////////////////////////////////////////////////
void SetNonDrivablePath(NonDrivableCell decor[], const int decorSize,
	int forest, int private_residence, int apartment);

////////////////////////////////////////////////////////////
   /// \brief Checks if cells need to swaped and swap them
////////////////////////////////////////////////////////////
void CheckSwap(sf::RenderWindow& window, DrivableCell road[], const int roadSize);

////////////////////////////////////////////////////////////
   /// \brief Set all cells main positions 
////////////////////////////////////////////////////////////
void ReadMainPositions(const char lvlpath[], DrivableCell road[], const int roadSize,
	NonDrivableCell decor[], const int decorSize,
	StructureCell structs[], const int structSize);

////////////////////////////////////////////////////////////
   /// \brief Set all cells positions 
////////////////////////////////////////////////////////////
void SetPositions(const int roadSize, DrivableCell cell[],
	const int decorSize, NonDrivableCell decor[],
	const int structSize, StructureCell structs[], sf::RenderWindow& window);

////////////////////////////////////////////////////////////
   /// \brief Set all cells chosen status to given
   ///
   /// \param var - status that will be set
////////////////////////////////////////////////////////////
void SetIsChosen(bool var, DrivableCell road[], const int roadSize);

////////////////////////////////////////////////////////////
   /// \brief Read car position from file
   ///
   /// \param lvlpath - path to level file
////////////////////////////////////////////////////////////
void ReadCarPosition(Car& car, const char lvlpath[]);

////////////////////////////////////////////////////////////
   /// \brief Read cells types from file
   ///
   /// \param lvlpath - path to level file
////////////////////////////////////////////////////////////
void ReadCellsTypes(const char lvlpath[], int& straight, int& turned, int& threeway, int& fourway, int& finish, int& flowers, int& private_residence, int& apartments);

///////////////////////////////////////////////////////////
   /// \brief Draw all cells in the given window
////////////////////////////////////////////////////////////
void DrawCells(sf::RenderWindow& win, DrivableCell roads[], NonDrivableCell chosen,
	const int roadSize, NonDrivableCell decor[], const int decorSize, 
	StructureCell structs[], const int structSize);