#ifndef TEXTCLEANER_H
#define TEXTCLEANER_H

class TextCleaner {
public:
    void setText(const char* inputText);
    void removeDuplicates();
    const char* getProcessedText() const;

private:
    char* text = nullptr;
};

#endif