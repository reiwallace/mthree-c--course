#include <iostream>
#include <set>
#include <string>

/**
    Checks if a word is made up of all unique characters
    @param str - Word to check
    @returns True if the word has all unique characters or false if the word has any duplicate character
*/
bool areAllUnique(const std::string &str) {
    std::set<char> chars;

    for(char c : str) {
        // If insert wasn't successful - Set already has char
        if(!chars.insert(c).second) return false;
    }

    return true;
}

int main() {
    std::string word = "sample";

    std::cout << word << " is unique?" << std::endl;
    std::cout << (areAllUnique(word) ? "true" : "false") << std::endl;

    return 0;
}