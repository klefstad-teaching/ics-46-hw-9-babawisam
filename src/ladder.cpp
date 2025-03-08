#include "ladder.h"

void error(std::string word1, std::string word2, std::string msg) {
    std::cerr << "Error with words '" << word1 << "' and '" << word2 << "': " << msg << std::endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    int len1 = str1.length();
    int len2 = str2.length();
    
    if (std::abs(len1 - len2) > d) {
        return false;
    }

    int diff_count = 0;

    if (len1 == len2) {
        for (size_t i = 0; i < len1; ++i) {
            if (str1[i] != str2[i]) {
                ++diff_count;
                if (diff_count > d) return false;
            }
        }
        return diff_count <= d;
    } 
    
    const std::string &shorter = (len1 < len2) ? str1 : str2;
    const std::string &longer = (len1 < len2) ? str2 : str1;

    size_t i = 0, j = 0;
    while (i < shorter.length() && j < longer.length()) {
        if (shorter[i] != longer[j]) {
            if (++diff_count > d) return false;
            ++j;
        } else {
            ++i;
            ++j;
        }
    }

    while (j < longer.length()) {
        if (++diff_count > d) return false;
        ++j;
    }

    return true;
}

bool is_adjacent(const std::string& word1, const std::string& word2) {
    return edit_distance_within(word1, word2, 1);
}

std::vector<std::string> generate_word_ladder(const std::string& begin_word, const std::string& end_word, const std::set<std::string>& word_list) {
    std::queue<std::vector<std::string>> ladder_queue;
    ladder_queue.push({begin_word});
    std::set<std::string> visited;
    visited.insert(begin_word);
    
    while (!ladder_queue.empty()) {
        std::vector<std::string> ladder = ladder_queue.front();
        ladder_queue.pop();
        std::string last_word = ladder.back();
        
        for (const std::string& word : word_list) {
            if (is_adjacent(last_word, word) && visited.find(word) == visited.end()) {
                visited.insert(word);
                std::vector<std::string> new_ladder = ladder;
                new_ladder.push_back(word);
                
                if (word == end_word) {
                    return new_ladder;
                }
                
                ladder_queue.push(new_ladder);
            }
        }
    }
    
    return {};
}

void load_words(std::set<std::string>& word_list, const std::string& file_name) {
    word_list.clear();

    std::ifstream in(file_name);

    if (!in) {
        error(file_name, "File error", "Could not open file for reading.");
        return;
    }

    for (std::string word; in >> word;) {
        word_list.insert(word);
    }
}

void print_word_ladder(const std::vector<std::string>& ladder) {

    if (ladder.empty()) {
        std::cout << "No word ladder found." << std::endl;
        return;
    }

    std::cout << "Word ladder found: ";
    for (int i = 0; i < ladder.size(); i++) {
        std::cout << ladder[i];
        if (i < ladder.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}
void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "../src/words.txt");
    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}