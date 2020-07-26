#ifndef __FSM__
#define __FSM__

/*range 0<->255; size 1 byte*/
typedef unsigned char        UInt8;
/*range 0<->255 or -128<->127; size 1 byte*/
typedef char                 SInt8;
/*range -128<->127; size 1 byte*/
typedef signed char          Int8;
/*range 0<->65535 size 2 byte*/
typedef unsigned short       UInt16;
/*range -32768<->32767 size 2 byte*/
typedef signed short         SInt16;
/*range 0<->4,294,967,295 size 4 byte*/
typedef unsigned int         UInt32;
/*range -2147483648 to 2147483647, size 4 byte*/
typedef signed int           SInt32;
/*range -9223372036854775808<->9223372036854775807, size 8 byte*/
typedef unsigned long        ULong64;
/*range 0<->18446744073709551615, size 8 byte*/
typedef signed long          SLong64;
typedef unsigned long long   UInt64;
typedef signed long long     SInt64;
typedef float                UDouble32;
typedef double               UDouble64;

typedef struct  _state state_t;

#define MAX_FSM_NAME                32
#define MAX_IP_BUFFER               128
#define MAX_STATE_NAME              32
#define MAX_TRANSITION_TABLE_ENTRY  128
#define MAX_TRANSITION_KEY          64

typedef enum {False,True} FSMBool;

typedef struct _transitionTableEntry
{
    /*transition key count*/
    UInt8   count;

    /*Transition Key of a state*/
    SInt8   transition_key[MAX_TRANSITION_KEY];

    /*Next state*/
    state_t *p_next_state;

}transitionTableEntry_t;

typedef struct _transitionTable
{
    transitionTableEntry_t
        transitionTableEntry[MAX_TRANSITION_TABLE_ENTRY];

}transitionTable_t

typedef struct  _state
{
    /*Name of a state*/
    SInt8              state_name[MAX_STATE_NAME];

    /*Transition Table of the state*/
    transitionTable_t  transition_table;

    /*check for Final state or not*/
    FSMBool            is_finale_state;
}state_t;

typedef struct _fsm
{
    /*Initial State of FSM*/
    state_t   *p_initial_state;

    /*Name of FSM*/
    SInt8     fsm_name[MAX_FSM_NAME];

    /*Input Buffer Size*/
    UInt8     count;

    /*Input provided by user*/
    SInt8     input_buffer[MAX_IP_BUFFER];

    /*Input Buffer currnt pos*/
    UInt8     current_count;
}fsm_t;

/*create FSM API*/
fsm_t *CreateFSM(const SInt8 *fsm_name);

/*create New State*/
state_t *CreateNewState(const SInt8 * state_name,FSMBool isFinal);

/*Initial State*/
void setInitialState(fsm_t *FSM,state_t *state);

/*Insert transition table Entry into A Given state*/
transitionTableEntry_t *CreateAndInsertNewTTEntry
(
 transitionTable_t *transition_table,
 SInt8   *transitionKey,
 UInt8   sizeofKey,
 state_t *nextState
);

#endif
