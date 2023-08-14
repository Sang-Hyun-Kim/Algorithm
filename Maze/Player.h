#pragma once

class Board;

class Player
{
public:

	void Init(Board* board);
	void Update(uint64 deltaTick);


	void SetPos(Pos pos) { _pos = pos; }
	Pos GetPos() { return _pos; }
private:
	Pos _pos = {};

	// 방향값: 초기 윗방향
	int32 _dir = DIR_UP;
	// 현재 위치
	Board* _board = nullptr;

};

