#ifndef _SELECTOR_PARSER_H
#define _SELECTOR_PARSER_H

#include "ProteinDOFparser_common.h"
#include <memory>

#include "Atom.h"


class SelectorParser {
public:
    enum class TokenType {
        CHAIN,      // chain
        RESN,       // residue name
        RESI,       // residue index
        ATOM,       // atom name
        AND,        // and
        OR,         // or
        NOT,        // not
        ALL,        // all
        NUMBER,     // 数字
        IDENTIFIER, // 标识符
        LPAREN,     // (
        RPAREN,     // )
        DASH,       // -
        COMMA,      // ,
        END        // 结束标记
    };

    struct Token {
        TokenType type;
        std::string value;
    };

    class SelectorExpression {
    public:
        virtual ~SelectorExpression() = default;
        virtual bool evaluate(const Atom& atom) const = 0;
    };

private:
    std::vector<Token> tokens;
    size_t current_pos = 0;

    // 词法分析方法
    std::vector<Token> tokenize(const std::string& selector);
    
    // 语法分析方法
    std::unique_ptr<SelectorExpression> parse();
    std::unique_ptr<SelectorExpression> parseOr();
    std::unique_ptr<SelectorExpression> parseAnd();
    std::unique_ptr<SelectorExpression> parseNot();
    std::unique_ptr<SelectorExpression> parsePrimary();

public:
    std::unique_ptr<SelectorExpression> parse(const std::string& selector);
};


#endif // _SELECTOR_PARSER_H