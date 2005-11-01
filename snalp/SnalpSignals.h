#ifndef GUARD_SNALPSIGNALS_H_INCLUDED
#define GUARD_SNALPSIGNALS_H_INCLUDED 1

#include <string>
#include <sigc++/slot.h>
#include "types.h"

struct SnalpSignals
{
    sigc::slot< void , std::string const & > AddLanguageSlot;
    sigc::slot< void , std::string const & > AddCategorySlot;
};

#endif //GUARD_SNALPSIGNALS_H_INCLUDED
