#pragma once

#include "../Game.h"
#include "../Entity.h"

#include <string>
#include <vector>
#include <map>

namespace levels
{
	class Other
	{
		public:
            Other();
			std::vector<std::string> loadLevel0(int rX, int rY , Game& game, EntityClass& obj);
			std::vector<std::string> loadLevel1(int rX, int rY , Game& game, EntityClass& obj);
			std::vector<std::string> loadLevel2(int rX, int rY , Game& game, EntityClass& obj);
			std::vector<std::string> loadLevel3(int rX, int rY , Game& game, EntityClass& obj);
			std::vector<std::string> loadLevel4(int rX, int rY , Game& game, EntityClass& obj);
			
			std::multimap<int, std::vector<std::string> > othermaps;
			std::string roomName;
            int roomTileSet;
            bool roomTextOn;
            int roomTextX;
            int roomTextY;
            int roomTextNumberLines;
            std::vector<std::string> roomText;
	};
}
