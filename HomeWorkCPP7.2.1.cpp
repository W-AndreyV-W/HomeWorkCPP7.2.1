#include <string>
#include <iostream>
#include <algorithm>

class Text {

public:

    virtual void render(const std::string& data) const {

        std::cout << data;
    }
};


class DecoratedText : public Text {

public:

    explicit DecoratedText(Text* text) : text_(text) {}

    Text* text_;
};

class ItalicText : public DecoratedText {

public:

    explicit ItalicText(Text* text) : DecoratedText(text) {}

    void render(const std::string& data)  const override {

        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }
};

class BoldText : public DecoratedText {

public:

    explicit BoldText(Text* text) : DecoratedText(text) {}

    void render(const std::string& data) const override {

        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }
};

class Paragraph : public DecoratedText {

public:

    explicit Paragraph(Text* text) : DecoratedText(text) {}

    void render(const std::string& data) const override {

        std::cout << "<p>";
        text_->render(data);
        std::cout << "</p>";
    }
};

class Reversed : public DecoratedText {

public:

    explicit Reversed(Text* text) : DecoratedText(text) {}

    void render(const std::string& data) const override {
        
        std::string _data = data;
        std::reverse(_data.begin(), _data.end());
        text_->render(_data);
    }
};

class Link : public DecoratedText {

public:

    explicit Link(Text* text) : DecoratedText(text) {}

    void render(const std::string apostrophe, const std::string& data) const {

        std::cout << "<a " << apostrophe << ">";
        text_->render(data);
        std::cout << "</a>";
    }
};

int main() {

    auto text_block = new ItalicText(new BoldText(new Text()));
    text_block->render("Hello world");
    std::cout << std::endl;

    auto text_block_p = new Paragraph(new Text());
    text_block_p->render("Hello world");
    std::cout << std::endl;

    auto text_block_r = new Reversed(new Text());
    text_block_r->render("Hello world");
    std::cout << std::endl;

    auto text_block_l = new Link(new Text());
    text_block_l->render("netology.ru", "Hello world");
    std::cout << std::endl;
}