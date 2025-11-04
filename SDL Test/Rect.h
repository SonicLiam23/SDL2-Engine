#pragma once
#include "Log.h"
struct Rect
{
	int x, y, w, h;
	Rect(int px, int py, int pw, int ph) : x(px), y(py), w(pw), h(ph) {}

	template <typename T>
	const T TryParse()
	{
		T out;
		try
		{
			out.x = x;
			out.y = y;
			out.w = w;
			out.h = h;
		}
		catch (...)
		{
			Log::Get()->LogText("Error converting in Rect.h");
		}
		return out;
	}
};