#pragma once
#include <string>
#include <map>
#include <vector>

using namespace std;


class YB_ViewItemBasis
{
public:
	char viewId[6] = {};
	int x, y;				//the cordinate of upper left corner
	int w, h;				//the width/height of the viewitem

	vector<string> GetContent();	//several lines of the rendered texts
protected:
private:
	vector<string> viewContent;				//content for a line
};

