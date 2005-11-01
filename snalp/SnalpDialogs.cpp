#include "SnalpDialogs.h"
#include "SnalpAddLanguageDialog.h"
#include "SnalpAddCategoryDialog.h"
#include <libglademm.h>

SnalpDialogs::SnalpDialogs( GladeRef gladeref , boost::shared_ptr<SnalpSignals> signals )
: AddLanguageDialog(new SnalpAddLanguageDialog(gladeref,signals)),
  AddCategoryDialog(new SnalpAddCategoryDialog(gladeref,signals))
{
}
SnalpDialogs::~SnalpDialogs()
{
}
