#pragma once

#include <vector>
#include <memory>

#include "Sortable.hpp"
#include "window/WindowHandler.hpp"

class ArrayDrawer {

private:
	std::vector<Sortable> data;

private:
	static std::shared_ptr<WindowHandler> windowHandler;
	static WindowHandler::Color colorMask;

public:
	ArrayDrawer();

	void SetData(std::vector<Sortable> _data);
	std::vector<Sortable>& GetData();

	void Draw(bool hasDelay) const;

	static void SetWindowHander(std::shared_ptr<WindowHandler> _windowHandler);
	static void SetColorMask(WindowHandler::Color _colorMask);
};