#ifndef COLOR_H
#define COLOR_H

class Color{
	public:
		Color();
		Color(float red, float green, float blue);
		Color(float red, float green, float blue, float alpha);
		Color(int red, int green, int blue);
		Color(int red, int green, int blue, int alpha);
		float getRed();
		float getGreen();
		float getBlue();
		float getAlpha();
	protected:
		float red;
		float green;
		float blue;
		float alpha;
};

#endif