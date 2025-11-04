#include "TextObject.h"
#include "Text.h"
#include "Renderer.h"

TextObject::TextObject(const char* fontPath, int size)
{
	m_text = new Text(); 
	m_text->SetFont(fontPath, size);
}

void TextObject::Render()
{
	if (m_text != nullptr)
	{
		Renderer::Get()->DrawObject(m_text->GetTexture(), &rect);
	}
}

const char* TextObject::GetName()
{
	return "text";
}

void TextObject::SetText(const char* newText)
{
	if (m_text == nullptr)
	{
		return;
	}
	m_text->SetText(newText, &rect.w, &rect.h);
	
}
