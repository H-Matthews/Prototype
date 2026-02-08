#pragma once

#include "Data.h"

#include <string>
#include <sstream>

class DerivedData : public Data
{
public:
    static const std::string TYPE_NAME;

    DerivedData() :
        Data(TYPE_NAME),
        derivedData(100.5)
    {}

    std::string toString() override
    {
        std::ostringstream oss;
        oss << "DerivedData: " << derivedData;

        return oss.str();
    }

    double getDerivedData() { return derivedData; }

public:
    double derivedData;
};