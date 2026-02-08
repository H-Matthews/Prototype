#include "MessageHandler.h"

#include <iostream>

std::optional<MessageHandler::MessageCallback> MessageHandler::getCallbackForMessage(
    const std::string& type) const
{
    std::optional<MessageCallback> callback = std::nullopt;

    auto it = mMessageMap.find(type);
    if(it != mMessageMap.end())
    {
        callback = it->second;
    }
    else
    {
        std::cout << "MessageType: " << type << " was NOT registered" << std::endl;
    }

    return callback;
}