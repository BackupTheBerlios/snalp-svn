#ifndef GUARD_SNALPDIALOGS_H_INCLUDED
#define GUARD_SNALPDIALOGS_H_INCLUDED 1

#include "FowardDeclarations.h"

class SnalpAddLanguageDialog;
class SnalpAddCategoryDialog;

class SnalpDialogs
{
public:
    SnalpDialogs( GladeRef gladeref , boost::shared_ptr<SnalpSignals> signals );
    ~SnalpDialogs();
    boost::shared_ptr<SnalpAddLanguageDialog> AddLanguageDialog;
    boost::shared_ptr<SnalpAddCategoryDialog> AddCategoryDialog;
};

#endif // GUARD_SNALPDIALOGS_H_INCLUDED
