#include <stdexcept>
#include <iostream>
#include <SFML/Graphics.hpp>

class GameException : public std::exception {
public:
  explicit GameException(const std::string& message) : message_(message) {}

  const char* what() const noexcept override {
    return message_.c_str();
  }

private:
  std::string message_;
};

//exception to handle a erro of Load texture
void loadTexture(const std::string& filePath, sf::Texture& texture) {
  if (!texture.loadFromFile(filePath)) {
    throw GameException("Failed to load texture: " + filePath);
  }
}
