#pragma once

#include <memory>

class Data;
class PictureData;
class VideoData;
class DataHandler;

class Element
{
    // Required in order to call processMessage
    // from the Handler
    friend class DataHandler;

    public:
        Element();

        virtual ~Element() {}

        virtual bool processIncomingData(Data* data);

        virtual void registerData();

    protected:
        virtual bool processData(PictureData* pictureData);
        virtual bool processData(VideoData* videoData);

    protected:
        std::unique_ptr<DataHandler> mDataHandler;
};