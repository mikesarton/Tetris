#include "tetrisgame.h"

namespace mikoli{

//  constructeur par défaut

TetrisGame::TetrisGame(){}

//  constructeur avec paramètres
TetrisGame::TetrisGame(int width, int height){
    _tetrisMusic = new SoundPlayer("tetris.mp3", true);
    _tetrisMusic->play();
    _tetrisMusic->switchMute();
    _tetrisMusic->setVolume(30);
    _fallSound = new SoundPlayer("figTouchDown.mp3", false);
    _deleteOneLineSound = new SoundPlayer("oneLine.mp3", false);
    _deleteTwoLineSound = new SoundPlayer("twoLines.mp3", false);
    _deleteThreeLineSound = new SoundPlayer("threeLines.mp3", false);
    _deleteFourLineSound = new SoundPlayer("fourLines.mp3", false);
    _gameOverSound = new SoundPlayer("gameOver.mp3", false);
    _gameOverSound->setVolume(40);
    _goPause = new SoundPlayer("pauseGo.mp3", false);
    _backPause = new SoundPlayer("pauseBack.mp3", false);

    _board = Board(height, width);
    _figuresBag = FiguresBag();
    _isBegin = false;
    _isPaused = true;
    _isGameOver = false;
    _isWon = false;
    _isFalling = false;
    _currentScore = Score();
    _currentFigure = _figuresBag.getNextFigure();
    _nextFigure = _figuresBag.getNextFigure() ;
    _currentFigure.newPosition(_board.entryPoint());
    calculateShadow();
    _mode = Mode(Gamemode::NONE, 0);
    _timerGame = new Timer();
}

//  destructeur
TetrisGame::~TetrisGame(){}

//  retourne la figure courante
Figure TetrisGame::getCurrentFig(){
    return _currentFigure;
}

//  retourne un vector avec les blocs de la shadow
std::vector<Block> TetrisGame::getShadowCF() const {
    std::vector<Block> blocks;
    for(int i=0; i<4; ++i) {
        blocks.push_back(_shadowCF[i]);
    }
    return blocks;
}

//  retourne la figure suivante
Figure TetrisGame::getNextFig(){
    return _nextFigure;
}

//  retourne le board
Board TetrisGame::getBoard(){
    return _board;
}

bool TetrisGame::isGameOver(){
    return _isGameOver;
}

bool TetrisGame::isWon(){
    return _isWon;
}

Timer* TetrisGame::getTimer(){
    return _timerGame;
}

int TetrisGame::getScore(){
    return _currentScore.getScore();
}
int TetrisGame::getLevel(){
    return _currentScore.getLevel();
}
int TetrisGame::getNbLines(){
    return _currentScore.getNbLines();
}

Mode TetrisGame::getMode(){
    return _mode;
}

bool TetrisGame::isBegin(){
    return _isBegin;
}
bool TetrisGame::isPaused(){
    return _isPaused;
}

//  retourne la vitesse que le jeu devrait avoir à l'instant T
//  calcul fait en fonction du niveau
int TetrisGame::getSpeed(){
    int speed;
    if(_currentScore.getLevel() < 15){
        speed = 1000 - (_currentScore.getLevel() * 62.5);
    } else {
        return 110;
    }
    return speed;
}

bool TetrisGame::getIsFalling(){
    return _isFalling;
}

//  déplace, si possible, la figure courante dans la direction "direction"
void TetrisGame::move(Direction direction){
    if(_isPaused || _isGameOver){
        return;
    }
    if(_isFalling){
        direction=Direction::DOWN;
    }
    _board.move(_currentFigure, direction);
    calculateShadow();
    Notify();
    if(!_board.canGoLower(_currentFigure) && _autoDown) {
        endMove(0);
    }
    _autoDown = false;
    isWin();
}

//  rotationne, si possible, la figure courante dans la direction "direction"
void TetrisGame::rotate(Direction direction){
    if(_isPaused || _isGameOver || _isFalling){
        return;
    }
    _board.rotate(_currentFigure, direction);
    calculateShadow();
    Notify();
}

//  vérifie si les conditions de victoire (en cas d'un gameMode activé) sont remplies
void TetrisGame::isWin(){
    if(_mode.getGameMode() != Gamemode::NONE){
        if((_mode.getGameMode() == Gamemode::NBLINES) && (_currentScore.getNbLines() >= _mode.getGoal())){
            _isGameOver = true;
            _isWon = true;
            endGame();
            Notify();
        } else if((_mode.getGameMode() == Gamemode::SCORE) && (_currentScore.getScore() >= _mode.getGoal())){
            _isGameOver = true;
            _isWon = true;
            endGame();
            Notify();
        } else if((_mode.getGameMode() ==                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             