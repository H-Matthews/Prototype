#include "DerivedElement.h"

#include "DerivedData.h"
#include "VideoData.h"
#include "MessageHandler.h"

#include <iostream>

DerivedElement::DerivedElement() :
    Element()
{
}

void DerivedElement::registerMessages()
{
    mMessageHandler->registerMessage<DerivedData, DerivedElement>(this);

    Element::registerMessages();
}

bool DerivedElement::processMessage(DerivedData* derivedData)
{
    bool processed = false;
    if(derivedData)
    {
        processed = true;
        std::cout << "Handled Message: " << derivedData->getType() << std::endl;
    }

    return processed;
}

bool DerivedElement::processMessage(VideoData* videoData)
{
    if(videoData)
    {
        std::cout << "Handling Message: " << videoData->getType() 
            << " in DerivedElement" << std::endl;
    }

    return Element::processMessage(videoData);
}