#pragma once

#include <memory>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

#include "src/window/WindowHandler.hpp"
#include "src/window/SDLWindowHandler.hpp"
#include "src/window/NullWindowHandler.hpp"
#include "src/Sortable.hpp"
#include "src/ArrayDrawer.hpp"
#include "src/srt.hpp"

int main(void) {
	//std::shared_ptr<WindowHandler> windowHandler(new NullWindowHandler());
	std::shared_ptr<WindowHandler> windowHandler(new SDLWindowHandler());
	ArrayDrawer::SetWindowHander(windowHandler);

	std::shared_ptr<ArrayDrawer> arrayDrawer(new ArrayDrawer());
	Sortable::SetArrayDrawer(arrayDrawer);

	std::vector<Sortable> data;
	for (int i = 1; i <= 100; ++i) {
		int number = std::rand() % 20;
		data.push_back(Sortable(number));
	}

	arrayDrawer->SetData(data);
	arrayDrawer->SetColorMask({ 0, 1, 1, 1 });
	std::sort(arrayDrawer->GetData().begin(), arrayDrawer->GetData().end());

	windowHandler->DelayFrame(1000);

	arrayDrawer->SetData(data);
	arrayDrawer->SetColorMask({ 1, 0, 1, 1 });
	srt::quickSortVector<Sortable>(arrayDrawer->GetData());

	while (windowHandler->IsActive) {
		windowHandler->HandleEvents();
	}

	return 0;
}
