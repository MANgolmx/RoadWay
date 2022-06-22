#include "TextureManager.h"
#include <iostream>

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
}

void TextureManager::IncludeCellTextures()
{
	/*
	sf::Texture tmp;
	if (!tmp.loadFromFile("resources\\cells\\straight\\straight_flowers_1.png"))
	{ std::cout << "[ERROR OCURRED] Can not open texture from key" << std::endl; exit(1); }
	Textures["resources\\cells\\straight\\straight_flowers_1.png"] = tmp;
	TexturePointers["resources\\cells\\straight\\straight_flowers_1.png"] = Textures["resources\\cells\\straight\\straight_flowers_1.png"];

	if (!tmp.loadFromFile("resources\\cells\\straight\\straight_flowers_2.png"))
	{ std::cout << "[ERROR OCURRED] Can not open texture from key" << std::endl; exit(1); }
	Textures["resources\\cells\\straight\\straight_flowers_2.png"] = tmp;
	TexturePointers["resources\\cells\\straight\\straight_flowers_2.png"] = Textures["resources\\cells\\straight\\straight_flowers_2.png"];

	if (!tmp.loadFromFile("resources\\cells\\straight\\straight_flowers_3.png"))
	{ std::cout << "[ERROR OCURRED] Can not open texture from key" << std::endl; exit(1); }
	Textures["resources\\cells\\straight\\straight_flowers_3.png"] = tmp;
	TexturePointers["resources\\cells\\straight\\straight_flowers_3.png"] = Textures["resources\\cells\\straight\\straight_flowers_3.png"];

	if (!tmp.loadFromFile("resources\\cells\\straight\\straight_flowers_4.png"))
	{ std::cout << "[ERROR OCURRED] Can not open texture from key" << std::endl; exit(1); }
	Textures["resources\\cells\\straight\\straight_flowers_4.png"] = tmp;
	TexturePointers["resources\\cells\\straight\\straight_flowers_4.png"] = Textures["resources\\cells\\straight\\straight_flowers_4.png"];

	if (!tmp.loadFromFile("resources\\cells\\straight\\straight_trashbin_1.png"))
	{ std::cout << "[ERROR OCURRED] Can not open texture from key" << std::endl; exit(1); }
	Textures["resources\\cells\\straight\\straight_trashbin_1.png"] = tmp;
	TexturePointers["resources\\cells\\straight\\straight_trashbin_1.png"] = Textures["resources\\cells\\straight\\straight_trashbin_1.png"];

	if (!tmp.loadFromFile("resources\\cells\\straight\\straight_trashbin_2.png"))
	{ std::cout << "[ERROR OCURRED] Can not open texture from key" << std::endl; exit(1); }
	Textures["resources\\cells\\straight\\straight_trashbin_2.png"] = tmp;
	TexturePointers["resources\\cells\\straight\\straight_trashbin_2.png"] = Textures["resources\\cells\\straight\\straight_trashbin_2.png"];

	if (!tmp.loadFromFile("resources\\cells\\straight\\straight_trashbin_3.png"))
	{ std::cout << "[ERROR OCURRED] Can not open texture from key" << std::endl; exit(1); }
	Textures["resources\\cells\\straight\\straight_trashbin_3.png"] = tmp;
	TexturePointers["resources\\cells\\straight\\straight_trashbin_3.png"] = Textures["resources\\cells\\straight\\straight_trashbin_3.png"];

	if (!tmp.loadFromFile("resources\\cells\\straight\\straight_trashbin_4.png"))
	{ std::cout << "[ERROR OCURRED] Can not open texture from key" << std::endl; exit(1); }
	Textures["resources\\cells\\straight\\straight_trashbin_4.png"] = tmp;
	TexturePointers["resources\\cells\\straight\\straight_trashbin_4.png"] = Textures["resources\\cells\\straight\\straight_trashbin_4.png"];

	if (!tmp.loadFromFile("resources\\cells\\straight\\straight_trashbin_5.png"))
	{ std::cout << "[ERROR OCURRED] Can not open texture from key" << std::endl; exit(1); }
	Textures["resources\\cells\\straight\\straight_trashbin_5.png"] = tmp;
	TexturePointers["resources\\cells\\straight\\straight_trashbin_5.png"] = Textures["resources\\cells\\straight\\straight_trashbin_5.png"];

	if (!tmp.loadFromFile("resources\\cells\\straight\\straight_trashbin_6.png"))
	{ std::cout << "[ERROR OCURRED] Can not open texture from key" << std::endl; exit(1); }
	Textures["resources\\cells\\straight\\straight_trashbin_6.png"] = tmp;
	TexturePointers["resources\\cells\\straight\\straight_trashbin_6.png"] = Textures["resources\\cells\\straight\\straight_trashbin_6.png"];

	if (!tmp.loadFromFile("resources\\cells\\straight\\straight_busstop_1.png"))
	{ std::cout << "[ERROR OCURRED] Can not open texture from key" << std::endl; exit(1);  }
	Textures["resources\\cells\\straight\\straight_busstop_1.png"] = tmp;
	TexturePointers["resources\\cells\\straight\\straight_busstop_1.png"] = Textures["resources\\cells\\straight\\straight_busstop_1.png"];

	if (!tmp.loadFromFile("resources\\cells\\turned\\turned_flowers_1.png"))
	{ std::cout << "[ERROR OCURRED] Can not open texture from key" << std::endl; exit(1); }
	Textures["resources\\cells\\turned\\turned_flowers_1.png"] = tmp;
	TexturePointers["resources\\cells\\turned\\turned_flowers_1.png"] = Textures["resources\\cells\\straight\\straight_busstop_1.png"];

	if (!tmp.loadFromFile("resources\\cells\\turned\\turned_flowers_2.png"))
	{ std::cout << "[ERROR OCURRED] Can not open texture from key" << std::endl; exit(1); }
	Textures["resources\\cells\\turned\\turned_flowers_2.png"] = tmp;

	if (!tmp.loadFromFile("resources\\cells\\turned\\turned_flowers_3.png"))
	{ std::cout << "[ERROR OCURRED] Can not open texture from key" << std::endl; exit(1); }
	Textures["resources\\cells\\turned\\turned_flowers_3.png"] = tmp;

	if (!tmp.loadFromFile("resources\\cells\\turned\\turned_flowers_4.png"))
	{ std::cout << "[ERROR OCURRED] Can not open texture from key" << std::endl; exit(1); }
	Textures["resources\\cells\\turned\\turned_flowers_4.png"] = tmp;

	if (!tmp.loadFromFile("resources\\cells\\turned\\turned_busstop_1.png"))
	{ std::cout << "[ERROR OCURRED] Can not open texture from key" << std::endl; exit(1); }
	Textures["resources\\cells\\turned\\turned_busstop_1.png"] = tmp;

	if (!tmp.loadFromFile("resources\\cells\\turned\\turned_busstop_2.png"))
	{ std::cout << "[ERROR OCURRED] Can not open texture from key" << std::endl; exit(1); }
	Textures["resources\\cells\\turned\\turned_busstop_2.png"] = tmp;

	if (!tmp.loadFromFile("resources\\cells\\threeway\\threeway_flowers_1.png"))
	{ std::cout << "[ERROR OCURRED] Can not open texture from key" << std::endl; exit(1); }
	Textures["resources\\cells\\threeway\\threeway_flowers_1.png"] = tmp;

	if (!tmp.loadFromFile("resources\\cells\\threeway\\threeway_flowers_2.png"))
	{ std::cout << "[ERROR OCURRED] Can not open texture from key" << std::endl; exit(1); }
	Textures["resources\\cells\\threeway\\threeway_flowers_2.png"] = tmp;

	if (!tmp.loadFromFile("resources\\cells\\threeway\\threeway_flowers_3.png"))
	{ std::cout << "[ERROR OCURRED] Can not open texture from key" << std::endl; exit(1); }
	Textures["resources\\cells\\threeway\\threeway_flowers_3.png"] = tmp;

	if (!tmp.loadFromFile("resources\\cells\\threeway\\threeway_flowers_4.png"))
	{ std::cout << "[ERROR OCURRED] Can not open texture from key" << std::endl; exit(1); }
	Textures["resources\\cells\\threeway\\threeway_flowers_4.png"] = tmp;
	
	if (!tmp.loadFromFile("resources\\cells\\threeway\\threeway_flowers_5.png"))
	{ std::cout << "[ERROR OCURRED] Can not open texture from key" << std::endl; exit(1); }
	Textures["resources\\cells\\threeway\\threeway_flowers_5.png"] = tmp;

	if (!tmp.loadFromFile("resources\\cells\\threeway\\threeway_busstop_1.png"))
	{ std::cout << "[ERROR OCURRED] Can not open texture from key" << std::endl; exit(1); }
	Textures["resources\\cells\\threeway\\threeway_busstop_1.png"] = tmp;
	
	if (!tmp.loadFromFile("resources\\cells\\threeway\\threeway_busstop_2.png"))
	{ std::cout << "[ERROR OCURRED] Can not open texture from key" << std::endl; exit(1); }
	Textures["resources\\cells\\threeway\\threeway_busstop_2.png"] = tmp;

	if (!tmp.loadFromFile("resources\\cells\\flowers\\flowers_1.png"))
	{ std::cout << "[ERROR OCURRED] Can not open texture from key" << std::endl; exit(1); }
	Textures["resources\\cells\\flowers\\flowers_1.png"] = tmp;

	if (!tmp.loadFromFile("resources\\cells\\flowers\\flowers_2.png"))
	{ std::cout << "[ERROR OCURRED] Can not open texture from key" << std::endl; exit(1); }
	Textures["resources\\cells\\flowers\\flowers_2.png"] = tmp;

	if (!tmp.loadFromFile("resources\\cells\\flowers\\flowers_3.png"))
	{ std::cout << "[ERROR OCURRED] Can not open texture from key" << std::endl; exit(1); }
	Textures["resources\\cells\\flowers\\flowers_3.png"] = tmp;

	if (!tmp.loadFromFile("resources\\cells\\flowers\\flowers_4.png"))
	{ std::cout << "[ERROR OCURRED] Can not open texture from key" << std::endl; exit(1); }
	Textures["resources\\cells\\flowers\\flowers_4.png"] = tmp;

	if (!tmp.loadFromFile("resources\\cells\\flowers\\flowers_5.png"))
	{ std::cout << "[ERROR OCURRED] Can not open texture from key" << std::endl; exit(1); }
	Textures["resources\\cells\\flowers\\flowers_5.png"] = tmp;

	if (!tmp.loadFromFile("resources\\cells\\flowers\\flowers_6.png"))
	{ std::cout << "[ERROR OCURRED] Can not open texture from key" << std::endl; exit(1); }
	Textures["resources\\cells\\flowers\\flowers_6.png"] = tmp;

	if (!tmp.loadFromFile("resources\\cells\\privateResidence\\private_residence_1.png"))
	{ std::cout << "[ERROR OCURRED] Can not open texture from key" << std::endl; exit(1); }
	Textures["resources\\cells\\privateResidence\\private_residence_1.png"] = tmp;

	if (!tmp.loadFromFile("resources\\cells\\privateResidence\\private_residence_2.png"))
	{ std::cout << "[ERROR OCURRED] Can not open texture from key" << std::endl; exit(1); }
	Textures["resources\\cells\\privateResidence\\private_residence_2.png"] = tmp;

	if (!tmp.loadFromFile("resources\\cells\\privateResidence\\private_residence_3.png"))
	{ std::cout << "[ERROR OCURRED] Can not open texture from key" << std::endl; exit(1); }
	Textures["resources\\cells\\privateResidence\\private_residence_3.png"] = tmp;

	if (!tmp.loadFromFile("resources\\cells\\privateResidence\\private_residence_4.png"))
	{ std::cout << "[ERROR OCURRED] Can not open texture from key" << std::endl; exit(1); }
	Textures["resources\\cells\\privateResidence\\private_residence_4.png"] = tmp; */
}

sf::Texture& TextureManager::PullTexture(std::string key)
{
	if (Textures.find(key) != Textures.end()) return Textures[key];

	sf::Texture tmp;
	if (!tmp.loadFromFile(key))
	{
		std::cout << "[ERROR OCURRED] Can not open texture from key" << std::endl;
		exit(1);
	}
	
	Textures[key] = tmp;
	return Textures[key];
}
