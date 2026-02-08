#include "DerivedElement.h"

#include "DerivedData.h"
#include "VideoData.h"
#include "DataHandler.h"

#include <iostream>

DerivedElement::DerivedElement() :
    Element()
{
}

void DerivedElement::registerData()
{
    mDataHandler->registerData<DerivedData, DerivedElement>(this);

    Element::registerData();
}

bool DerivedElement::processData(DerivedData* derivedData)
{
    bool processed = false;
    if(derivedData)
    {
        processed = true;
        std::cout << "Handled Message: " << derivedData->getType() << std::endl;
    }

    return processed;
}

bool DerivedElement::processData(VideoData* videoData)
{
    if(videoData)
    {
        std::cout << "Handling Message: " << videoData->getType() 
            << " in DerivedElement" << std::endl;
    }

    return Element::processData(videoData);
}