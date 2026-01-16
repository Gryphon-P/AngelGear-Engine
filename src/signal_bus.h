/*
The signal bus contains a dictionary with all the signals sent in the game. Events could be like if the player is in a specific location
or if an AI takes damage.
*/

#include <map>
#include <string>
#include <utility>
#include "time.h"

static enum SignalType {
    SINGLE_FRAME, // Alerts for a single frame
    TIMED, // Keeps going for a certain duration
    PERSISTENT // Keeps going until stopped
};

static struct SignalBus {
    
    // std::map<signal name, std::pair<signal type, timed signal duration>>
    std::map<std::string, std::pair<SignalType, float>> signals;
    
    // Updates the timed durations and removes any completed signals
    void Update();


    


};

void EmitSignal(std::string signalName); // SINGLE_FRAME
void EmitTimedSignal(std::string signalName, float duration); // TIMED
void EmitPersistentSignal(std::string signalName); // PERSISTENT
void KillPersistentSignal(std::string signalName);