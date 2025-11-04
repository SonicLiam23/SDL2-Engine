#include "ObjectBase.h"
#include "Renderer.h"

ObjectBase::ObjectBase(Rect pos) : m_img(nullptr), rect(pos), CollisionEnabled(true)
{

}

void ObjectBase::Render()
{
	if (m_img != nullptr)
	{
		Renderer::Get()->DrawImage(m_img, &rect);
	}
}

void ObjectBase::SetImage(const char* Path)
{
	m_img = Renderer::Get()->AddImage(Path);
}

Rect* ObjectBase::GetPosition()
{
	return &rect;
}
