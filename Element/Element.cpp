#include "Element.h"

#include "DataHandler.h"
#include "VideoData.h"
#include "PictureData.h"

#include <optional>
#include <functional>
#include <string>
#include <iostream>

Element::Element() :
    mDataHandler(std::make_unique<DataHandler>())
{
}

void Element::registerData()
{
    // Register Messages
    mDataHandler->registerData<PictureData, Element>(this);
    mDataHandler->registerData<VideoData, Element>(this);
}

bool Element::processIncomingData(Data* data)
{
    const std::string& dataType = data->getType();

    std::optional<DataHandler::FunctionCallback> functionCallback =
        mDataHandler->getCallbackForMessage(dataType);

    if(functionCallback.has_value())
    {
        return functionCallback.value()(data);
    }
    else
    {
        std::cout << "Dropping Data: " << dataType << std::endl;
    }

    return false;
}

bool Element::processData(PictureData* pictureData)
{
    bool processed = false;
    if(pictureData)
    {
        processed = true;
        std::cout << "Handled Data: " << pictureData->getType() << std::endl;
    }

    return processed;
}

bool Element::processData(VideoData* videoData)
{
    bool processed = false;
    if(videoData)
    {
        processed = true;
        std::cout << "Handled Data: " << videoData->getType() << std::endl;
    }

    return processed;
}

