#include "Label.h"

Label::Label(const std::string& text)
    : m_text(text)
{
}

void Label::SetText(const std::string& text)
{
    m_text = text;
}

const std::string& Label::GetText() const
{
    return m_text;
}

bool Label::Empty() const noexcept
{
    return m_text.empty();
}