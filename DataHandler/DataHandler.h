#pragma once

#include "Element.h"

#include <string>
#include <functional>
#include <unordered_map>
#include <optional>

// Forward Declarations
class Data;

class DataHandler
{

public:
    using FunctionCallback = std::function<bool(Data* data)>;
    using DataHandlerMap = std::unordered_map<std::string, FunctionCallback>;

    template<typename D, typename E>
    void registerData(E* element);

    std::optional<FunctionCallback> 
        getCallbackForMessage(const std::string& type) const;

private:
    DataHandlerMap mDataHandlerMap;
};

// D = TypedData; E = TypedElement
template<typename D, typename E>
void DataHandler::registerData(E* element)
{
    auto messageMapIt = mDataHandlerMap.find(D::TYPE_NAME);
    if(messageMapIt == mDataHandlerMap.end())
    {
        FunctionCallback callback = [element](Data* data)->bool {
            return element->processData(static_cast<D*>(data));
        };

        mDataHandlerMap[D::TYPE_NAME] = callback;
    }
}