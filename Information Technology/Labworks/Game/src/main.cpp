#include <iostream>
#include <windows.h>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <cmath>

using namespace sf;
using namespace std;


int width = 96;
int height = 128;

int ground = 800-height;
int left_side = -15;
int right_side = 1115;

class Object {
	public:
		Texture texture;
		Sprite image;
		float x = 0;
		float y = 0;
		float width = 0;
		float height = 0;
		float mass = 0;
		Vector2f velocity;
		bool moving = false;
		bool can_collide = false;

		Object(string filename) {
			bool a = texture.loadFromFile(filename);
			image.setTexture(texture);
			width = texture.getSize().x;
			height = texture.getSize().y;
			image.setOrigin({width / 2, height / 2});

			x = image.getPosition().x;
			y = image.getPosition().y;

			velocity = Vector2f();
			velocity.x = 0.;
			velocity.y = 0.;
		};
		~Object(){};
		void Move(float new_x, float new_y) {
			image.setPosition({new_x, new_y});
			x = new_x;
			y = new_y;
		};
		void setImage(string filename) {
			bool a = texture.loadFromFile(filename);
			image.setTexture(texture);
		};
		void setScale(float x_scale, float y_scale) {
			image.setScale({x_scale, y_scale});
			width *= x_scale;
			height *= y_scale;
		};

};

class PLAYER {
	public:
		float dx, dy;
		FloatRect rect;
		bool onGround;
		Sprite sprite;
		float currentFrame;
		bool sit;

		PLAYER(Texture &image) {
			sprite.setTexture(image);
			rect = FloatRect({0, (float) (800 - height)}, {(float) width , (float) height});
			currentFrame = 3;
			dx = 0; dy = 0;
		}

		void update(float time) {
			
			rect.left += dx * time;

			if (rect.left > right_side) {
				rect.left = right_side;
				dx = 0;
			}
			if (rect.left < left_side) {
				rect.left = left_side;
				dx = 0;
			}

			if (!onGround) {
				dy += 0.0005 * time;
			}

			rect.top += dy * time;
			
			onGround = false;

			if (rect.top > ground) {
				rect.top = ground;
				dy = 0;
				onGround = true;
				sprite.setTextureRect(IntRect({width * 3 , height * 2}, {width, height}));
			}
			
			currentFrame += 0.002 * time;
			
			
			if (currentFrame > 6) {
				currentFrame -= 3;
			}
			if (dy > 0) {
				
				if (dx > 0) {
					sprite.setTextureRect(IntRect({width * 2, height * 0}, {width, height}));
				}
				
				if (dx < 0) {
					sprite.setTextureRect(IntRect({width * 3, height * 0}, {-width, height}));
				}
				
				if (dx == 0) {
					sprite.setTextureRect(IntRect({width * 4, height * 0}, {width, height}));
				}

			} else if (dy < 0) {
				
				if (dx > 0) {
					sprite.setTextureRect(IntRect({width * 1, height * 0}, {width, height}));
				}
				
				if (dx < 0) {
					sprite.setTextureRect(IntRect({width * 2, height * 0}, {-width, height}));
				}
				
				if (dx == 0) {
					sprite.setTextureRect(IntRect({width * 7, height * 0}, {width, height}));
				}

			} else {

				if (abs(dx * 20) == 1) {

					if (dx > 0) {
						sprite.setTextureRect(IntRect({(width*int(currentFrame)) - width, height * 4}, {width, height}));
					}
				
					if (dx < 0) {
						sprite.setTextureRect(IntRect({(width*int(currentFrame)), height * 4}, {-width, height}));
					}
				
				}
				if (abs(dx * 20) == 2) {
					
					if (dx > 0) {
						sprite.setTextureRect(IntRect({width*(int(currentFrame) + 3), height * 2}, {width, height}));
					}
				
					if (dx < 0) {
						sprite.setTextureRect(IntRect({width*(int(currentFrame) + 4), height * 2}, {-width, height}));
					}
				}
				
				if (dx == 0) {
						sprite.setTextureRect(IntRect({width * 3 , height * 2}, {width, height}));
				}

			}
			
			if (sit) {
				
				if (dy == 0) {
					
					if (dx == 0) {
						sprite.setTextureRect(IntRect({width * 3, height * 0}, {width, height}));
					} else if (dx > 0) {
						sprite.setTextureRect(IntRect({width * 1, height * 1}, {width, height}));
					} else  {
						sprite.setTextureRect(IntRect({width * 2, height * 1}, {-width, height}));
					}
				}
				
				sit = false;
			}

			sprite.setPosition({rect.left, rect.top}); 

			dx = 0;
		}
};

unsigned window_width = 1200;
unsigned window_height = 800;

Object sun("sun.png");
Object background("background.jpg");

int main()
{
	Texture t;

	int choice = 0;
	std::cout << "What person do you want?\n1:\tRobot\n2:\tMale person\n3:\tMale adventurer\n4:\tFemale person\n5:\tFemale adventurer\n6:\tZombie\nYour choice: ";
	std::cin >> choice;
	switch (choice) {
		case 1: {bool a = t.loadFromFile("C:/IT/IT_LR/LR9/build/kenney_tooncharacters1/Robot/Tilesheet/character_robot_sheet.png"); break;}
		case 2: {bool a = t.loadFromFile("C:/IT/IT_LR/LR9/build/kenney_tooncharacters1/Male\ person/Tilesheet/character_malePerson_sheet.png"); break;}
		case 3: {bool a = t.loadFromFile("C:/IT/IT_LR/LR9/build/kenney_tooncharacters1/Male\ adventurer/Tilesheet/character_maleAdventurer_sheet.png"); break;}
		case 4: {bool a = t.loadFromFile("C:/IT/IT_LR/LR9/build/kenney_tooncharacters1/Female\ person/Tilesheet/character_femalePerson_sheet.png"); break;}
		case 5: {bool a = t.loadFromFile("C:/IT/IT_LR/LR9/build/kenney_tooncharacters1/Female\ adventurer/Tilesheet/character_femaleAdventurer_sheet.png"); break;}
		case 6: {bool a = t.loadFromFile("C:/IT/IT_LR/LR9/build/kenney_tooncharacters1/Zombie/Tilesheet/character_zombie_sheet.png"); break;}
	}

	RenderWindow window(VideoMode({window_width, window_height}), "SFML works!");
	
	sun.Move(window_width / 2, sun.height / 2);
	background.Move(window_width / 2, window_height / 4);
	
	
	PLAYER p(t);

	Clock clock;

	while (window.isOpen()) {
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time = time / 400;

		Event event; 
		while (window.pollEvent(event)) {

			if (event.type == Event::Closed) {
				window.close();
			}

        }

		if (Keyboard::isKeyPressed(Keyboard::A)) {
			p.dx = -0.05;
		}

		if (Keyboard::isKeyPressed(Keyboard::D)) {
			p.dx = 0.05;
		}

		if (Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::LControl)) {
			p.dx = -0.1;
		}

		if (Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::LControl)) {
			p.dx = 0.1;
		}

		if (Keyboard::isKeyPressed(Keyboard::W)) {
			if (p.onGround) {
				p.dy = -0.5;
				p.onGround = false;
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::S)) {
			p.sit = true;
		}
		
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}
	
		p.update(time);

		window.clear(Color::White);

		window.draw(background.image);
		window.draw(sun.image);
		window.draw(p.sprite);

		window.display();
	}

	return 0;
}