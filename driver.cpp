#include "DataHandler.h"
#include "DerivedElement.h"
#include "PictureData.h"
#include "VideoData.h"
#include "DerivedData.h"

#include <iostream>
#include <vector>

int main()
{
    auto derivedElement = std::make_unique<DerivedElement>();
    derivedElement->registerData();

    auto derivedData = std::make_unique<DerivedData>();
    auto pictureData = std::make_unique<PictureData>();
    auto videoData = std::make_unique<VideoData>();

    std::vector<Data*> dataVec;
    dataVec.push_back(derivedData.get());
    dataVec.push_back(pictureData.get());
    dataVec.push_back(videoData.get());

    bool isDataProcessed = false;
    for(auto data : dataVec)
    {
        isDataProcessed = derivedElement->processIncomingData(data);
        std::cout << "Message Processed: " << std::boolalpha << isDataProcessed << std::endl;
    }


    return 0;
}