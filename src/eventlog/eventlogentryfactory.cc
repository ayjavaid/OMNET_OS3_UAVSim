//=========================================================================
//  EVENTLOGENTRYFACTORY.CC - part of
//                  OMNeT++/OMNEST
//           Discrete System Simulation in C++
//
//  This is a generated file -- do not modify.
//
//=========================================================================

#include <stdio.h>
#include "event.h"
#include "eventlogentryfactory.h"

USING_NAMESPACE

EventLogTokenBasedEntry *EventLogEntryFactory::parseEntry(Event *event, int entryIndex, char **tokens, int numTokens)
{
    if (numTokens < 1)
        return NULL;

    char *code = tokens[0];
    EventLogTokenBasedEntry *entry;

    if (false)
        ;
    else if (code[0]=='S' && code[1]=='B' && code[2]==0)  // SB
        entry = new SimulationBeginEntry(event, entryIndex);
    else if (code[0]=='S' && code[1]=='E' && code[2]==0)  // SE
        entry = new SimulationEndEntry(event, entryIndex);
    else if (code[0]=='B' && code[1]=='U' && code[2]==0)  // BU
        entry = new BubbleEntry(event, entryIndex);
    else if (code[0]=='M' && code[1]=='B' && code[2]==0)  // MB
        entry = new ModuleMethodBeginEntry(event, entryIndex);
    else if (code[0]=='M' && code[1]=='E' && code[2]==0)  // ME
        entry = new ModuleMethodEndEntry(event, entryIndex);
    else if (code[0]=='M' && code[1]=='C' && code[2]==0)  // MC
        entry = new ModuleCreatedEntry(event, entryIndex);
    else if (code[0]=='M' && code[1]=='D' && code[2]==0)  // MD
        entry = new ModuleDeletedEntry(event, entryIndex);
    else if (code[0]=='M' && code[1]=='R' && code[2]==0)  // MR
        entry = new ModuleReparentedEntry(event, entryIndex);
    else if (code[0]=='G' && code[1]=='C' && code[2]==0)  // GC
        entry = new GateCreatedEntry(event, entryIndex);
    else if (code[0]=='G' && code[1]=='D' && code[2]==0)  // GD
        entry = new GateDeletedEntry(event, entryIndex);
    else if (code[0]=='C' && code[1]=='C' && code[2]==0)  // CC
        entry = new ConnectionCreatedEntry(event, entryIndex);
    else if (code[0]=='C' && code[1]=='D' && code[2]==0)  // CD
        entry = new ConnectionDeletedEntry(event, entryIndex);
    else if (code[0]=='C' && code[1]=='S' && code[2]==0)  // CS
        entry = new ConnectionDisplayStringChangedEntry(event, entryIndex);
    else if (code[0]=='M' && code[1]=='S' && code[2]==0)  // MS
        entry = new ModuleDisplayStringChangedEntry(event, entryIndex);
    else if (code[0]=='E' && code[1]==0)  // E
        entry = new EventEntry(event, entryIndex);
    else if (code[0]=='K' && code[1]=='F' && code[2]==0)  // KF
        entry = new KeyframeEntry(event, entryIndex);
    else if (code[0]=='C' && code[1]=='E' && code[2]==0)  // CE
        entry = new CancelEventEntry(event, entryIndex);
    else if (code[0]=='B' && code[1]=='S' && code[2]==0)  // BS
        entry = new BeginSendEntry(event, entryIndex);
    else if (code[0]=='E' && code[1]=='S' && code[2]==0)  // ES
        entry = new EndSendEntry(event, entryIndex);
    else if (code[0]=='S' && code[1]=='D' && code[2]==0)  // SD
        entry = new SendDirectEntry(event, entryIndex);
    else if (code[0]=='S' && code[1]=='H' && code[2]==0)  // SH
        entry = new SendHopEntry(event, entryIndex);
    else if (code[0]=='C' && code[1]=='M' && code[2]==0)  // CM
        entry = new CreateMessageEntry(event, entryIndex);
    else if (code[0]=='C' && code[1]=='L' && code[2]==0)  // CL
        entry = new CloneMessageEntry(event, entryIndex);
    else if (code[0]=='D' && code[1]=='M' && code[2]==0)  // DM
        entry = new DeleteMessageEntry(event, entryIndex);
    else
        return NULL;

    entry->parse(tokens, numTokens);
    return entry;
}
