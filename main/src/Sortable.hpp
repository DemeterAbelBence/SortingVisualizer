#pragma once

#include <memory>

class ArrayDrawer;

class Sortable {
public:
	struct Vector2 {
		int x;
		int y;
	};
	Vector2 Position;

	int Value;

private:
	static std::shared_ptr<ArrayDrawer> arrayDrawer;

public:
	Sortable(int _Value);
	static void SetArrayDrawer(std::shared_ptr<ArrayDrawer> _arrayDrawer);

	void operator=(const Sortable& other);
	bool operator<(const Sortable& other);
	bool operator>(const Sortable& other);
	bool operator<=(const Sortable& other);
	bool operator>=(const Sortable& other);
};