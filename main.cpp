#include "stdafx.h"
#include "GameDirector.h"

int APIENTRY _tWinMain(HINSTANCE hIn, HINSTANCE prev, PTSTR cmd, int cShow) {
	return const_cast<GameDirector&>(GameDirector::GetGameDirector()).Run(hIn);
}