#pragma once

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL2_gfxPrimitives.h>

#include "WindowHandler.hpp"

class SDLWindowHandler : public WindowHandler {

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

protected:
	void Initialize() override;
	void Destroy() override;

public:
	SDLWindowHandler();
	~SDLWindowHandler();

	void DrawRect(const RectData&, const Color&) const override;
	void RenderFrame() const override;
	void ClearFrame() const override;
	void DelayFrame(unsigned int milliseconds) const override;
	void HandleEvents() override;
};