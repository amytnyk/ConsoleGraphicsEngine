#include "stdafx.h"

#include <iostream>
#include <windows.h>
#include <Windows.h>
#include <vector>
#include <string>

void DrawCircle(HWND hW, int xCenter, int yCenter, int radius, COLORREF borderColor, COLORREF fillColor)
{
	HDC hDC = GetDC(hW);
	HPEN hPen = CreatePen(PS_SOLID, 1, borderColor);
	HPEN hOldPen = (HPEN)SelectObject(hDC, hPen);
	HBRUSH hBrush = CreateSolidBrush(fillColor);
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);

	Ellipse(hDC, xCenter - radius, yCenter - radius, xCenter + radius, yCenter + radius);

	SelectObject(hDC, hOldPen);
	DeleteObject(hPen);
	SelectObject(hDC, hOldBrush);
	DeleteObject(hBrush);
	ReleaseDC(hW, hDC);
}

void DrawLine(HWND hW, int x0, int y0, int x1, int y1, COLORREF color)
{
	HDC hDC = GetDC(hW);
	HPEN hPen = CreatePen(PS_SOLID, 2, color);
	HPEN hOldPen = (HPEN)SelectObject(hDC, hPen);

	POINT p = { 0, 0 };
	GetCurrentPositionEx(hDC, &p);
	MoveToEx(hDC, x0, y0, &p);
	LineTo(hDC, x1, y1);

	SelectObject(hDC, hOldPen);
	DeleteObject(hPen);
	ReleaseDC(hW, hDC);
}

void DrawReactangle(HWND hW, int xCenter, int yCenter, int x2Center, int y2Center, COLORREF borderColor, COLORREF fillColor)
{
	HDC hDC = GetDC(hW);
	HPEN hPen = CreatePen(PS_SOLID, 1, borderColor);
	HPEN hOldPen = (HPEN)SelectObject(hDC, hPen);
	HBRUSH hBrush = CreateSolidBrush(fillColor);
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);

	Reactangle(hW, xCenter, yCenter, x2Center, y2Center, borderColor, fillColor);

	SelectObject(hDC, hOldPen);
	DeleteObject(hPen);
	SelectObject(hDC, hOldBrush);
	DeleteObject(hBrush);
	ReleaseDC(hW, hDC);
}

void DrawOval(HWND hW, int xCenter, int yCenter, int x2Center, int y2Center, COLORREF borderColor, COLORREF fillColor)
{
    HDC hDC = GetDC(hW);
    HPEN hPen = CreatePen(PS_SOLID, 1, borderColor);
    HPEN hOldPen = (HPEN)SelectObject(hDC, hPen);
    HBRUSH hBrush = CreateSolidBrush(fillColor);
    HBRUSH hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);
 
    Ellipse(hDC, xCenter, yCenter, x2Center, y2Center);
 
    SelectObject(hDC, hOldPen);
    DeleteObject(hPen);
    SelectObject(hDC, hOldBrush);
    DeleteObject(hBrush);
    ReleaseDC(hW, hDC);
}

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
	for (int i = 0; i < s.texture.size();)
	{
		auto current = s.texture[i];
		if (current == "DrawLine")
		{
			COLORREF color;
			if (s.texture[i + 5] == "red")
				color = RGB(201, 18, 21);
			if (s.texture[i + 5] == "green")
				color = RGB(30, 204, 14);
			if (s.texture[i + 5] == "blue")
				color = RGB(26, 29, 186);
			DrawLine(hW,
				std::stoi(s.texture[i + 1]),
				std::stoi(s.texture[i + 2]),
				std::stoi(s.texture[i + 3]),
				std::stoi(s.texture[i + 4]),

				color
				);
			i += 6;
		}
		if (current == "DrawEllipse")
		{
			COLORREF border_color;
			COLORREF fill_color;
			if (s.texture[i + 5] == "red")
				border_color = RGB(201, 18, 21);
			if (s.texture[i + 5] == "green")
				border_color = RGB(30, 204, 14);
			if (s.texture[i + 5] == "blue")
				border_color = RGB(26, 29, 186);
			if (s.texture[i + 6] == "red")
				fill_color = RGB(201, 18, 21);
			if (s.texture[i + 6] == "green")
				fill_color = RGB(30, 204, 14);
			if (s.texture[i + 6] == "blue")
				fill_color = RGB(26, 29, 186);
			DrawOval(hW,
				std::stoi(s.texture[i + 1]),
				std::stoi(s.texture[i + 2]),
				std::stoi(s.texture[i + 3]),
				std::stoi(s.texture[i + 4]),
				border_color,
				fill_color
				);
			i += 7;
		}
		if (current == "DrawRectangle")
		{
			COLORREF border_color;
			COLORREF fill_color;
			if (s.texture[i + 5] == "red")
				border_color = RGB(201, 18, 21);
			if (s.texture[i + 5] == "green")
				border_color = RGB(30, 204, 14);
			if (s.texture[i + 5] == "blue")
				border_color = RGB(26, 29, 186);
			if (s.texture[i + 6] == "red")
				fill_color = RGB(201, 18, 21);
			if (s.texture[i + 6] == "green")
				fill_color = RGB(30, 204, 14);
			if (s.texture[i + 6] == "blue")
				fill_color = RGB(26, 29, 186);
			DrawReactangle(hW,
				std::stoi(s.texture[i + 1]),
				std::stoi(s.texture[i + 2]),
				std::stoi(s.texture[i + 3]),
				std::stoi(s.texture[i + 4]),
				border_color,
				fill_color
				);
			i += 7;
		}
	}
}