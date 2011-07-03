#pragma once

SDL_Rect rotatePoint(int x, int y, int Xorigin, int Yorigin, double rotation);
double degreeToRads(double degree);
bool overRect(int x, int y, SDL_Rect rect);
bool overRect(int x, int y, SDL_Rect rect, double percent, int HEIGHTborder, int WIDTHborder);
bool over(int x, int y, SDL_Rect OriginalRect, double rotation, double scale, double screen, double percent, int HEIGHTborder, int WIDTHborder);