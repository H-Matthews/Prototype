#include "DataHandler.h"

#include <iostream>

std::optional<DataHandler::FunctionCallback> DataHandler::getCallbackForMessage(
    const std::string& type) const
{
    std::optional<FunctionCallback> callback = std::nullopt;

    auto it = mDataHandlerMap.find(type);
    if(it != mDataHandlerMap.end())
    {
        callback = it->second;
    }
    else
    {
        std::cout << "MessageType: " << type << " was NOT registered" << std::endl;
    }

    return callback;
}