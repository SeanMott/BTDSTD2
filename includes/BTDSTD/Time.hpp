#pragma once

//handles time and delta time

#include <SDL_timer.h>

namespace BTD::Time
{
	//defines a Time
	struct Time
	{
		static double deltaTime;
		static double fixedDeltaTime;

		static Uint64 lastFrame;
		static Uint64 currentFrame;

		//calculates the delta time
		inline static double CalDeltaTime()
		{
			lastFrame = currentFrame;
			currentFrame = SDL_GetPerformanceCounter();
			Uint64 elapsedTicks = currentFrame - lastFrame;

			Uint64 frequency = SDL_GetPerformanceFrequency();
			deltaTime = static_cast<double>(elapsedTicks) / static_cast<double>(frequency);

			//lastFrame = currentFrame;
			//currentFrame = SDL_GetPerformanceCounter();
			//
			//deltaTime = (double)((currentFrame - lastFrame) * 1000 / (double)SDL_GetPerformanceFrequency());
			return deltaTime;
		}

		//calculates the fixed delta time
	};
}