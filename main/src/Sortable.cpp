#include "Sortable.hpp"
#include "ArrayDrawer.hpp"

std::shared_ptr<ArrayDrawer> Sortable::arrayDrawer = nullptr;

Sortable::Sortable(int _Value) {
	Value = _Value;
	Position = { 0, 0 };
}

void Sortable::SetArrayDrawer(std::shared_ptr<ArrayDrawer> _arrayDrawer) {
	arrayDrawer = _arrayDrawer;
}

void Sortable::operator=(const Sortable& other) {
	Value = other.Value;
	arrayDrawer->Draw(false);
}

bool Sortable::operator<(const Sortable& other) {
	arrayDrawer->Draw(true);
	return Value < other.Value;
}

bool Sortable::operator>(const Sortable& other) {
	arrayDrawer->Draw(true);
	return Value > other.Value;
}

bool Sortable::operator<=(const Sortable& other) {
	arrayDrawer->Draw(true);
	return Value <= other.Value;
}

bool Sortable::operator>=(const Sortable& other) {
	arrayDrawer->Draw(true);
	return Value >= other.Value;
}
