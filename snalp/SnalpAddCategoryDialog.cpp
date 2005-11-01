#include "SnalpAddCategoryDialog.h"

#include <libglademm.h>
#include <gtkmm/dialog.h>
#include <gtkmm/entry.h>

#include "SnalpException.h"
#include "SnalpSignals.h"

SnalpAddCategoryDialog::SnalpAddCategoryDialog( GladeRef gladeref , boost::shared_ptr<SnalpSignals> _signals )
: dialog(0),entry(0),signals(_signals)
{
    try
    {
        Gtk::Button * button = 0;
        gladeref->get_widget<Gtk::Dialog>("AddCategoryDialog",dialog);
        gladeref->get_widget<Gtk::Entry>("AddCategoryDialogEntry",entry);
        gladeref->get_widget<Gtk::Button>("AddCategoryDialogOkButton",button);
        button->signal_clicked().connect(sigc::mem_fun(*this,&SnalpAddCategoryDialog::OnAccept));        
        gladeref->get_widget<Gtk::Button>("AddCategoryDialogCancelButton",button);
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

SnalpAddCategoryDialog::~SnalpAddCategoryDialog()
{
}

void SnalpAddCategoryDialog::Run()
{
    Clear();
    dialog->show_all();
}

void SnalpAddCategoryDialog::Clear()
{
    entry->set_text("");
}

void SnalpAddCategoryDialog::OnAccept()
{
    signals->AddCategorySlot(Glib::locale_from_utf8(entry->get_text()));
    Clear();
    dialog->hide();
}