#ifndef GAMEMODE_H
#define GAMEMODE_H

namespace mikoli {

/*!
 * \brief The Gamemode enum
 * All the modes possible
 */
enum class Gamemode {
    NBLINES, TIME, SCORE, NONE
};

int gmToInt (Gamemode);
Gamemode intToGm (int);

}

#endif // GAMEMODE_H
