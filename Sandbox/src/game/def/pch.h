#pragma once
/*	 --- General ---	*/
#include <iostream>
#include <algorithm>
#include <functional>
#include <memory>
#include <thread>
#include <utility>

#include "../hdr/Logger.h"

/*	 --- Data Structures ---   */
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <array>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

/*    --- SDL2 ----		*/
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#ifdef GAME_PLAT_WINDOWS
	#include <Windows.h>
#endif