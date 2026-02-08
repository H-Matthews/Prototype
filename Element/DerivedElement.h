#pragma once

#include "Element.h"

class DerivedData;

// This Element Handles DerivedData
class DerivedElement : public Element
{
    friend class DataHandler;

    public:
        DerivedElement();

        virtual void registerData() override;

    private:
        bool processData(DerivedData* derivedData);

        // From Element
        bool processData(VideoData* videoData) override;
};