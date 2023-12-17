#ifndef CHARACTER_HPP
#define CHARACTER_HPP

enum class CharacterType {
    NUMERIC,
    OPERATOR,
    EQUALITY
};

class Character {
public:
    virtual ~Character() {}

    virtual const CharacterType getType() = 0;
    virtual const char toChar() = 0;

    static Character* fromChar(const char c);
};

#endif // CHARACTER_HPP
