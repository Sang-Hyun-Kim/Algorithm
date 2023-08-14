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

	// ���Ⱚ: �ʱ� ������
	int32 _dir = DIR_UP;
	// ���� ��ġ
	Board* _board = nullptr;

};

