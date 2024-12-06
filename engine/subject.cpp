#include "subject.h"
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>

std::string Subject::replace_word(const std::string& text, const std::string& old_word, const std::string& new_word) {
    if (old_word.empty()) {
        return text;
    }
    std::string result = text;
    size_t pos = 0;

    while ((pos = result.find(old_word, pos)) != std::string::npos) {
        result.replace(pos, old_word.length(), new_word);
        pos += new_word.length();
    }

    return result;
}

std::string Subject::search_phrase(const std::string& text, const std::string& phrase) {
    return text.find(phrase) != std::string::npos ? "Phrase found" : "Phrase not found";
}

std::string Subject::capitalize_words(const std::string& text) {
    std::string result = text;
    bool capitalize = true;
    for (char& ch : result) {
        if (std::isspace(ch)) {
            capitalize = true;
        } else if (capitalize && std::isalpha(ch)) {
            ch = std::toupper(ch);
            capitalize = false;
        }
    }
    return result;
}

std::string Subject::capitalize_sentences(const std::string& text) {
    std::string result = text;
    bool capitalize = true;
    for (char& ch : result) {
        if (capitalize && std::isalpha(ch)) {
            ch = std::toupper(ch);
            capitalize = false;
        }
        if (ch == '.' || ch == '!' || ch == '?') {
            capitalize = true;
        }
    }
    return result;
}

std::string Subject::add_sentence_numbers(const std::string& text) {
    std::stringstream input(text);
    std::stringstream output;
    std::string sentence;
    int counter = 1;

    while (std::getline(input, sentence, '.')) {
        if (!sentence.empty()) {
            std::string trimmed_sentence = sentence;
            trimmed_sentence.erase(0, trimmed_sentence.find_first_not_of(" \t"));
            output << counter++ << ". " << trimmed_sentence << "." << std::endl;
        }
    }
    return output.str();
}