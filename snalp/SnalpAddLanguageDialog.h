#ifndef GUARD_SNALPADDLANGUAGEDIALOG_H_INCLUDED
#define GUARD_SNALPADDLANGUAGEDIALOG_H_INCLUDED 1

#include "FowardDeclarations.h"

class SnalpAddLanguageDialog
{
public:
    SnalpAddLanguageDialog( GladeRef gladeref , boost::shared_ptr<SnalpSignals> _signals );
    ~SnalpAddLanguageDialog();
    void Run(); 
private:
    void Clear();
    void OnAccept();
    Gtk::Dialog * dialog;
    Gtk::Entry  * entry;    
    boost::shared_ptr<SnalpSignals> signals;
};

#endif //  GUARD_SNALPADDLANGUAGEDIALOG_H_INCLUDED
