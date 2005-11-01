#include "SnalpAddLanguageDialog.h"

#include <libglademm.h>
#include <gtkmm/dialog.h>
#include <gtkmm/entry.h>

#include "SnalpException.h"
#include "SnalpSignals.h"

SnalpAddLanguageDialog::SnalpAddLanguageDialog( GladeRef gladeref , boost::shared_ptr<SnalpSignals> _signals )
: dialog(0),entry(0),signals(_signals)
{
    try
    {
        Gtk::Button * button = 0;
        gladeref->get_widget<Gtk::Dialog>("AddLanguageDialog",dialog);
        gladeref->get_widget<Gtk::Entry>("LanguageDialogEntry",entry);
        gladeref->get_widget<Gtk::Button>("AddLanguageDialogOkButton",button);
        button->signal_clicked().connect(sigc::mem_fun(*this,&SnalpAddLanguageDialog::OnAccept));        
        gladeref->get_widget<Gtk::Button>("AddLanguageDialogCancelButton",button);
        button->signal_clicked().connect(sigc::mem_fun(*dialog,&Gtk::Dialog::hide));        
        
    }
    catch( Gnome::Glade::XmlError const & xml_error )
    {
        THROW_SNALP_EXCEPTION(SnalpFatalException,xml_error.what());
    }
    catch( std::exception const & e )
    {
        THROW_SNALP_EXCEPTION(SnalpFatalException,e.what());
    }
    catch( Glib::Exception const & e )
    {
        THROW_SNALP_EXCEPTION(SnalpFatalException,e.what());
    }
    catch( ... )
    {
        THROW_SNALP_EXCEPTION(SnalpFatalException, "Unknown exception caught" );
    }
}

SnalpAddLanguageDialog::~SnalpAddLanguageDialog()
{
}

void SnalpAddLanguageDialog::Run()
{
    Clear();
    dialog->show_all();
}

void SnalpAddLanguageDialog::Clear()
{
    entry->set_text("");
}

void SnalpAddLanguageDialog::OnAccept()
{
    signals->AddLanguageSlot(Glib::locale_from_utf8(entry->get_text()));
    Clear();
    dialog->hide();
}