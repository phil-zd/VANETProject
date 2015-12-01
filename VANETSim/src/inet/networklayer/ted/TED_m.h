//
// Generated file, do not edit! Created by nedtool 4.6 from networklayer/ted/TED.msg.
//

#ifndef _TED_M_H_
#define _TED_M_H_

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0406
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



// cplusplus {{
#include "IPv4Address.h"

#define LINK_STATE_MESSAGE      1

typedef std::vector<struct TELinkStateInfo> TELinkStateInfoVector;
// }}

/**
 * Struct generated from networklayer/ted/TED.msg:31 by nedtool.
 */
struct TELinkStateInfo
{
    TELinkStateInfo();
    IPv4Address advrouter;
    IPv4Address linkid;
    IPv4Address local;
    IPv4Address remote;
    double metric;
    double MaxBandwidth;
    double UnResvBandwidth[8];
    simtime_t timestamp;
    unsigned int sourceId;
    unsigned int messageId;
    bool state;
};

void doPacking(cCommBuffer *b, TELinkStateInfo& a);
void doUnpacking(cCommBuffer *b, TELinkStateInfo& a);

/**
 * Class generated from <tt>networklayer/ted/TED.msg:53</tt> by nedtool.
 * <pre>
 * //
 * // Data structure supplied with NF_TED_CHANGE ~NotificationBoard notifications.
 * // This triggers the link state protocol to send out up-to-date link state info
 * // about the given links.
 * //
 * class TEDChangeInfo
 * {
 *     int tedLinkIndices[];
 * }
 * </pre>
 */
class TEDChangeInfo : public ::cObject
{
  protected:
    int *tedLinkIndices_var; // array ptr
    unsigned int tedLinkIndices_arraysize;

  private:
    void copy(const TEDChangeInfo& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const TEDChangeInfo&);

  public:
    TEDChangeInfo();
    TEDChangeInfo(const TEDChangeInfo& other);
    virtual ~TEDChangeInfo();
    TEDChangeInfo& operator=(const TEDChangeInfo& other);
    virtual TEDChangeInfo *dup() const {return new TEDChangeInfo(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual void setTedLinkIndicesArraySize(unsigned int size);
    virtual unsigned int getTedLinkIndicesArraySize() const;
    virtual int getTedLinkIndices(unsigned int k) const;
    virtual void setTedLinkIndices(unsigned int k, int tedLinkIndices);
};

inline void doPacking(cCommBuffer *b, TEDChangeInfo& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, TEDChangeInfo& obj) {obj.parsimUnpack(b);}


#endif // ifndef _TED_M_H_
