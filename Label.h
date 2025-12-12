#pragma once

#include <string>

class Label
{
public:
    Label();
    explicit Label(const std::string& text);

    void SetText(const std::string& text);
    const std::string& GetText() const;
    bool Empty() const noexcept;

private:
    std::string m_text;
};