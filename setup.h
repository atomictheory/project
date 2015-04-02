#ifndef SETUP_H
#define SETUP_H

///////////////////////////////////////////////////
///////////////////////////////////////////////////

#define VARIANT_ATOMIC
//#define WINBOARD
#define ALLOW_BOOK
//#define SEARCH_MULTI

///////////////////////////////////////////////////
///////////////////////////////////////////////////

#define SETUP_DEEPNESS 10
#define SETUP_DEPTH_BONUS 5

#define SETUP_MAX_MINIMAX_DEPTH 30
#define SETUP_MAX_MINIMAX_PUFFER_SIZE 40
#define SETUP_MINIMAX_DEPTH 10
#define SETUP_INIT_DEPTH 10

#define SETUP_MAX_LISTED_MOVES 20

const int WINBOARD_DEPTH=(6);

///////////////////////////////////////////////////
// heuristic tuning

const int MOBILITY_BONUS=(10);
const int ATTACKER_BONUS=(15);
const int RANDOM_BONUS=(25);

const int PAWN_VALUE=(120);
const int KNIGHT_VALUE=(300);
const int BISHOP_VALUE=(300);
const int ROOK_VALUE=(500);
const int QUEEN_VALUE=(900);
const int KING_VALUE=(0);

///////////////////////////////////////////////////

#if (defined(__GNUC__) || defined(__GNUG__)) && !(defined(__clang__) || defined(__INTEL_COMPILER))
#define MY_GNU
#else
#define MY_MSVC
#endif

///////////////////////////////////////////////////

const int MOVE_HASH_SHIFT=(18);

#ifdef WINBOARD

const int NUM_THREADS=(4);
const int DEEP_POSITION_BUFFER_SIZE=(2);
const int DEEP_HASH_SHIFT=(1);

#else

const int NUM_THREADS=(4);
const int DEEP_POSITION_BUFFER_SIZE=(100000);
const int DEEP_HASH_SHIFT=(16);

#endif

#define SETUP_GENERATED_NODES (NUM_THREADS*5)

#endif