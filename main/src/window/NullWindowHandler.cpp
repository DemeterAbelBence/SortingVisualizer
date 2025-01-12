#include "NullWindowHandler.hpp"

void NullWindowHandler::Initialize() {}

void NullWindowHandler::Destroy() {}

NullWindowHandler::NullWindowHandler() {
	IsActive = true;
}

NullWindowHandler::~NullWindowHandler() {}
