#ifndef TETRISGAME_H
#define TETRISGAME_H

#include "figuresbag.h"
#include "board.h"
#include "soundplayer.h"
#include "gamemode.h"
#include "mode.h"
#include "score.h"
#include "timer.h"
#include "figure.h"
#include "position.h"
#include <QTimerEvent>
#include <QObject>
#include <chrono>
#include <list>

namespace mikoli{
/*!
 * \brief The TetrisGame class
 *
 * This class will be used for build a new game.
 *
 * \ref _figuresBag The list in which are each figure
 * that will become the next figure and then the current Figure.
 * \ref _currentFigure The figure that can be rotated or moved
 *  during its descent.
 * \ref _nextFigure
 */
class TetrisGame: public Observable{

private:
    // Privates attributes
    /*!
     * \brief _figuresBag
     * The list in which are each figure
     * that will become the next figure and then the current Figure.
     */
    FiguresBag _figuresBag;

    /*!
     * \brief _currentFigure The figure that can be rotated or moved,
     * by the player, during Its descent.
     */
    Figure _currentFigure;

    /*!
     * \brief _shadowCF
     * The shadow is the ghost figure, in white, that indicates
     * the player where it's figure will fall.
     */
    Block _shadowCF[4];

    /*!
     * \brief _nextFigure The next figure that will be played by the player
     */
    Figure _nextFigure;

    /*!
     * \brief _board
     */
    Board _board;

    /*!
     * \brief _currentScore
     * .
     */
    Score _currentScore;

    /*!
     * \brief _mode
     * The game mode.
     */
    Mode _mode;

    /*!
     * \brief _timerGame
     * A timer of the time the game is running.
     */
    Timer* _timerGame;

    /*!
     * \brief _isBegin
     */
    bool _isBegin;

    /*!
     * \brief _isPaused
     */
    bool _isPaused;

    /*!
     * \brief _isGameOver
     */
    bool _isGameOver;

    /*!
     * \brief _isFalling
     */
    bool _isFalling;

    /*!
     * \brief _autoDown
     */
    bool _autoDown;

    /*!
     * \brief _isWon
     */
    bool _isWon;

    /*!
     * \brief _tetrisMusic
     * The music of the game.
     */
    SoundPlayer * _tetrisMusic;

    /*!
     * \brief _goPause
     * Sound when we set the game in pause.
     */
    SoundPlayer * _goPause;

    /*!
     * \brief _backPause
     * Sound when we resume the game.
     */
    SoundPlayer * _backPause;

    /*!
     * \brief _gameOverSound
     * Sound when the game is over.
     */
    SoundPlayer * _gameOverSound;

    /*!
     * \brief _fallSound
     * Sound when the current figure touch the bottom after a fall.
     */
    SoundPlayer * _fallSound;

    //  differents sounds if we delete one, two, three of four line
    //  in one move.
    SoundPlayer * _deleteOneLineSound;
    SoundPlayer * _deleteTwoLineSound;
    SoundPlayer * _deleteThreeLineSound;
    SoundPlayer * _deleteFourLineSound;

public:
    // Constructor / destructor
    /*!
     * \brief TetrisGame's constructor without parameter.
     * Build a standard game with level mode "normal" and difficulty "normal".
     */
    TetrisGame();

    /*!
     * \brief TetrisGame's constructor with size parameters.
     * Build a standard game with level mode "normal" and difficulty "normal".
     */
    TetrisGame(int width,int height);

    /*!
     * \brief TetrisGame destructor.
     * Deallocate the memory that was previously reserved for the Game.
     */
    ~TetrisGame();

    //Getter

    /*!
     * \brief getCurrentFig
     * \return The current figure
     */
    Figure getCurrentFig();

    /*!
     * \brief getShadowCF
     * \return A vector with the blocks of the shadow.
     */
    std::vector<Block> getShadowCF() const;

    /*!
     * \brief getNextFig
     * \return The next figure.
     */
    Figure getNextFig();

    /*!
     * \brief getBoard
     * \return The board.
     */
    Board getBoard();

    /*!
     * \brief isGameOver
     * \return True is the game is over, false otherwise.
     */
    bool isGameOver();

    /*!
     * \brief isWon
     * \return True if the player reached it's goal, false otherwise.
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       