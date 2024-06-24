#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>



using std:: cout;
using std:: endl;
using std:: ifstream;

using namespace std;
using namespace sf;



int main (int argc, char **argv)
{
   
   // big bulleye1 radius of 100
    sf::RenderWindow Window(sf::VideoMode(2024, 1024), "SFML Window");
    sf::CircleShape bulleye1(100.f);
    bulleye1.setFillColor(sf::Color::Blue);
    bulleye1.getGlobalBounds();
    
    //bulleye1 variables
    int pos_x {};
    int pos_y {};
    bulleye1.setPosition(pos_x, pos_y);
    int delta_x2 = 10;
    int delta_y2 = 3;
    
    // medium bulleye2 raius of 50
    sf::CircleShape bulleye2(50.f);
    bulleye2.setFillColor(sf::Color::Red);
    bulleye2.getGlobalBounds();
    //medium bulleye2  varaibles
    int pos_x2 { 50 };
    int pos_y2 {};
    bulleye2.setPosition(pos_x2, pos_y2);
    int delta_x3 = 10;
    int delta_y3 = 3;
    
    // small bulleye3 radius of 25
    sf::CircleShape bulleye3(35.f);
    bulleye3.setFillColor(sf::Color::Yellow);
    bulleye3.getGlobalBounds();
    // varisbles for bulleye3
    int pos_x3 { 60 };
    int pos_y3 {};
    bulleye3.setPosition(pos_x3, pos_y3);
    int delta_x4 = 10;
    int delta_y4 = 3;
    
//player1 details
    sf::RectangleShape player1(sf::Vector2f(85.f,75.f));
    player1.setFillColor(sf::Color::Green);
    player1.getGlobalBounds();
    
    //set position of player1
    int pos_x4{ 600 };
    int pos_y4{ 800 };
    player1.setPosition(pos_x4, pos_y4);
    int delta_x = 10;
     //might have to be delta
    
    // shoot the projectile/ create projectile
    sf::CircleShape projectile(15.f);
    projectile.setFillColor(sf::Color::Cyan);
    projectile.getGlobalBounds();
    
    bool shot = false;
    int pos_x5{ 630 };
    int pos_y5{ 775 };
    projectile.setPosition(pos_x5, pos_y5);
    int delta_x5 = 10;
    int delta_y5 = -25;
    int count {};// count for my if statwemnts 
    
    
  //opens window and closes window
    while (Window.isOpen())
    {
        
        Event event;
        
        while (Window. pollEvent(event))
        {
            if(event.type == Event::Closed) {
                Window.close();
                
            }
        }
        //Helps with finding a specific postion on the screen
        if (event.type == sf::Event::EventType::MouseMoved)
        {
            sf::Vector2i vec = sf::Mouse::getPosition(Window);
            std:: cout << vec.x << " " << vec.y << std::endl;
        }
        cout << "KC" << endl;
    
        if (event.type == Event::KeyPressed) {
            switch (event.key.code) {
                case Keyboard::Escape:
                    Window.close();
                    break;
                case Keyboard::Left:
                    player1.move(-60,0);
                    projectile.move(-60,0);
                    break;
                case Keyboard::Right:
                    player1.move(60,0);
                    projectile.move(60,0);
                    break;
                default:
                    break;
            }
        }
        
        //if space bar is clicked, the ball should move up//
        if (Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            projectile.move(0,-6.f); //will cause the ball to shoot
            pos_y5 -= 6;
        }
        if (pos_y5 <= 0) {
            
            projectile.setPosition(pos_x5, pos_x4);
            pos_y5 = pos_x4;
        }
        
        if (projectile.getGlobalBounds().intersects(bulleye2.getGlobalBounds())) {
            count++;
            projectile.setPosition(pos_x5, pos_y4);
        }
        //if the projectile reaches the top of screen
        // poation to its x and y value
       
        
        /* if (pos_y5 > 0){
           delta_y5 *= 1;
       }
       if (pos_y5 < 1200){
           delta_y5 *= 1;
       } */
       
        
        //this prevents the blue target from going off screen
         if (pos_x < 0) {
               delta_x2 *= -1;
               }
        //make the ball go right BLUE BALL
        if (pos_x > 1800) {
               delta_x2 *= -1;
               }
        //the red bulleye
        if (pos_x2 < 43) {
            delta_x3 *= -1;
        }
        if (pos_x2 > 1850) {
               delta_x3 *= -1;
               }
        //the yellow bulleye
        if (pos_x3 < 53) { //same with this one makes the yellow ball from going off the screen left
            delta_x4 *= -1;
        }
        if (pos_x3 > 1865) { //for right the coordinates are stwicched idkk why
               delta_x4 *= -1;
               }
     
        pos_x += delta_x2;
        pos_x2 += delta_x3;
        pos_x3 += delta_x4;
        pos_x4 += delta_x;
      
        
        
    // show all items on screen
    Window.clear();
    bulleye1.setPosition(pos_x, 100);
    bulleye2.setPosition(pos_x2, 145);
    bulleye3.setPosition(pos_x3, 160);
    Window.draw (bulleye1);
    Window.draw (bulleye2);
    Window.draw (bulleye3);
    Window.draw(player1);
    Window.draw(projectile);
    Window.display();
    sf::sleep(sf::milliseconds(10));
    }
 return 0;

}
