#include "MessageHandler.h"
#include "DerivedElement.h"
#include "PictureData.h"
#include "VideoData.h"
#include "DerivedData.h"

#include <iostream>
#include <vector>

int main()
{
    auto derivedElement = std::make_unique<DerivedElement>();
    derivedElement->registerMessages();

    auto derivedData = std::make_unique<DerivedData>();
    auto pictureData = std::make_unique<PictureData>();
    auto videoData = std::make_unique<VideoData>();

    std::vector<Data*> dataVec;
    dataVec.push_back(derivedData.get());
    dataVec.push_back(pictureData.get());
    dataVec.push_back(videoData.get());

    bool isMessageProcessed = false;
    for(auto data : dataVec)
    {
        isMessageProcessed = derivedElement->processDataMessage(data);
        std::cout << "Message Processed: " << std::boolalpha << isMessageProcessed << std::endl;
    }


    return 0;
}