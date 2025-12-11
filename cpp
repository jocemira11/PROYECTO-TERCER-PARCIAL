#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include <vector>

struct Cell {
    int type; // 0 vacío, >0 id de pieza
    sf::Color color;
};

struct Tetromino {
    int id;
    std::vector<std::array<sf::Vector2i,4>> rotations;
    sf::Color color;
};

class Tetris {
public:
    Tetris(int cols = 10, int rows = 20, int cellSize = 32);
    void reset();
    void update(float dt);
    void handleEvent(const sf::Event& e);
    void draw(sf::RenderWindow& window);

private:
    int cols, rows, cellSize;
    std::vector<Cell> grid;
    Tetromino current, next;
    sf::Vector2i pos;
    int rotationIndex;
    float fallTimer, fallInterval;
    bool paused, gameOver;
    int score, linesCleared, combo;

    std::vector<Tetromino> bag;
    sf::Font font;
    bool fontLoaded = false;
    sf::Text uiText;

    bool canMove(const Tetromino& t, sf::Vector2i p, int rot) const;
    void lockPiece();
    void clearLines();
    void spawnPiece();
    Tetromino randomFromBag();
    void applyPowerUps(int lines);
    void hardDrop();
    void softDrop();
    void move(int dx);
    void rotate(int dir);
    int index(int c, int r) const { return r*cols + c; }
    void drawGrid(sf::RenderWindow& window);
    void drawPiece(sf::RenderWindow& window, const Tetromino& t, sf::Vector2i p, int rot);
};
