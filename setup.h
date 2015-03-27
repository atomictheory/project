#ifndef SETUP_H
#define SETUP_H

#define WINBOARD

#if (defined(__GNUC__) || defined(__GNUG__)) && !(defined(__clang__) || defined(__INTEL_COMPILER))
#define MY_GNU
#else
#define MY_MSVC
#endif

const int MOVE_HASH_SHIFT=(18);

#ifdef WINBOARD

const int NUM_THREADS=(4);
const int DEEP_POSITION_BUFFER_SIZE=(2);
const int DEEP_HASH_SHIFT=(1);

#else

const int NUM_THREADS=(4);
const int DEEP_POSITION_BUFFER_SIZE=(50000);
const int DEEP_HASH_SHIFT=(16);

#endif

#endif