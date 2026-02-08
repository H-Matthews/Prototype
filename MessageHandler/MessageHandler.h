#pragma once

#include "Element.h"

#include <string>
#include <functional>
#include <unordered_map>
#include <optional>

// Forward Declarations
class Data;

class MessageHandler
{

public:
    using MessageCallback = std::function<bool(Data* data)>;
    using MessageHandlerMap = std::unordered_map<std::string, MessageCallback>;

    template<typename D, typename E>
    void registerMessage(E* element);

    std::optional<MessageCallback> 
        getCallbackForMessage(const std::string& type) const;

private:
    MessageHandlerMap mMessageMap;
};

// D = TypedData; E = TypedElement
template<typename D, typename E>
void MessageHandler::registerMessage(E* element)
{
    auto messageMapIt = mMessageMap.find(D::TYPE_NAME);
    if(messageMapIt == mMessageMap.end())
    {
        MessageCallback callback = [element](Data* data)->bool{
            D* typedData = static_cast<D*>(data);

            return element->processMessage(typedData);
        };

        mMessageMap[D::TYPE_NAME] = callback;
    }
}