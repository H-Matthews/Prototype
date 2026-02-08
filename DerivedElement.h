#pragma once

#include "Element.h"

class DerivedData;

// This Element Handles DerivedData
class DerivedElement : public Element
{
    friend class MessageHandler;

    public:
        DerivedElement();

        virtual void registerMessages() override;

    private:
        bool processMessage(DerivedData* derivedData);

        // From Element
        bool processMessage(VideoData* videoData) override;
};