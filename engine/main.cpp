#include "wrapper.h"
#include "subject.h"
#include "engine.h"
#include <iostream>

int main() {
    Subject subject;

    // Инициализация объектов Wrapper для различных методов Subject
    Wrapper replace_word_wrapper(&subject, &Subject::replace_word, {
        {"text", ""}, 
        {"old_word", ""}, 
        {"new_word", ""}
    });
    Wrapper search_phrase_wrapper(&subject, &Subject::search_phrase, {
        {"text", ""}, 
        {"phrase", ""}
    });
    Wrapper capitalize_words_wrapper(&subject, &Subject::capitalize_words, {
        {"text", ""}
    });
    Wrapper capitalize_sentences_wrapper(&subject, &Subject::capitalize_sentences, {
        {"text", ""}
    });
    Wrapper add_sentence_numbers_wrapper(&subject, &Subject::add_sentence_numbers, {
        {"text", ""}
    });

    // Инициализация объекта Engine и регистрация команд
    Engine engine;
    engine.register_command(&replace_word_wrapper, "replace_word");
    engine.register_command(&search_phrase_wrapper, "search_phrase");
    engine.register_command(&capitalize_words_wrapper, "capitalize_words");
    engine.register_command(&capitalize_sentences_wrapper, "capitalize_sentences");
    engine.register_command(&add_sentence_numbers_wrapper, "add_sentence_numbers");

    engine.register_command(&add_sentence_numbers_wrapper, "replace_word");

    std::cout << engine.execute("replace_word", {
        {"text", "Replace ME"}, 
        {"old_word", "ME"}, 
        {"new_word", "(replaced)"}
    }) << std::endl;

    std::cout << engine.execute("search_phrase", {
        {"text", "find ME"}, 
        {"phrase", "ME"}
    }) << std::endl;

    std::cout << engine.execute("search_phrase", {
        {"text", "do not find ME"}, 
        {"phrase", "Me"}
    }) << std::endl;

    std::cout << engine.execute("capitalize_words", {
        {"text", "capitalize every every word in this sentence"}
    }) << std::endl;

    std::cout << engine.execute("capitalize_sentences", {
        {"text", "capitalize every. first. letter of this 3 sentences."}
    }) << std::endl;

    std::cout << engine.execute("add_sentence_numbers", {
        {"text", "enumerate. every sentence. from. Here please"}
    }) << std::endl;

    return 0;
}