#include "SelectorParser.h"

std::vector<SelectorParser::Token> SelectorParser::tokenize(const std::string& selector) {
    std::vector<Token> tokens;
    std::istringstream iss(selector);
    std::string word;

    while (iss >> word) {
        if (word == "chain") {
            tokens.push_back({TokenType::CHAIN, word});
        }
        else if (word == "resn") {
            tokens.push_back({TokenType::RESN, word});
        }
        else if (word == "resi") {
            tokens.push_back({TokenType::RESI, word});
        }
        else if (word == "atom") {
            tokens.push_back({TokenType::ATOM, word});
        }
        else if (word == "and") {
            tokens.push_back({TokenType::AND, word});
        }
        else if (word == "or") {
            tokens.push_back({TokenType::OR, word});
        }
        else if (word == "not") {
            tokens.push_back({TokenType::NOT, word});
        }
        else if (word == "all") {
            tokens.push_back({TokenType::ALL, word});
        }
        else if (word == "(") {
            tokens.push_back({TokenType::LPAREN, word});
        }
        else if (word == ")") {
            tokens.push_back({TokenType::RPAREN, word});
        }
        else if (word == "-") {
            tokens.push_back({TokenType::DASH, word});
        }
        else if (word == ",") {
            tokens.push_back({TokenType::COMMA, word});
        }
        else if (std::isdigit(word[0])) {
            tokens.push_back({TokenType::NUMBER, word});
        }
        else {
            tokens.push_back({TokenType::IDENTIFIER, word});
        }
    }
    tokens.push_back({TokenType::END, ""});
    return tokens;
}