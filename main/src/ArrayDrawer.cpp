#include "ArrayDrawer.hpp"

std::shared_ptr<WindowHandler> ArrayDrawer::windowHandler = nullptr;

WindowHandler::Color ArrayDrawer::colorMask = { 1, 1, 1, 1 };

ArrayDrawer::ArrayDrawer() {}

void ArrayDrawer::SetWindowHander(std::shared_ptr<WindowHandler> _windowHandler) {
	windowHandler = _windowHandler;
}

void ArrayDrawer::SetColorMask(WindowHandler::Color _colorMask) {
	colorMask = _colorMask;
}

void ArrayDrawer::SetData(std::vector<Sortable> _data) {
	data = _data;
	for (int i = 0; i < data.size(); ++i) {
		data[i].Position.x = i * (windowHandler->Width / data.size());
		data[i].Position.y = windowHandler->Height;
	}
}

std::vector<Sortable>& ArrayDrawer::GetData() {
	return data;
}

void ArrayDrawer::Draw(bool hasDelay) const {
	windowHandler->HandleEvents();
	windowHandler->ClearFrame();

	for (int i = 0; i < data.size(); ++i) {
		int columnWidth = windowHandler->Width / data.size();
		int columnHeight = data[i].Value * 20;

		WindowHandler::RectData rectData = { 
			data[i].Position.x, 
			data[i].Position.y, 
			columnWidth, 
			-columnHeight
		};

		int intensity = 50 + 0.4f * columnHeight;
		WindowHandler::Color color = {
			intensity * colorMask.red,
			intensity * colorMask.green,
			intensity * colorMask.blue,
			255 * colorMask.alpha
		};

		windowHandler->DrawRect(rectData, color);
	}

	windowHandler->RenderFrame();

	if (hasDelay) {
		windowHandler->DelayFrame(1);
	}
}
