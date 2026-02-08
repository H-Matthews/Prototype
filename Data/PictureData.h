#pragma once

#include "Data.h"

#include <string>
#include <sstream>

class PictureData : public Data
{
public:
    static const std::string TYPE_NAME;

    PictureData() :
        Data(TYPE_NAME),
        mPhoto('a')
    {}

    std::string toString() override
    {
        std::ostringstream oss;
        oss << "PictureData: " << mPhoto;

        return oss.str();
    }

    char getPictureData() { return mPhoto; }

public:
    char mPhoto;
};