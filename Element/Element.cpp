#include "Element.h"

#include "MessageHandler.h"
#include "VideoData.h"
#include "PictureData.h"

#include <optional>
#include <functional>
#include <string>
#include <iostream>

Element::Element() :
    mMessageHandler(std::make_unique<MessageHandler>())
{
    registerMessages();
}

void Element::registerMessages()
{
    // Register Messages
    mMessageHandler->registerMessage<PictureData, Element>(this);
    mMessageHandler->registerMessage<VideoData, Element>(this);
}

bool Element::processDataMessage(Data* data)
{
    const std::string& dataType = data->getType();

    std::optional<MessageHandler::MessageCallback> messageCallback =
        mMessageHandler->getCallbackForMessage(dataType);

    if(messageCallback.has_value())
    {
        return messageCallback.value()(data);
    }

    return false;
}

bool Element::processMessage(PictureData* pictureData)
{
    bool processed = false;
    if(pictureData)
    {
        processed = true;
        std::cout << "Handled Message: " << pictureData->getType() << std::endl;
    }

    return processed;
}

bool Element::processMessage(VideoData* videoData)
{
    bool processed = false;
    if(videoData)
    {
        processed = true;
        std::cout << "Handled Message: " << videoData->getType() << std::endl;
    }

    return processed;
}

