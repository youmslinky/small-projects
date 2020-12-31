#include "life.h"

uint64_t findStillLife()
{
    static uint64_t startStateInt = 0;
    while(true)
    {
        set_state_to_uint64(startStateInt);
        calcNextState();
        uint64_t stateInt = array_to_uint64(state);

        //still life
        if(startStateInt == stateInt){
            return startStateInt++;
            break;
        }
        startStateInt++;
    }
}

void calcNextState()
{
    for (int r = 0; r < 8; ++r) {
        for (int c = 0; c < 8; ++c) {
            unsigned n = neighbors_count(c,r);
            if(n<2){
                nextState[c][r] = 0;
            }
            else if(n==2){
                nextState[c][r] = state[c][r];
            }
            else if(n==3){
                nextState[c][r] = 1;
            }
            else{
                nextState[c][r] = 0;
            }
        }
    }
    //copy nextState to state
    memcpy(state,nextState,8*8*sizeof(char));
}

void lifeAnimationCycle()
{
    //set_state_to_uint64(lfsr_next());
    //set_pixels_array(state);
    int draw_delay = 200;
    uint64_t stateU;
    uint64_t last_stateU;
    for(uint32_t i=0;i<100;i++)
    {
        calcNextState();
        //set_pixels_array(state);

        //check if only still life, or blank board
        last_stateU = stateU;
        stateU = array_to_uint64(state);

        //still life
        if(stateU == last_stateU){
            for(int i=0;i<10;i++){
                //digitalWrite(LED_BUILTIN, LOW);
                //delay(300);
                //digitalWrite(LED_BUILTIN, HIGH);
                //delay(300);
            }
            break;
        }
        //blank board
        if(stateU == (uint64_t)0){
            //digitalWrite(LED_BUILTIN, LOW);
            //delay(1000);
            //digitalWrite(LED_BUILTIN, HIGH);
            break;
        }
        //delay(draw_delay);

    }
}

unsigned neighbors_count(unsigned col, unsigned row)
{
    int count = 0;
    for(int r=-1;r<=1;r++){
        for(int c=-1;c<=1;c++){
            //don't count yourself
            if(c == 0 && r == 0) continue;
            if(state[(col+c)%8][(row+r)%8] == 1) count++;
        }
    }
    return count;
}
