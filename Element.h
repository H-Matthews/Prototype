#pragma once

#include <memory>

class Data;
class PictureData;
class VideoData;
class MessageHandler;

class Element
{
    // Required in order to call processMessage
    // from the Handler
    friend class MessageHandler;

    public:
        Element();

        virtual bool processDataMessage(Data* data);

        virtual void registerMessages();

    protected:
        virtual bool processMessage(PictureData* pictureData);
        virtual bool processMessage(VideoData* videoData);

    protected:
        std::unique_ptr<MessageHandler> mMessageHandler;
};