#pragma once

#include "WindowHandler.hpp"

class NullWindowHandler : public WindowHandler {
private:

protected:
	void Initialize() override;
	void Destroy() override;

public:
	NullWindowHandler();
	~NullWindowHandler();
};