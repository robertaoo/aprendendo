#include "Camera.hpp"
#include "GameLevelController.hpp"

Camera::Camera(sf::RenderWindow *window) {
    m_window = window;
}

Camera::~Camera() {

}

void Camera::Start() {

}

void Camera::Update(float deltaTime) {
    sf::View viewCurr = m_window->getView();
    sf::Vector2f playerPos = GameLevelController::getInstance().getPlayer()->getPosition();
    sf::Vector2f oldCenter = viewCurr.getCenter();

    if (playerPos.x >= oldCenter.x) {
        viewCurr.setCenter(playerPos.x, oldCenter.y);
        m_window->setView(viewCurr);
    }
}

