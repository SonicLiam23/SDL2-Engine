#include "ObjectBase.h"
#include "Renderer.h"

ObjectBase::ObjectBase() : m_img(nullptr), m_Position({0, 0, 320, 320}), CollisionEnabled(true)
{
}

void ObjectBase::Render()
{
	if (m_img != nullptr)
	{
		Renderer::Get()->DrawImage(m_img, &m_Position);
	}
}

void ObjectBase::SetImage(const char* Path)
{
	m_img = Renderer::Get()->AddImage(Path);
}

SDL_Rect* ObjectBase::GetPosition()
{
	return &m_Position;
}
