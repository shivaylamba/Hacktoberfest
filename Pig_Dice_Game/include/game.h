#ifndef GAME_H
#define GAME_H

#include "data.h"

/*!
 * Ask user for the next action, which might be either ROLL or HOLD.
 * \param turn_total_ Number of points accumulated in the current turn.
 * \param my_pts_ Number of points of the current player (human).
 * \param opponent_pts_ Number of points of the opponent player.
 * \param n_my_turn_rolls_ Number of time the dice has been rolled in this turn.
 *
 * \return The next action, chosen by the player.
 */
char human_play(TurnSnapshot &ts);

/*!
 * Ask AI for the next action, which might be either ROLL or HOLD.
 * \param turn_total_ Number of points accumulated in the current turn.
 * \param my_pts_ Number of points of the current player (human).
 * \param opponent_pts_ Number of points of the opponent player.
 * \param n_my_turn_rolls_ Number of time the dice has been rolled in this turn.
 *
 * \return The next action, chosen by the player.
 */
char ia_play(TurnSnapshot &ts);

/*!
 * Checks in the game state if one of the player has won.
 *
 * \param gst_ The game state.
 * \return true if a player has won, false otherwise.
 */
bool game_over(game_state &gs);

/*!
 * Process the game events and update de game state.
 * In this context, this means to ask the current player (either a
 * human or the AI) for the next action (either ROLL or HOLD).
 * After that, process the choice and add the points of the current
 * turn or pass the turn to the opponent.
 *
 * \param gst_ The game state.
 */
void call_and_update(game_state &gs);

/*!
 * Initalize the game state.
 * Reset all scores.
 * This method algo chooses who is going to start the game.
 *
 * \param gs The game state.
 */
void ini(game_state &gs);

/*!
 * Roll the dice.	
 * This method select a random number in te range [1, 6].
 *
 * \param gs The game state.
 * \return the random number like a dice face.
 */
int roll(void);



#endif