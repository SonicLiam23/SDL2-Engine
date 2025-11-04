#pragma once
#include "ObjectBase.h"
class Text;
class TextObject 
	: public ObjectBase
{
public:
	TextObject(const char* fontPath, int size);
	void Render() override;
	virtual const char* GetName() override;
	void SetText(const char* newText);

private:
	Text* m_text;
};

