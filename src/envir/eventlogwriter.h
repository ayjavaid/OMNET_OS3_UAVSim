//=========================================================================
// EVENTLOGWRITER.H - part of
//                  OMNeT++/OMNEST
//           Discrete System Simulation in C++
//
//  This is a generated file -- do not modify.
//
//=========================================================================

#ifndef __EVENTLOGWRITER_H_
#define __EVENTLOGWRITER_H_

#include <stdio.h>
#include "envirdefs.h"
#include "simtime_t.h"

USING_NAMESPACE

class EventLogWriter
{
  public:
    static void recordLogLine(FILE *f, const char *s, int n);
    static void recordSimulationBeginEntry_v_rid_b(FILE *f, int version, const char * runId, int keyframeBlockSize);
    static void recordSimulationEndEntry_e_c_m(FILE *f, bool isError, int resultCode, const char * message);
    static void recordBubbleEntry_id_txt(FILE *f, int moduleId, const char * text);
    static void recordModuleMethodBeginEntry_sm_tm_m(FILE *f, int fromModuleId, int toModuleId, const char * method);
    static void recordModuleMethodEndEntry(FILE *f);
    static void recordModuleCreatedEntry_id_c_t_n(FILE *f, int moduleId, const char * moduleClassName, const char * nedTypeName, const char * fullName);
    static void recordModuleCreatedEntry_id_c_t_pid_n_cm(FILE *f, int moduleId, const char * moduleClassName, const char * nedTypeName, int parentModuleId, const char * fullName, bool compoundModule);
    static void recordModuleDeletedEntry_id(FILE *f, int moduleId);
    static void recordModuleReparentedEntry_id_p(FILE *f, int moduleId, int newParentModuleId);
    static void recordGateCreatedEntry_m_g_n_o(FILE *f, int moduleId, int gateId, const char * name, bool isOutput);
    static void recordGateCreatedEntry_m_g_n_i_o(FILE *f, int moduleId, int gateId, const char * name, int index, bool isOutput);
    static void recordGateDeletedEntry_m_g(FILE *f, int moduleId, int gateId);
    static void recordConnectionCreatedEntry_sm_sg_dm_dg(FILE *f, int sourceModuleId, int sourceGateId, int destModuleId, int destGateId);
    static void recordConnectionDeletedEntry_sm_sg(FILE *f, int sourceModuleId, int sourceGateId);
    static void recordConnectionDisplayStringChangedEntry_sm_sg_d(FILE *f, int sourceModuleId, int sourceGateId, const char * displayString);
    static void recordModuleDisplayStringChangedEntry_id_d(FILE *f, int moduleId, const char * displayString);
    static void recordEventEntry_e_t_m_ce_msg(FILE *f, eventnumber_t eventNumber, simtime_t simulationTime, int moduleId, eventnumber_t causeEventNumber, long messageId);
    static void recordKeyframeEntry_p_c_s(FILE *f, int64 previousKeyframeFileOffset, const char * consequenceLookaheadLimits, const char * simulationStateEntries);
    static void recordMessageEntry_id_tid_eid_etid_c_n_pe(FILE *f, long messageId, long messageTreeId, long messageEncapsulationId, long messageEncapsulationTreeId, const char * messageClassName, const char * messageName, eventnumber_t previousEventNumber);
    static void recordMessageEntry_id_tid_eid_etid_c_n_k_p_l_er_d_pe(FILE *f, long messageId, long messageTreeId, long messageEncapsulationId, long messageEncapsulationTreeId, const char * messageClassName, const char * messageName, short messageKind, short messagePriority, int64 messageLength, bool hasBitError, const char * detail, eventnumber_t previousEventNumber);
    static void recordCancelEventEntry_id_tid_eid_etid_c_n_pe(FILE *f, long messageId, long messageTreeId, long messageEncapsulationId, long messageEncapsulationTreeId, const char * messageClassName, const char * messageName, eventnumber_t previousEventNumber);
    static void recordCancelEventEntry_id_tid_eid_etid_c_n_k_p_l_er_d_pe(FILE *f, long messageId, long messageTreeId, long messageEncapsulationId, long messageEncapsulationTreeId, const char * messageClassName, const char * messageName, short messageKind, short messagePriority, int64 messageLength, bool hasBitError, const char * detail, eventnumber_t previousEventNumber);
    static void recordBeginSendEntry_id_tid_eid_etid_c_n_pe(FILE *f, long messageId, long messageTreeId, long messageEncapsulationId, long messageEncapsulationTreeId, const char * messageClassName, const char * messageName, eventnumber_t previousEventNumber);
    static void recordBeginSendEntry_id_tid_eid_etid_c_n_k_p_l_er_d_pe(FILE *f, long messageId, long messageTreeId, long messageEncapsulationId, long messageEncapsulationTreeId, const char * messageClassName, const char * messageName, short messageKind, short messagePriority, int64 messageLength, bool hasBitError, const char * detail, eventnumber_t previousEventNumber);
    static void recordEndSendEntry_t(FILE *f, simtime_t arrivalTime);
    static void recordEndSendEntry_t_is(FILE *f, simtime_t arrivalTime, bool isReceptionStart);
    static void recordSendDirectEntry_sm_dm_dg(FILE *f, int senderModuleId, int destModuleId, int destGateId);
    static void recordSendDirectEntry_sm_dm_dg_pd_td(FILE *f, int senderModuleId, int destModuleId, int destGateId, simtime_t propagationDelay, simtime_t transmissionDelay);
    static void recordSendHopEntry_sm_sg(FILE *f, int senderModuleId, int senderGateId);
    static void recordSendHopEntry_sm_sg_pd_td(FILE *f, int senderModuleId, int senderGateId, simtime_t propagationDelay, simtime_t transmissionDelay);
    static void recordCreateMessageEntry_id_tid_eid_etid_c_n_pe(FILE *f, long messageId, long messageTreeId, long messageEncapsulationId, long messageEncapsulationTreeId, const char * messageClassName, const char * messageName, eventnumber_t previousEventNumber);
    static void recordCreateMessageEntry_id_tid_eid_etid_c_n_k_p_l_er_d_pe(FILE *f, long messageId, long messageTreeId, long messageEncapsulationId, long messageEncapsulationTreeId, const char * messageClassName, const char * messageName, short messageKind, short messagePriority, int64 messageLength, bool hasBitError, const char * detail, eventnumber_t previousEventNumber);
    static void recordCloneMessageEntry_id_tid_eid_etid_c_n_pe_cid(FILE *f, long messageId, long messageTreeId, long messageEncapsulationId, long messageEncapsulationTreeId, const char * messageClassName, const char * messageName, eventnumber_t previousEventNumber, long cloneId);
    static void recordCloneMessageEntry_id_tid_eid_etid_c_n_k_p_l_er_d_pe_cid(FILE *f, long messageId, long messageTreeId, long messageEncapsulationId, long messageEncapsulationTreeId, const char * messageClassName, const char * messageName, short messageKind, short messagePriority, int64 messageLength, bool hasBitError, const char * detail, eventnumber_t previousEventNumber, long cloneId);
    static void recordDeleteMessageEntry_id_tid_eid_etid_c_n_pe(FILE *f, long messageId, long messageTreeId, long messageEncapsulationId, long messageEncapsulationTreeId, const char * messageClassName, const char * messageName, eventnumber_t previousEventNumber);
    static void recordDeleteMessageEntry_id_tid_eid_etid_c_n_k_p_l_er_d_pe(FILE *f, long messageId, long messageTreeId, long messageEncapsulationId, long messageEncapsulationTreeId, const char * messageClassName, const char * messageName, short messageKind, short messagePriority, int64 messageLength, bool hasBitError, const char * detail, eventnumber_t previousEventNumber);
};

#endif
