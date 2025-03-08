#include "ladder.h"

void error(std::string word1, std::string word2, std::string msg) {
    // TODO: Implement error handling
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    // TODO: Implement edit distance check
    return false;
}

bool is_adjacent(const std::string& word1, const std::string& word2) {
    // TODO: Implement adjacency check
    return false;
}

std::vector<std::string> generate_word_ladder(const std::string& begin_word, const std::string& end_word, const std::set<std::string>& word_list) {
    // TODO: Implement word ladder generation
    return {};
}

void load_words(std::set<std::string>& word_list, const std::string& file_name) {
    // TODO: Implement word loading from file
}

void print_word_ladder(const std::vector<std::string>& ladder) {
    // TODO: Implement word ladder printing
}

/*
//define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}
void verify_word_ladder() {
    std::set<std::string> word_list;
    load_words(word_list, "words.txt");
    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}
*/