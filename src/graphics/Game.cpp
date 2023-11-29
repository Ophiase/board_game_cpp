#include "graphics/Game.hpp"
#include "graphics/ResourcesLoader.hpp"
#include "utils/Cli.hpp"
#include "graphics/screen/Text.hpp"
#include "geometry/Geometry.hpp"
#include "utils/NotImplemented.hpp"

Game::Game(Launcher *launcher, std::string title) : 
    Screen{launcher, title}, 
    currentPlayer{this, "Turn: ?"},
    exitButton{this, "Exit",
        [this](sf::Event) -> void{
            this->alive = false;
        },
    } {

    Cli::info("Choose : " + title);

    auto boardRes = ResourcesLoader::getTexture(Texture::CheckerBoard0)->getSize();
    this->checkBoardTexture.create(boardRes.x, boardRes.y);
    this->checkerBoardImage.setTexture(&checkBoardTexture.getTexture());
    this->checkerBoardImage.setPosition(BOARD_POSITION);
    this->checkerBoardImage.setSize(BOARD_SIZE);

    this->currentPlayer.setSizeY(0.04);
    this->currentPlayer.center(sf::Vector2f{0.75, 0.05});

    this->exitButton.setSizeY(0.04);
    this->exitButton.center(sf::Vector2f{0.10, 0.05});
};

void Game::setCurrentPlayer(std::string currentPlayer) {
    this->currentPlayer.setText("Turn: " + currentPlayer);
};

void Game::draw() {
    Screen::draw();  
    this->getRenderWindow().draw(this->checkerBoardImage);
};

void Game::updateBoard() {
    this->checkBoardTexture.clear(sf::Color::Transparent);

    sf::RectangleShape background{
        Geometry::toFloat(checkBoardTexture.getSize())};
    background.setTexture(ResourcesLoader::getTexture(Texture::CheckerBoard3));
    this->checkBoardTexture.draw(background);
};

void Game::updateBoardContent(Board board) {
    this->updateBoard();

    float cellSpace = (float)(this->checkBoardTexture.getSize().x / 8); 
    float pieceScale = 0.8;
    float pieceSize = cellSpace*pieceScale;

    sf::RectangleShape piece{sf::Vector2f{
        pieceSize, pieceSize
    }};

    float offset = pieceSize / 2.0;
    for (int x = 0; x < 8; x++) for (int y = 0; y < 8; y++) {
        CellPiece cell = board.getCell(CellPosition(x, y));
        if (!cell.isNone()) {
            float px = (cellSpace * (x + 0.5)) - offset;
            float py = (cellSpace * (y + 0.5)) - offset;

            piece.setPosition(px, py);
            piece.setTexture(ResourcesLoader::getTexture(cell));
            checkBoardTexture.draw(piece);
        }
    }
};

void Game::updateBoardSidedContent(BoardSided boardSided) {
    this->updateBoardContent(boardSided);
    throw NotImplemented();
};