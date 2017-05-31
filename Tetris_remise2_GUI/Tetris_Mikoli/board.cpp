#include "board.h"

namespace mikoli{

//    Constructeur par défaut
Board::Board() : Board(20, 10){}

//    Constructeur avec paramètres
Board::Board(int height, int width) : _height{validationHeight(height)}, _width{validationWidth(width)}{
    _entryPoint = entryPoint();
    _rotationSound = new SoundPlayer("figRotation.mp3", false);
    _rotationFailSound = new SoundPlayer("figRotationFail.mp3", false);
}

//  Getters

//  retourne la liste des blocks du board
std::list<Block> Board::getBlocks() const {
    return _listBlocks;
}

//  ajoute une figure à la liste du board (la currentFigure)
void Board::addFigure(Figure & cF) {
    for(Block bl: cF.getBlocks()){
        _listBlocks.push_back(bl);
    }
}

//  vérifie si la currentFigure peut aller plus bas
bool Board::canGoLower(Figure & cF) {
    for(Block bl : cF.getBlocks()) {
        for(Block blTab : _listBlocks) {
            if((bl.getPosition().getX() == blTab.getPosition().getX()) && (bl.getPosition().getY() -1 == blTab.getPosition().getY())) {
                return false;
            }
        }
        if(bl.getPosition().getY() - 1 <= 0) {
            return false;
        }
    }
    return true;
}

//  méthodes de validation
int Board::validationHeight(int nb){
    if(nb < 10){
        throw TetrisException {"Height invalid for the board, minimum 10."};
    }
    return nb;
}

int Board::validationWidth(int nb){
    if(nb < 5){
        throw TetrisException {"Parameter invalid for the board, minimum 5."};
    }
    return nb;
}

//  autres méthodes
// déplace la currentFigure dans la direction "direction"
void Board::move(Figure & cF, Direction direction){
    if(canMove(cF, direction)){
        cF.move(direction);
    }
}

//  rotationne la currentFigure dans la direction "direction"
void Board::rotate(Figure & cF, Direction direction){
    if(canRotate(cF, direction)){
        if(cF.getTypeFigure() != TypeShape::O){
            _rotationSound->play();
        } else {
            _rotationFailSound->play();
        }
        cF.rotate(direction);
    } else {
        _rotationFailSound->play();
    }
}

//  vérifie que la currentFigure peut bouger dans la direction "direction"
bool Board::canMove(Figure cF, Direction direction){
    cF.move(direction);
    return areBlocksAvailable(cF);
}

//  vérifie que la currentFigure peut rotationner dans la direction "direction"
bool Board::canRotate(Figure cF, Direction direction){
    cF.rotate(direction);
    return areBlocksAvailable(cF);
}

//  vérifie que la currentFigure peut entrer dans le board à l'entryPoint
bool Board::canPut(Figure cF){
    cF.newPosition(entryPoint());
    return areBlocksAvailable(cF);
}

//  vérifie qu'aucune position de la currentFigure n'est égale à une d'un bloc
//    du board ou que la currentFigure ne sorte pas des dimensions du board
bool Board::areBlocksAvailable(Figure cF){
    std::list<Position> listPosBoard;

    for(Block bl : _listBlocks){
        listPosBoard.push_back(bl.getPosition());
    }

    for(Position posCF : cF.getPositions()){
        for(Position posBoard : listPosBoard){
            if(posCF.isSame(posBoard)){
                return false;
            }
        }
        if(posCF.getX() <= 0 || posCF.getX() > _width){
            return false;
        }
        if(posCF.getY() <= 0 || posCF.getY() > _height){
            return false;
        }
    }
    return true;
}

//  vérifie s'il y a une ligne de complète et renvoit son y le cas échéant
int Board::checkLines(){
    std::unordered_map<int, int> lines;
    int lineToRemove = 0;

    for(Block bl : _listBlocks){
        Position posB = bl.getPosition();
        auto it = lines.find(posB.getY());
        if(it == lines.end()){
            lines.insert({posB.getY(), 1});
        } else {
            lines.at(posB.getY()) += 1;
        }
    }

    for(auto it = lines.begin(); it != lines.end(); ++it){
        if(it->second == _width){
            lineToRemove = it->first;
            break;
        }
    }
    return lineToRemove;
}

//  reçoit un y (une ligne) et supprime tous les b                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  