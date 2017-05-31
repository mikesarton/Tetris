#ifndef BOARD_H
#define BOARD_H

#include "figure.h"
#include "tetrisexception.h"
#include "soundplayer.h"
#include <list>
#include <math.h>
#include <unordered_map>
#include <iostream>


namespace mikoli{

/*!
 * \brief The Board class
 *
 * This class is used to represent a fictive board in which the user will play.
 * Here will stand the blocks and the current figure of the player.
 * A "fictive board" because it's not really a board.
 * It is a list of Block. This list contains only the blocks placed in the graphical board.
 * There are methods that allow to handle the moves of the current figure,
 * to rotate the current figure and the suppression of lines, the reorganization of the blocks in the "board".
 *
 * \ref _listBlocks The list of the blocks inside the board.
 * \ref _width The width of the board.
 * \ref _height The height of the board.
 * \ref _entryPoint The position where the current figure appears when she arrives in the board.
 */
class Board{
private:
    //Private Attributes
    /*!
     * \brief _listBlocks
     * This attribute composes the "board". It contains all the blocks that can be placed in the graphical board.
     * Used to know if a position is free or if it's possible to move/rotate/put a figure.
     */
    std::list<Block> _listBlocks;

    /*!
     * \brief height
     * This attribute is the logical height of the board.
     */
    int _height;

    /*!
     * \brief width
     * This attribute is the logical witdh of the board.
     */
    int _width;

    /*!
     * \brief _entryPoint
     * This attribute represent the entry point of each figure in the board.
     * Every time
     */
    Position _entryPoint;

    /*!
     * \brief _rotationSound
     * The sound when we rotate a figure.
     */
    SoundPlayer * _rotationSound;

    /*!
     * \brief _rotationFailSound
     * The sound when we can't rotate a figure.
     */
    SoundPlayer * _rotationFailSound;

public:

    //Constructors
    /*!
     * \brief Board's constructor without parameters.
     * This constructor uses the constructor with parameters by setting the height to 20 and the width to 10.
     */
    Board();

    /*!
     * \brief Board's constructor with parameters.
     * \param height The height of the board.
     * \param width The width of the board.
     */
    Board(int height, int width);

    // Destructor inline
    /*!
     * \brief ~Board's inline destructor.
     */
    inline ~Board(){}

    //Getter

    /*!
     * \brief getBlocks
     * \return The list of the blocks in the board.
     */
    std::list<Block> getBlocks() const ;

    //Others methods

    /*!
     * \brief addFigure
     * \param cF The figure to add in the board.
     * Add the current figure to the board's list of blocks.
     */
    void addFigure(Figure & cF);

    /*!
     * \brief canGoLower
     * \param cF The current figure to test.
     * \return True if the figure can go once down, false otherwise.
     */
    bool canGoLower(Figure & cF);

    /*!
     * \brief validationHeight
     * This method check if the number received is >= 10.
     * \param nb The number to validate.
     * \return The number if he's >= 10, an exception otherwise.
     * \throw TetrisException if nb < 10.
     */
    int validationHeight(int nb);

    /*!
     * \brief validationWidth
     * This method check if the number received is >= 5.
     * \param nb The number to validate.
     * \return The number if he's >= 5, an exception otherwise.
     * \throw TetrisException if nb < 5.
     */
    int validationWidth(int nb);

    /*!
     * \brief move
     * This method uses canMove() to check if it's possible to move
     * the figure in this direction, and if so, will actually move the figure
     * by calling her method move().
     *
     * If itsn't possible to move the figure, the method does nothing.
     * \param cF The current figure.
     * \param direction The direction into move the figure.
     */
    void move(Figure & cF, Direction direction);

    /*!
     * \brief rotate
     * \param cF The current figure to rotate
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     