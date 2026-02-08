#pragma once

#include <string>

class Data
{
public:

    Data(const std::string& type) :
        mType(type)
    {}

    virtual ~Data() {}

    const std::string& getType() { return mType; }

    virtual std::string toString() = 0;

private:
    std::string mType;
};