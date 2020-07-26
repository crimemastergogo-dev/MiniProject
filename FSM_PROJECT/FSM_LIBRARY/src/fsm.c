#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <memory.h>
#include "fsm.h"


fsm_t *CreateFSM(const SInt8 *fsm_name)
{
    fsm_t *FSM = NULL;

    assert(fsm_name);

    FSM = (fsm_t*)malloc(sizeof(fsm_t));
    if(NULL == FSM)
    {
        printf("Memory Allocation Failed\n");
        exit(1);
    }

    memcpy(FSM->fsm_name,fsm_name,strlen(fsm_name)+1);
    FSM->fsm_name[strlen(FSM->fsm_name)+1] = '\0';

    return FSM;
}

state_t *CreateNewState(const SInt8 *state_name,FSMBool isFinal)
{
    state_t *state = NULL;

    assert(state_name);

    state = (state_t*)malloc(sizeof(sizeof(state_t)));
    if (NULL == state)
    {
        printf("Memory Allocation Failed");
        exit(1);
    }

    memcpy(state->state_name,state_name,strlen(state_name)+1);
    state->state_name[strlen[state->state_name]+1] = '\0';

    state->is_finale_state = isFinal; 

    return state;
}

void setInitialState(fsm_t *FSM,state_t *state)
{
    assert(!FSM->p_initial_state);

    FSM->p_initial_state = state;
}


FSMBool IsEmptyTransitionTableEntry(transitionTableEntry_t TTEntry)
{
    FSMBool isEmpty = False;

    if(TTEntry.p_next_state)
        isEmpty = True;

    return isEmpty;
}

transitionTableEntry_t *NextEmptyTTEntry(transitionTable_t *transition_table)
{
    transitionTableEntry_t *ret_val = NULL;
    UInt8 Index                     = 0;

    assert(NULL!=transition_table);

    for (Index = 0 ; Index < MAX_TRANSITION_TABLE_ENTRY ; Index++)
    {
        if (True == IsEmptyTransitionTableEntry(transition_table->transitionTableEntry[Index]))
        {
            ret_val = &transitionTableEntry[Index]; 
            break;
        }
    }

    return ret_val;
}

transitionTableEntry_t *CreateAndInsertNewTTEntry
(
 transitionTable_t *transition_table,
 SInt8   *transitionKey,
 UInt8   sizeofKey,
 state_t *nextState
)
{
    transitionTableEntry_t *p_Entry = NULL;

    assert(sizeofKey < MAX_TRANSITION_KEY);

    p_Entry = NextEmptyTTEntry(transition_table);

    if (NULL == p_Entry)
    {
        printf("Transiotion table entry Is FULL...!!!";)
            return;
    }
    
    p_Entry->count = sizeofKey;
    memcpy(p_Entry->transition_key,transition_key,sizeofKey);
    p_Entry->transition_key[sizeofKey] = '\0';
    p_Entry->p_next_state = nextState;

}

