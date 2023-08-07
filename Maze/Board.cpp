#include "pch.h"
#include "Board.h"
#include "ConsoleHelper.h"


const char* TILE = "■";

Board::Board()
{

}

Board::~Board()
{
}



// 미로 생성
void Board::GenerateMap()
{
	for (int32 y = 0; y < _size; y++)
	{
		for (int32 x = 0; x < _size; x++)
		{
			if (x % 2 ==0 || y%2 == 0)
			{
				_tile[y][x] = TileType::WALL;

			}
			else
			{
				_tile[y][x] = TileType::EMPTY;
			}
		}
	}

	// 랜덤으로 우측 혹은 아래로 길을 뚫는 작업
	for (int32 y = 0; y < _size; y++)
	{
		for (int32 x = 0; x < _size; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
				continue;

			const int32 randValue = ::rand() % 2;
			if (randValue == 0)
			{
				_tile[y][x + 1] = TileType::EMPTY;
			}
			else
			{
				_tile[y + 1][x] = TileType::EMPTY;
			}
		}
	}

}

void Board::Init(int32 size)
{
	_size = size;
	GenerateMap();
}

void Board::Render()
{

		ConsoleHelper::SetCursorPosition(0, 0);
		ConsoleHelper::ShowConsoleCursor(false);
		

		for (int32 y = 0; y < 25; y++)
		{
			for (int32 x = 0; x < 25; x++)
			{
				ConsoleColor color = GetTileColor(Pos{x,y});
				ConsoleHelper::SetCursorColor(color);

				cout << TILE;
			}
			cout << endl;
		}
}

TileType Board::GetTileType(Pos pos)
{
	if (pos.x < 0 || pos.x >= _size)
		return TileType::NONE;

	if (pos.y < 0 || pos.y >= _size)
		return TileType::NONE;

	return _tile[pos.y][pos.x];
}

ConsoleColor Board::GetTileColor(Pos pos)
{
	TileType tileType = GetTileType(pos);

	switch (tileType)
	{
	case::TileType::EMPTY:
		return ConsoleColor::GREEN;
	case::TileType::WALL:
		return ConsoleColor::RED;

	}
	return ConsoleColor::WHITE;
}
