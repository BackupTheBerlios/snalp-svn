#ifndef GUARD_SNALPADDCATEGORYDIALOG_H_INCLUDED
#define GUARD_SNALPADDCATEGORYDIALOG_H_INCLUDED 1

#include "FowardDeclarations.h"

class SnalpAddCategoryDialog
{
public:
    SnalpAddCategoryDialog( GladeRef gladeref , boost::shared_ptr<SnalpSignals> _signals );
    ~SnalpAddCategoryDialog();
    void Run(); 
private:
    void Clear();
    void OnAccept();
    Gtk::Dialog * dialog;
    Gtk::Entry  * entry;    
    boost::shared_ptr<SnalpSignals> signals;
};

#endif //GUARD_SNALPADDCATEGORYDIALOG_H_INCLUDED
