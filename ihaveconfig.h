#ifndef IHAVECONFIG_H
#define IHAVECONFIG_H

#include "config.h"

class IHaveConfig
{
public:
    IHaveConfig(const Config &config);

protected:
    const Config _config;
};

#endif // IHAVECONFIG_H
