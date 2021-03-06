#pragma once

namespace GameOfLifeCLR {

public ref class Config
{
public:
	Config(int wnd_width, int wnd_height);

	static int getWidth(){return mWorldWidth;};
	static int getHeight(){return mWorldHeight;};
	static int getSeed(){return mSeed;};


	static void setWidth(int w){mWorldWidth = w;};
	static void setHeight(int h){mWorldHeight = h;};
	static void setSeed(int s){mSeed = s;};

private:
	static int mWorldWidth = 10;
	static int mWorldHeight = 10;
	static int mSeed = 5;

};
}
