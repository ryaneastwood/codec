/*
 * Copyright 2014-2018 Neueda Ltd.
 * 
 * Generated 24/04/2019
 */
#ifndef EUREX_SRQSQUOTERESPONSE_PACKET_H
#define EUREX_SRQSQUOTERESPONSE_PACKET_H

#include <string>
#include <vector>
#include <sstream>
#include <cstddef>
#include <stdint.h>
#include "eurexPackets.h"
#include "eurexPacketUtils.h"

namespace neueda
{

using namespace std;

class eurexSRQSQuoteResponsePacket
{
    public:
        // no value constants
        static const uint64_t QUOTE_ID_MIN;
        static const uint64_t QUOTE_ID_MAX;
        static const uint64_t QUOTE_ID_NO_VALUE;
        static const uint32_t NEGOTIATION_ID_MIN;
        static const uint32_t NEGOTIATION_ID_MAX;
        static const uint32_t NEGOTIATION_ID_NO_VALUE;
        static const char QUOTE_REQ_ID_NO_VALUE[20];
        static const size_t QUOTE_REQ_ID_MAX_LENGTH;

        // fields (use with care)
        eurexMessageHeaderOutCompPacket mMessageHeaderOut;
        eurexResponseHeaderCompPacket mResponseHeader;
        uint64_t mQuoteID;
        uint32_t mNegotiationID;
        char mQuoteReqID[20];

        // constructor
        eurexSRQSQuoteResponsePacket ()
        {
            mMessageHeaderOut.mTemplateID = 10703;
            mQuoteID = QUOTE_ID_NO_VALUE;
            mNegotiationID = NEGOTIATION_ID_NO_VALUE;
            memcpy(mQuoteReqID, QUOTE_REQ_ID_NO_VALUE, sizeof (mQuoteReqID));
        }

        // getters & setters
        const eurexMessageHeaderOutCompPacket& getMessageHeaderOut () const
        {
            return mMessageHeaderOut;
        }

        bool setMessageHeaderOut (const eurexMessageHeaderOutCompPacket& v)
        {
            mMessageHeaderOut = v;
            return true;
        }

        const eurexResponseHeaderCompPacket& getResponseHeader () const
        {
            return mResponseHeader;
        }

        bool setResponseHeader (const eurexResponseHeaderCompPacket& v)
        {
            mResponseHeader = v;
            return true;
        }

        uint64_t getQuoteID () const
        {
            return mQuoteID;
        }

        bool setQuoteID (uint64_t v)
        {
            mQuoteID = v;
            return ((QUOTE_ID_MIN <= mQuoteID && mQuoteID <= QUOTE_ID_MAX) || mQuoteID == QUOTE_ID_NO_VALUE);
        }

        bool isQuoteIDValid () const
        {
            return (mQuoteID != QUOTE_ID_NO_VALUE);
        }

        void resetQuoteID ()
        {
            mQuoteID = QUOTE_ID_NO_VALUE;
        }

        uint32_t getNegotiationID () const
        {
            return mNegotiationID;
        }

        bool setNegotiationID (uint32_t v)
        {
            mNegotiationID = v;
            return ((NEGOTIATION_ID_MIN <= mNegotiationID && mNegotiationID <= NEGOTIATION_ID_MAX) || mNegotiationID == NEGOTIATION_ID_NO_VALUE);
        }

        bool isNegotiationIDValid () const
        {
            return (mNegotiationID != NEGOTIATION_ID_NO_VALUE);
        }

        void resetNegotiationID ()
        {
            mNegotiationID = NEGOTIATION_ID_NO_VALUE;
        }

        string getQuoteReqID () const
        {
            return string (mQuoteReqID, QUOTE_REQ_ID_MAX_LENGTH);
        }

        bool setQuoteReqID (const string& v)
        {
            memset (mQuoteReqID, '\0', sizeof (mQuoteReqID));
            size_t size = min ((size_t) v.size (), (size_t) QUOTE_REQ_ID_MAX_LENGTH);
            strncpy (mQuoteReqID, v.c_str (), size);
            return (v.size () <= QUOTE_REQ_ID_MAX_LENGTH);
        }

        bool isQuoteReqIDValid () const
        {
            return (memcmp (mQuoteReqID, QUOTE_REQ_ID_NO_VALUE, sizeof (mQuoteReqID)) != 0);
        }

        void resetQuoteReqID ()
        {
            memcpy (mQuoteReqID, QUOTE_REQ_ID_NO_VALUE, sizeof (mQuoteReqID));
        }


        // render current raw size
        size_t getRawSize () const
        {
            size_t result = mMessageHeaderOut.getRawSize()
                + mResponseHeader.getRawSize()
                + sizeof (mQuoteID)
                + sizeof (mNegotiationID)
                + sizeof (mQuoteReqID);
            return result;
        }

        // serialization
        codecState serialize (void *buf, size_t len, size_t &used)
        {
            mMessageHeaderOut.mBodyLen = getRawSize ();
            codecState state;
            state = mMessageHeaderOut.serialize (buf, len, used);
            if (state != GW_CODEC_SUCCESS) return state;
            state = mResponseHeader.serialize (buf, len, used);
            if (state != GW_CODEC_SUCCESS) return state;
            state = eurex::serialize (mQuoteID, buf, len, used);
            if (state != GW_CODEC_SUCCESS) return state;
            state = eurex::serialize (mNegotiationID, buf, len, used);
            if (state != GW_CODEC_SUCCESS) return state;
            state = eurex::serialize (mQuoteReqID, buf, len, used);
            if (state != GW_CODEC_SUCCESS) return state;
            return GW_CODEC_SUCCESS;
        }

        // deserialization
        codecState deserialize (const void *buf, size_t len, size_t &used)
        {
            codecState state;
            state = mMessageHeaderOut.deserialize (buf, len, used);
            if (state != GW_CODEC_SUCCESS) return state;
            state = mResponseHeader.deserialize (buf, len, used);
            if (state != GW_CODEC_SUCCESS) return state;
            state = eurex::deserialize (mQuoteID, buf, len, used);
            if (state != GW_CODEC_SUCCESS) return state;
            state = eurex::deserialize (mNegotiationID, buf, len, used);
            if (state != GW_CODEC_SUCCESS) return state;
            state = eurex::deserialize (mQuoteReqID, buf, len, used);
            if (state != GW_CODEC_SUCCESS) return state;
            mMessageHeaderOut.mBodyLen = getRawSize ();
            return GW_CODEC_SUCCESS;
        }

        // string conversion
        string toString () const
        {
            stringstream sss;
            sss << "SRQSQuoteResponse::"
                << "[MessageHeaderOut=" << mMessageHeaderOut.toString () << "],"
                << "[ResponseHeader=" << mResponseHeader.toString () << "],"
                << "[QuoteID=" << getQuoteID () << "],"
                << "[NegotiationID=" << getNegotiationID () << "],"
                << "[QuoteReqID=" << getQuoteReqID () << "]";
            return sss.str();
        }
};

const uint64_t eurexSRQSQuoteResponsePacket::QUOTE_ID_MIN = 0UL;
const uint64_t eurexSRQSQuoteResponsePacket::QUOTE_ID_MAX = 18446744073709551614UL;
const uint64_t eurexSRQSQuoteResponsePacket::QUOTE_ID_NO_VALUE = 0xFFFFFFFFFFFFFFFF;
const uint32_t eurexSRQSQuoteResponsePacket::NEGOTIATION_ID_MIN = 0;
const uint32_t eurexSRQSQuoteResponsePacket::NEGOTIATION_ID_MAX = 4294967294;
const uint32_t eurexSRQSQuoteResponsePacket::NEGOTIATION_ID_NO_VALUE = 0xFFFFFFFF;
const char eurexSRQSQuoteResponsePacket::QUOTE_REQ_ID_NO_VALUE[20] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
const size_t eurexSRQSQuoteResponsePacket::QUOTE_REQ_ID_MAX_LENGTH = 20;


} // namespace neueda

#endif // EUREX_SRQSQUOTERESPONSE_PACKET_H
