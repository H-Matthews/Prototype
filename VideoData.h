#pragma once

#include "Data.h"

#include <string>
#include <sstream>

class VideoData : public Data
{
public:
    static const std::string TYPE_NAME;

    VideoData() :
        Data(TYPE_NAME),
        mVideoData(50.0)
    {}

    std::string toString() override
    { 
        std::ostringstream oss;
        oss << "VideoData: " << mVideoData;

        return oss.str();
    }

    double getVideoData() { return mVideoData; }

private:
    double mVideoData;
};