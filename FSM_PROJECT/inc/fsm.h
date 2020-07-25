#ifndef __FSM__
#define __FSM__

#define MAX_FSM_NAME                255
#define MAX_IP_BUFFER               255
#define MAX_STATE_NAME              255
#define MAX_TRANSITION_TABLE_ENTRY  255

typedef enum {False,True} FSMBool;

typedef _transitionTable
{
    transitionTableEntry_t
        transitionTableEntry[MAX_TRANSITION_TABLE_ENTRY];

}transitionTable_t

typedef _state
{
    /*Name of a state*/
    char                 state_name[MAX_STATE_NAME];

    /*Transition Table of the state*/
    transitionTable_t    transition_table;

    /*check for Final state or not*/
    FSMBool               is_finale_state;
}state_t;

typedef struct _fsm
{
    /*Initial State of FSM*/
    state_t      *p_initial_state;

    /*Name of FSM*/
    char          fsm_name[MAX_FSM_NAME];

    /*Input Buffer Size*/
    unsigned char count;

    /*Input provided by user*/
    char          input_buffer[MAX_IP_BUFFER];

    /*Input Buffer currnt pos*/
    unsigned char  current_count;
}fsm_t;


#endif
