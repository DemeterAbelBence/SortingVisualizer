#pragma once

class WindowHandler {

public:
	struct RectData {
		int posx;
		int posy;
		int width;
		int height;
	};

	struct Color {
		int red;
		int green;
		int blue;
		int alpha;
	};

public:
	unsigned int Width = 1200;
	unsigned int Height = 700;
	bool IsActive = false;

protected:
	virtual void Initialize() = 0;
	virtual void Destroy() = 0;

public:
	virtual void DrawRect(const RectData&, const Color&) const;
	virtual void RenderFrame() const;
	virtual void ClearFrame() const;
	virtual void DelayFrame(unsigned int milliseconds) const;
	virtual void HandleEvents();
};