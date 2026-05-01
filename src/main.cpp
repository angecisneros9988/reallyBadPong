#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

void rectMoveUp(sf::RectangleShape &rect, float coords)
{
	if (rect.getPosition().y > 0)
		rect.setPosition(rect.getPosition() - sf::Vector2f(0.0f, 0.2f));
}
void rectMoveDown(sf::RectangleShape &rect, float coords)
{
	if (rect.getPosition().y < coords - rect.getSize().y)
		rect.setPosition(rect.getPosition() + sf::Vector2f(0.0f, 0.2f));
}

int main()
{
	sf::RenderWindow window(sf::VideoMode().getDesktopMode(), "SFML works!", sf::Style::Default, sf::State::Windowed);
	sf::CircleShape shape(25.f);
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2.25));
	sf::RectangleShape rect(sf::Vector2f(20, 200));
	rect.setFillColor(sf::Color::White);

	sf::RectangleShape botRect(sf::Vector2f(20, 200));
	botRect.setFillColor(sf::Color::White);
	botRect.setPosition(sf::Vector2f(window.getSize().x - 20, 0));
	// sf::Time t1 = sf::seconds(10.0f);
	bool changeTime = false;
	bool goBack = false;
	bool goDown = false;

	sf::Clock clock; // starts the clock

	while (window.isOpen())
	{
		while (const optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.draw(rect);
		window.draw(botRect);
		window.display();

		sf::Time elapsed1 = clock.getElapsedTime();

		if (shape.getPosition().x + shape.getRadius() > window.getSize().x)
			goBack = true;
		if (shape.getPosition().x + shape.getRadius() < 0)
		{
			goBack = false;

			if (shape.getPosition().y + shape.getRadius() < rect.getPosition().y)
				window.close();
			if (shape.getPosition().y + shape.getRadius() > rect.getPosition().y + rect.getSize().y)
				window.close();
		}

		// cout << "[TOP] : " << rect.getPosition().y << endl;
		// cout << "[BOTTOM] : " << rect.getPosition().y + rect.getSize().y << endl;
		// cout << "[BALL] : " << shape.getPosition().y << endl;

		if (shape.getPosition().y + shape.getRadius() > window.getSize().y)
			goDown = false;
		if (shape.getPosition().y + shape.getRadius() < 0)
			goDown = true;

		// BALL MOVE LOGIC
		if (goBack)
		{
			shape.setPosition(shape.getPosition() - sf::Vector2f(0.2f, 0.0f));
			shape.setFillColor(sf::Color::Red);
		}
		else
		{
			shape.setPosition(shape.getPosition() + sf::Vector2f(0.2f, 0.0f));
			shape.setFillColor(sf::Color::Cyan);
		}

		if (goDown)
			shape.setPosition(shape.getPosition() + sf::Vector2f(0.0f, 0.2f));
		else
			shape.setPosition(shape.getPosition() - sf::Vector2f(0.0f, 0.2f));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
			rectMoveUp(rect, window.getSize().y);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
			rectMoveDown(rect, window.getSize().y);

		if (shape.getPosition().y > botRect.getPosition().y)
			rectMoveDown(botRect, window.getSize().y);
		if (shape.getPosition().y < botRect.getPosition().y)
			rectMoveUp(botRect, window.getSize().y);
	}
}