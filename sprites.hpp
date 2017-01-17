#include "stdafx.h"

#include <iostream>
#include <vector>
#include <cstring>
#include <st.hpp>
#include <windows.h>
#include <Windows.h>
#include <cmath>

class Sprite
{
public:
	int X;
	int Y;
	std::vector<std::string> texture;
};

void Draw(Sprite s)
{
	HWND hW = GetConsoleWindow();
	for(int i = 0;i < s.texture.size();)
	{
		auto current = s.texture[i];
		if(current == "DrawLine")
		{
			COLORREF color;
			if(s.texture[i + 5] == "red")
				color = RGB(201, 18, 21); 
			if(s.texture[i + 5] == "green")
				color = RGB(30, 204, 14); 
			if(s.texture[i + 5] == "blue")
				color = RGB(26, 29, 186); 
			DrawLine(hW, 
				std::stoi( s.texture[i + 1] ),
				std::stoi( s.texture[i + 2] ),
				std::stoi( s.texture[i + 3] ),
				std::stoi( s.texture[i + 4] ),
			
				color
				);
			i += 6;
		}
	}
}
